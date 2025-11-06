// 文件 info/info_windows.cpp

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "info_inner.h"

BOOL WINAPI DllMain(HINSTANCE hInstDLL, DWORD dwReason, LPVOID lpvReserved) {
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        InitModule();
        break;
    case DLL_PROCESS_DETACH:
        DeinitModule();
        break;
    // dwReason 还有两个值：
    // DLL_THREAD_ATTACH 和 DLL_THREAD_DETACH
    default:
        break;
    }

    // 这里返回FALSE 会加载失败
    return TRUE;
}