#include "tar_file.h"

#include <archive_entry.h>

#include <fcntl.h>

#include <list>
#include <sstream>
#include <iostream>

namespace {
    std::list<std::string> SplitFullPath(const std::string& fullpath) {
        std::list<std::string> result;

        auto pos = fullpath.find('\'');
        if (pos != std::string::npos) {
            return result;
        }
        pos = fullpath.find('\"');
        if (pos != std::string::npos) {
            return result;
        }
        auto begin_itor = fullpath.cbegin();
        auto cur_itor = begin_itor;
        while (cur_itor != fullpath.cend()) {
            if (*cur_itor == '/') {
                std::string temp(begin_itor, cur_itor);
                begin_itor = ++cur_itor;

                if (!temp.empty()) result.push_back(temp);
            } else {
                ++cur_itor;
            }
        }

        if (cur_itor == fullpath.cend() && begin_itor != cur_itor) {
            std::string temp(begin_itor, cur_itor);
            if (!temp.empty()) result.push_back(temp);
        }

        return result;
    }

    bool CalcRelativeName(const std::string& link, std::string& filename) {
        do {
            std::list<std::string> src = SplitFullPath(link);
            if (src.empty()) break;

            std::list<std::string> dest = SplitFullPath(filename);
            if (dest.empty()) break;

            auto src_iter = src.begin();
            auto dest_iter = dest.begin();

            while(src_iter != src.end() && dest_iter != dest.end()) {
                if (*src_iter == *dest_iter) {
                    src_iter = src.erase(src_iter);
                    dest_iter = dest.erase(dest_iter);
                } else {
                    break;
                }
            }

            if (src.empty()) break;
            if (dest.empty()) break;

            std::ostringstream os;

            os << "..";
            for (int i = 1; i < src.size() - 1; ++i) 
                os << "/..";

            for (auto iter = dest.begin(); iter != dest.end(); ++iter)
                os << "/" << *iter;

            filename = os.str();

            return true;
        } while(false);

        return false;
    }
}

TarFile::TarFile(const std::string& filename, const std::string& path_prefix)
    : path_prefix_(path_prefix) {
    tarfile_ = archive_write_new();
    archive_write_set_format_pax_restricted(tarfile_);
    // archive_write_set_compression_none(tarfile_);
    archive_write_add_filter_none(tarfile_);
    archive_write_set_format_ustar(tarfile_);

    archive_write_open_filename(tarfile_, filename.c_str());
}

TarFile::~TarFile() {
    archive_write_free(tarfile_);
}

void TarFile::AddDir(const std::string& dir) {
    std::string filename = path_prefix_ + dir;
    
    auto iter = dir_cache_.find(dir);
    if (iter != dir_cache_.end()) return;
    dir_cache_.insert(dir);

    struct stat st;
    stat(filename.c_str(), &st);
    struct archive_entry* entry = archive_entry_new();
    archive_entry_copy_stat(entry, &st);
    archive_entry_set_pathname(entry, dir.c_str());
    archive_entry_set_filetype(entry, AE_IFDIR);
    archive_entry_set_perm(entry, 0755);
    archive_entry_set_size(entry, 0);
    int ret = archive_write_header(tarfile_, entry);
    // if (ret != ARCHIVE_OK) {
    //     std::cout << "archive_write_header Failed: " << filename << std::endl;
    //     exit(1);
    // }
    archive_write_finish_entry(tarfile_);
    archive_entry_free(entry);
}

void TarFile::AddFile(const std::string& filename) {
    std::string fullname = path_prefix_ + filename;

    struct stat st;
    stat(fullname.c_str(), &st);
    struct archive_entry* entry = archive_entry_new();
    archive_entry_copy_stat(entry, &st);
    archive_entry_set_pathname(entry, filename.c_str());
    int ret = archive_write_header(tarfile_, entry);
    // if (ret != ARCHIVE_OK) {
    //     std::cout << "archive_write_header Failed: " << filename << std::endl;
    //     exit(1);
    // }
    int fd = open(fullname.c_str(), O_RDONLY);
    // if (fd < 0) {
    //     std::cout << "open Failed: " << filename << std::endl;
    //     exit(1);
    // }
    char buff[10240];
    size_t bytes;
    while((bytes = read(fd, buff, sizeof(buff))) > 0 ) {
        ret = archive_write_data(tarfile_, buff, bytes);
        // if (ret != bytes) {
        //     std::cout << "archive_entry_data Failed: " << " --- " << filename << std::endl;
        //     exit(1);
        // }
    }
    close(fd);
    archive_write_finish_entry(tarfile_);
    archive_entry_free(entry);
}

void TarFile::AddLink(const std::string& link) {
    std::string filename = path_prefix_ + link;

    struct stat st;
    stat(filename.c_str(), &st);
    char buff[1024] = { 0 };
    ssize_t bytes = readlink(filename.c_str(), buff, sizeof(buff));
    if (bytes <= 1) return;
    std::string text = buff;
    if (text[0] == '/') {
        if (!CalcRelativeName(filename, text)) return;
    }

    struct archive_entry* entry = archive_entry_new();
    archive_entry_copy_stat(entry, &st);
    archive_entry_set_pathname(entry, link.c_str());
    archive_entry_set_mode(entry, S_IFLNK | 0777);

    archive_entry_set_symlink(entry, text.c_str());
    archive_write_disk_set_options(tarfile_, 0);
    archive_write_header(tarfile_, entry);
    archive_write_finish_entry(tarfile_);
    archive_entry_free(entry);
}