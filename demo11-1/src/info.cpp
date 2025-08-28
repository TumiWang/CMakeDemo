// 文件 src/info.cpp

#include "info.h"

unsigned int GetValueOfFibonacci(unsigned int index) {
    if (index < 2) return index;
    return GetValueOfFibonacci(index - 1) + GetValueOfFibonacci(index - 2);
}