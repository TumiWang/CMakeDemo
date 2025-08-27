#include "insert_all.h"

InsertAll::InsertAll(TarFile& tar_file, const std::string& dir_prefix, const std::string& dir)
    : DirDetect(dir_prefix + dir), dir_prefix_(dir_prefix), tar_file_(tar_file) {
    if (dir.empty() || dir[dir.size() - 1] == '/') {
        cur_dir_ = dir;
    } else {
        cur_dir_ = dir;
        cur_dir_ += "/";
    }
    tar_file_.AddDir(dir);
}

void InsertAll::OnDetectDir(const std::string& dir) {
    tar_file_.AddDir(cur_dir_ + dir);

    InsertAll insert(tar_file_, dir_prefix_, cur_dir_ + dir);
    insert.Detect();
}

void InsertAll::OnDetectLink(const std::string& link) {
    tar_file_.AddLink(cur_dir_ + link);
}

void InsertAll::OnDetectFile(const std::string& file) {
    tar_file_.AddFile(cur_dir_ + file);
}