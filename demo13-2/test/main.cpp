// 文件 test/main.cpp

#include "info.h"

#include <iomanip>
#include <iostream>

int main() {
    FibonacciInterface* f1 = nullptr;
    FibonacciInterface* f2 = nullptr;

    f1 = CreateFibonacciInstance(true);
    f2 = CreateFibonacciInstance(false);

    if (!f1 || !f2) {
        std::cout << "CreateFibonacciInstance -- Failed" << std::endl;
        return 1;
    }

    for (unsigned int i = 0; i <= 10; ++i)
        std::cout << std::setw(2) << i << " ";
    std::cout << std::endl;

    for (unsigned int i = 0; i <= 10; ++i)
        std::cout << std::setw(2) << f1->GetValue(i) << " ";
    std::cout << std::endl;

    for (unsigned int i = 0; i <= 10; ++i)
        std::cout << std::setw(2) << f2->GetValue(i) << " ";
    std::cout << std::endl;

    f1->Cleanup();
    f2->Cleanup();

    return 0;
}