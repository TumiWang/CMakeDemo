// 文件 info/info_posix.cpp

#include "info_inner.h"

// MacOS 和 Linux 上的动态库
// 使用 __attribute__((constructor)) 修饰的方法就会在加载后立即被调用
__attribute__((constructor))
void Init() {
    InitModule();
}

// 同理 __attribute__((destructor)) 修饰的方法 会在模块卸载前调用
__attribute__((destructor))
void Deinit() {
    DeinitModule();
}