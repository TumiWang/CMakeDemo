// 文件 src/main.cpp

#include "number.h"

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << GetNumber() << std::endl;
    number_ = 1;
    std::cout << GetNumber() << std::endl;
    return 0;
}