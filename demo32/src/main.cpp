// 文件 src/main.cpp

#include <cstring>
#include <iostream>

int main()
{
    int* p = new int[5];

    // memset(p, 0, sizeof(*p) * 5);
    // 没有下面这句, p[3] 实际上没有初始化
    // 在工具链文件中, 使用 -fsanitize=memory 可以检查

    std::cout << "hello: " << p[3] << std::endl;

    // 如果没有 delete[] 就有内存泄露
    // 在工具链文件中, 使用 -fsanitize=address 可以检查
    delete[] p;
    
    p = nullptr;

    return 0;
}