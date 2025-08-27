#include "lib_detect.h"

#include "info.h"
#include "insert_all.h"

#include <vector>

LibDetect::LibDetect(TarFile& tar_file, const std::string& dir_prefix, const std::string& dir)
    : DirDetect(dir_prefix + dir), dir_prefix_(dir_prefix), tar_file_(tar_file) {
    if (dir.empty() || dir[dir.size() - 1] == '/') {
        cur_dir_ = dir;
    } else {
        cur_dir_ = dir;
        cur_dir_ += "/";
    }
    tar_file_.AddDir(dir);
}

void LibDetect::OnDetectDir(const std::string& dir) {
    static const std::vector<std::string> lists = {
        "cmake",
        "gcc",
        "pkgconfig"
    };
    bool need_insert = false;
    for (const auto& item: lists) {
        if (dir == item) {
            need_insert = true;
            break;
        }
    }
    if (!need_insert) {
        auto pos = dir.find(GetArch());
        if (pos == 0) need_insert = true;
    }
    if (need_insert) {
        tar_file_.AddDir(cur_dir_ + dir);

        InsertAll insert(tar_file_, dir_prefix_, cur_dir_ + dir);
        insert.Detect();
    }
}

void LibDetect::OnDetectLink(const std::string& link) {
    tar_file_.AddLink(cur_dir_ + link);
}

void LibDetect::OnDetectFile(const std::string& file) {
    tar_file_.AddFile(cur_dir_ + file);
}