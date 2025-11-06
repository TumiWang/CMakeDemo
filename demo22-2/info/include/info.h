// 文件 info/include/info.h

#ifndef __INFO_INCLUDE_INFO_H_
#define __INFO_INCLUDE_INFO_H_

#ifdef _WIN32
    // Windows
    #ifdef INFO_MODULE_IMPL
        #define EXPORT_DECORATED __declspec(dllexport)
    #else
        #define EXPORT_DECORATED __declspec(dllimport)
    #endif
#else
    #if __has_attribute(visibility)
        #define EXPORT_DECORATED __attribute__((visibility("default")))
    #else
        #define EXPORT_DECORATED
    #endif
#endif // _WIN32

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

// 这个函数的参数result，实际上是传出参数
// 是获取，模块初始化时的线程信息
//   -- 就是初始化时的线程ID, 因为这个ID在不同平台可能不同，所以，这里都转换为std::string
EXPORT_DECORATED void getInitInfo(std::string& result);

#ifdef __cplusplus
}
#endif

#endif // __INFO_INCLUDE_INFO_H_