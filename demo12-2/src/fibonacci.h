// 文件 src/fibonacci.h

#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

class FibonacciInterface {
public:
    FibonacciInterface() = default;
    virtual ~FibonacciInterface() = default;

    virtual const char* GetValue(unsigned int index) = 0;

    // 这是自清理方法
    // 该方法调用后，这个接口指针就失效了
    virtual void Cleanup() = 0;
};

FibonacciInterface* CreateFibonacciInterface();

#endif // __FIBONACCI_H__