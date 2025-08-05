// 文件 src/info.h

#ifndef __INFO_H___
#define __INFO_H___

#ifdef MY_INFO_SHARED_LIBS
// 动态库
    #ifdef _WIN32
    // Windows
    // 实际上使用 _WIN32 宏判断可能有问题，
    // 更好的方法是使用cmake判断后定义 对应的宏。
        #ifdef MY_INFO_IMPL
            #define MY_INFO_EXPORT __declspec(dllexport)
        #else
            #define MY_INFO_EXPORT __declspec(dllimport)
        #endif // MY_INFO_IMPL
    #else
    // 如果不是Windows，我们就简单粗暴的认为是Linux和MacOS
        #if __has_attribute(visibility)
        #define MY_INFO_EXPORT __attribute__((visibility("default")))
        #endif
    #endif // _WIN32
#else
// 静态库
    #define MY_INFO_EXPORT
#endif // MY_INFO_SHARED_LIBS

MY_INFO_EXPORT const char* GetInfo();

#endif // __INFO_H___
