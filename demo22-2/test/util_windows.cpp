// 文件 test/util_windows.cpp

#include "util.h"

const char* info_module_name_ = "info.dll";

HMODULE LoadInfoLib(const std::string& filename) {
    return LoadLibraryA(filename.c_str());;
}

void UnloadInfoLib(HMODULE module) {
    if (module) {
        FreeLibrary(module);
    }
}

GetInitInfo_Func_Type GetInfoFunc(HMODULE module) {
    GetInitInfo_Func_Type func = nullptr;

    if (module) {
        func = (GetInitInfo_Func_Type)GetProcAddress(module, "getInitInfo");
    }

    return func;
}