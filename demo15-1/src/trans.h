// 文件 src/trans.h

#ifndef __TRANS_H___
#define __TRANS_H___

// 实际上，宏通常都不缩进的，这里为了看看清楚
#ifdef _WIN32
    // Windows
    #define MY_TRANS_EXPORT __declspec(dllexport)
#else
    #if __has_attribute(visibility)
        #define MY_TRANS_EXPORT __attribute__((visibility("default")))
    #endif
#endif // _WIN32

#ifndef MY_TRANS_EXPORT
    #define MY_TRANS_EXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

// 如果使用c++编译器，该函数会使用C风格
// 下面函数trans_gbk2utf8 的功能是把GBK编译转为UTF8编码
// text是GBK编译的输入参数
// buff 和 buff_len 是 UTF8编码的存储内存
// 返回值是 UTF8 编码的字符串的长度
// 如果 buff_len小于返回值，实际上不会填充 buff的内存
// 这时，可以重新分配一个足够长度的内存
MY_TRANS_EXPORT int trans_gbk2utf8(const char* text, char* buff, int buff_len);

#ifdef __cplusplus
}
#endif

#endif // __TRANS_H___
