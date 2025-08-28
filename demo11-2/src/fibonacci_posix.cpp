// 文件 src/fibonacci_posix.cpp

#include "fibonacci.h"

#include <dlfcn.h>
#include <iostream>

namespace {
// 因为在MacOS和Linux上，动态库的名称不通，这里使用编译宏(__APPLE__)控制
#ifdef __APPLE__
const char library_filename[] = "../demo11-1/build/libinfo.dylib";
#else
const char library_filename[] = "../demo11-1/build/libinfo.so";
#endif

// 在MacOS上虽然使用工具看 导出的方法名称前有前缀 _
// 但使用使用忽略这个前缀
// 所以，MacOS和Linux上，名称相同 ———— 实际上Windows上也是这个名称
const char fibonacci_func_name[] = "GetValueOfFibonacci";
}

Fibonacci::Fibonacci() {
    fibonacci_ = nullptr;
    module_ = dlopen(library_filename, RTLD_LAZY);
    if (!module_) {
        std::cout << "dlopen Failed -- " << library_filename << std::endl;
        return;
    }
    fibonacci_ = reinterpret_cast<fibonacci_func_type>(dlsym(module_, fibonacci_func_name));
    if (!fibonacci_) {
        std::cout << "dlsym Failed -- " << fibonacci_func_name << std::endl;
        return;
    }
}

Fibonacci::~Fibonacci() {
    if (module_) {
        dlclose(module_);
    }
}