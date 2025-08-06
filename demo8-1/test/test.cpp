// 文件 test/test.cpp

#include "../info/info.h"

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << GetInfo() << std::endl;
    return 0;
}