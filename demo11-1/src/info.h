// 文件 src/info.h

#ifndef __INFO_H___
#define __INFO_H___

// 实际上，宏通常都不缩进的，这里为了看看清楚
#ifdef _WIN32
    // Windows
    #define MY_INFO_EXPORT __declspec(dllexport)
#else
    #if __has_attribute(visibility)
        #define MY_INFO_EXPORT __attribute__((visibility("default")))
    #endif
#endif // _WIN32

#ifndef MY_INFO_EXPORT
    #define MY_INFO_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

// 如果使用c++编译器，该函数会使用C风格
MY_INFO_EXPORT unsigned int GetValueOfFibonacci(unsigned int index);

#ifdef __cplusplus
}
#endif

#endif // __INFO_H___
