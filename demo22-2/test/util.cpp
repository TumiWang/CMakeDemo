// 文件 test/util.cpp

#include "util.h"

#include <filesystem>

extern const char* info_module_name_;

std::string GetInfoFullPath(const char* processname) {
    std::filesystem::path filename(processname);
    filename = std::filesystem::absolute(filename);
    filename = filename.parent_path();
    filename.append(info_module_name_);
    return filename.string();
}