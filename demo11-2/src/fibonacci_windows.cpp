// 文件 src/fibonacci_.cpp

#include "fibonacci.h"

#include <iostream>

namespace {
const char library_filename[] = "../demo11-1/build/Release/info.dll";
const char fibonacci_func_name[] = "GetValueOfFibonacci";
}

Fibonacci::Fibonacci() {
    fibonacci_ = nullptr;
    module_ = LoadLibraryA(library_filename);
    if (!module_) {
        std::cout << "LoadLibraryA Failed -- " << library_filename << std::endl;
        return;
    }
    fibonacci_ = (fibonacci_func_type)GetProcAddress(module_, fibonacci_func_name);
    if (!fibonacci_) {
        std::cout << "GetProcAddress Failed -- " << fibonacci_func_name << std::endl;
        return;
    }
}

Fibonacci::~Fibonacci() {
    if (module_) {
        FreeLibrary(module_);
    }
}