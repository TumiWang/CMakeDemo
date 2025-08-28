// 文件 src/fibonacci.h

#ifndef __FIBONACCI_H__
#define __FIBONACCI_H__

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif // _WIN32

class Fibonacci {
public:
    Fibonacci();
    ~Fibonacci();

public:
    unsigned int Calc(unsigned int index);

private:
    using fibonacci_func_type = unsigned int(*)(unsigned int);
    fibonacci_func_type fibonacci_;

#ifdef _WIN32
    HANDLE module_;
#else
    void* module_;
#endif // _WIN32
};

#endif // __FIBONACCI_H__