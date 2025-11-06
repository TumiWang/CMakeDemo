// 文件 test/main.cpp

#include "info.h"

#include <iostream>
#include <thread>

int main() {
    std::cout << "Main Thread ID: " << std::this_thread::get_id() << std::endl;

    std::thread thread([]{
        std::cout << "Work Thread ID: " << std::this_thread::get_id() << std::endl;
        std::string text;
        getInitInfo(text);
        std::cout << "Thread ID of loading info: " << text << std::endl;
    });

    thread.join();
}