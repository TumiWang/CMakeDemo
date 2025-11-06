// 文件 info/info_windows.cpp

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "info_inner.h"

BOOL WINAPI DllMain(HINSTANCE hInstDLL, DWORD dwReason, LPVOID lpvReserved) {
    switch (reason)
    {
    case DLL_PROCESS_ATTACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    // reason 还有两个值：
    // DLL_THREAD_ATTACH 和 DLL_THREAD_DETACH
    default:
        break;
    }
}