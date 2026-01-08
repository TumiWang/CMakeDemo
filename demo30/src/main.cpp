// 文件 src/main.cpp

#include <iostream>
#include <thread>

int main()
{
    std::thread t([] {
        std::cout << "我是C++幻想" << std::endl;
    });
    t.join();
}