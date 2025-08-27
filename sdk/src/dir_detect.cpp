#include "dir_detect.h"

#include <dirent.h>

DirDetect::DirDetect(const std::string& dir) : dir_(dir) {
    if (dir_ == "/") full_path_ = "/";
    else full_path_ = dir_ + "/";
}

DirDetect::~DirDetect() {
    
}

void DirDetect::Detect() {
    DIR* root = opendir(dir_.c_str());
    if (root) {
        struct dirent* entry = nullptr;
        while(entry = readdir(root)) {
            if (entry->d_type == DT_LNK) {
                std::string name = entry->d_name;
                OnDetectLink(name);
            } else if (entry->d_type == DT_DIR) {
                std::string name = entry->d_name;
                if (name != "." && name != "..") {
                    OnDetectDir(name);
                }
            } else if (entry->d_type == DT_REG) {
                std::string name = entry->d_name;
                OnDetectFile(name);
            }
        }
    }
}
