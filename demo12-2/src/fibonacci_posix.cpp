// 文件 src/fibonacci_posix.cpp

#include "fibonacci.h"

#include <dlfcn.h>
#include <iostream>

namespace {
// 因为在MacOS和Linux上，动态库的名称不通，这里使用编译宏(__APPLE__)控制
#ifdef __APPLE__
const char library_filename[] = "../demo12-1/build/libinfo.dylib";
#else
const char library_filename[] = "../demo12-1/build/libinfo.so";
#endif

const char fibonacci_func_name[] = "CreateFibonacciInstance";

using fibonacci_func_type = FibonacciInterface*(*)();
}

FibonacciInterface* CreateFibonacciInterface() {
    do {
        void* info_module = dlopen(library_filename, RTLD_LAZY);
        if (!info_module) break;
        fibonacci_func_type fibonacci_func = 
            reinterpret_cast<fibonacci_func_type>(dlsym(info_module, fibonacci_func_name));
        if (!fibonacci_func) break;
        return fibonacci_func();
    } while(false);

    return nullptr;
}