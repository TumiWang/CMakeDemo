// 文件 src/main.cpp

#include <iostream>

#include "module1/api.h"
#include "module3/api.h"

int main(int argc, char* argv[]) {
    std::cout << "直接调用Module1: " << GetName() << std::endl;
    std::cout << GetInfo() << std::endl;
    return 0;
}