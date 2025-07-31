// 文件 src/main.cpp

#include <iostream>

#include <string>

// 这次没有写一个头文件 -- 提供 GetName 函数的声明
// 下面这种声明方式，在实际使用上，比写一个头文件麻烦
// 1. 如果有多个源文件，则每个源文件都要写一次这个声明
//    如果要修改 GetName 函数的原型也会更麻烦一些
// 2. 这里 GetName 函数使用了 std::string 类型
//    这需要额外的 包含 <string>；也是每个需要使用GetName 函数的源文件都需要
// 所以，下面这种写法并不推荐
std::string GetName();

const char* GetLabel() {
#ifdef CPP_FANTASY_CHINESE
    return "C++幻想";
#else 
    return "c++ fantasy";
#endif
}

int main(int argc, char* argv[]) {
    std::cout << "Label: " << GetLabel() << std::endl;
    std::cout << "Name: " << GetName() << std::endl;
    return 0;
}