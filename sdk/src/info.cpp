#include "info.h"

#include <sys/utsname.h>

#include <mutex>

namespace {
    std::once_flag init_arch_;

    std::string arch_;
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