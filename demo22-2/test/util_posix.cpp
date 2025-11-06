// 文件 test/util_posix.cpp

#include "util.h"

#include <dlfcn.h>

#ifdef __APPLE__
const char* info_module_name_ = "libinfo.dylib";
#else
const char* info_module_name_ = "libinfo.so";
#endif

HMODULE LoadInfoLib(const std::string& filename) {
    return dlopen(filename.c_str(), RTLD_LAZY);
}

void UnloadInfoLib(HMODULE module) {
    if (module) {
        dlclose(module);
    }
}

GetInitInfo_Func_Type GetInfoFunc(HMODULE module) {
    GetInitInfo_Func_Type func = nullptr;

    if (module) {
        func = reinterpret_cast<GetInitInfo_Func_Type>(dlsym(module, "getInitInfo"));
    }

    return func;
}