// 文件 src/fibonacci_.cpp

#include "fibonacci.h"

#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace {
const char library_filename[] = "../demo11-1/build/Release/info.dll";
const char fibonacci_func_name[] = "CreateFibonacciInstance";

using fibonacci_func_type = FibonacciInterface*(*)();
}

FibonacciInterface* CreateFibonacciInterface() {
    do {
        HMODULE info_module = LoadLibraryA(library_filename);
        if (!info_module) break;
        fibonacci_func_type fibonacci_func = 
            reinterpret_cast<fibonacci_func_type>(GetProcAddress(info_module, fibonacci_func_name););
        if (!fibonacci_func) break;
        return fibonacci_func();
    } while(false);

    return nullptr;
}