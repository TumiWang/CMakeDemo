#include "info.h"

#include <sys/utsname.h>

#include <mutex>

namespace {
    std::once_flag init_arch_;
    std::string arch_;

    std::once_flag init_lib_prefix_;
    std::vector<std::string> lib_prefix_;

    std::once_flag init_blacklist_prefix_;
    std::vector<std::string> blacklist_prefix_;

    void InitLibPrefix() {
        lib_prefix_.push_back("cmake");
        lib_prefix_.push_back("gcc");
        lib_prefix_.push_back("pkgconfig");
        lib_prefix_.push_back(GetArch());
        lib_prefix_.push_back("clang");
        lib_prefix_.push_back("llvm");
    }

    void InitBlacklistPrefix() {
        blacklist_prefix_.push_back("cmake-");
        blacklist_prefix_.push_back("perl");
    }
}

const std::string& GetArch() {
    std::call_once(init_arch_, [] {
        struct utsname info;
        if (uname(&info) >= 0) {
            arch_ = info.machine;
        }
    });
    return arch_;
}

bool MatchLibPrefix(const std::string& name) {
    std::call_once(init_lib_prefix_, InitLibPrefix);

    bool result = false;

    for (auto& item: lib_prefix_) {
        if (name.size() < item.size()) continue;
        if (name.size() == item.size()) {
            if (item != name) continue;
            result = true;
            break;
        }
        auto temp = name.substr(0, item.size());
        if (temp == item) {
            result = true;
            break;
        }
    }

    return result;
}

bool MatchBlacklistPrefix(const std::string& name) {
    std::call_once(init_blacklist_prefix_, InitBlacklistPrefix);

    bool result = false;

    for (auto& item: blacklist_prefix_) {
        if (name.size() < item.size()) continue;
        if (name.size() == item.size()) {
            if (item != name) continue;
            result = true;
            break;
        }
        auto temp = name.substr(0, item.size());
        if (temp == item) {
            result = true;
            break;
        }
    }

    return result;
}