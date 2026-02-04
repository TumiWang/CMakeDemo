// 文件 src/main.cpp

#include "fibonacci.h"

#include <iostream>

int main() {
    FibonacciInterface* fibonacci = CreateFibonacciInstance();
    if (fibonacci) {
        unsigned int index = 120;
        std::cout << "index: " << index
                  << " --- fibonacci: " << fibonacci->GetValue(index)
                  << std::endl;
        fibonacci->Cleanup();
    }
    return 0;
}