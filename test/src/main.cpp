// 文件 src/main.cpp

#include "info.h"
#include "name.cpp"

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Name: "<< GetName() << std::endl;
    std::cout << "Info: "<< GetInfo() << std::endl;
    return 0;
}