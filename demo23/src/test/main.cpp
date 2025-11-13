// 文件 src/main.cpp

#include <iostream>

#include "module1/api.h"
#include "module3/api.h"

int main(int argc, char* argv[]) {
    std::cout << "调用GetName: " << GetName() << std::endl;
    std::cout << "调用GetInfo: " << GetInfo() << std::endl;
    return 0;
}