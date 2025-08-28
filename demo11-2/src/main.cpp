// 文件 src/main.cpp

#include "fibonacci.h"

#include <iostream>

int main() {
    Fibonacci fibonacci;

    unsigned int i = 8;
    std::cout << i << " -> " << fibonacci.Calc(i) << std::endl;
}