// 文件 src/fibonacci_.cpp

#include "fibonacci.h"

unsigned int Fibonacci::Calc(unsigned int index) {
    if (!fibonacci_) return static_cast<unsigned int>(-1);
    return fibonacci_(index);
}