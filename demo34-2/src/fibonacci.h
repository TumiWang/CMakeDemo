// 文件 src/fibonacci.h

#ifndef __FIBONACCI_H___
#define __FIBONACCI_H___

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

class FibonacciInterface {
public:
    FibonacciInterface() = default;
    virtual ~FibonacciInterface() = default;

    virtual const char* GetValue(unsigned int index) = 0;

    // 这是自清理方法
    // 该方法调用后，这个接口指针就失效了
    virtual void Cleanup() = 0;
};

#ifdef __cplusplus
extern "C" {
#endif

// 如果使用c++编译器，该函数会使用C风格
MY_INFO_EXPORT FibonacciInterface* CreateFibonacciInstance();

#ifdef __cplusplus
}
#endif

#endif // __FIBONACCI_H___
