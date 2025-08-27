#include "check_dir.h"

#include <vector>

namespace {
const std::vector<std::string> header_paths_ = {
    "include"
};

const std::vector<std::string> lib_paths_ = {
    "lib",
    "lib64",
    "share"
};

}

CheckDir::CheckDir(const std::string& dir,
        std::function<void(const std::string&)> on_header,
        std::function<void(const std::string&)> on_lib,
        std::function<void(const std::string&)> on_link)
    : DirDetect(dir),
      on_header_(on_header), on_lib_(on_lib), on_link_(on_link) {

}

void CheckDir::OnDetectDir(const std::string& dir) {
    for (const auto& item: header_paths_) {
        if (dir == item) {
            on_header_(full_path_ + dir);
            return;
        }
    }
    for (const auto& item: lib_paths_) {
        if (dir == item) {
            on_lib_(full_path_ + dir);
            return;
        }
    }
}

void CheckDir::OnDetectLink(const std::string& link) {
    for (const auto& item: header_paths_) {
        if (link == item) {
            on_link_(full_path_ + link);
            return;
        }
    }
    for (const auto& item: lib_paths_) {
        if (link == item) {
            on_link_(full_path_ + link);
            return;
        }
    }
}

void CheckDir::OnDetectFile(const std::string& file) {

}
