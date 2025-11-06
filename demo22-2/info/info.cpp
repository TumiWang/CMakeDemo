// 文件 info/info.cpp

#include "info.h"
#include "info_inner.h"

#include <iostream>
#include <sstream>
#include <thread>

namespace {
    std::thread::id init_thread_id_;
}

void InitModule() {
    init_thread_id_ = std::this_thread::get_id();
}

void DeinitModule() {
    std::thread::id thread_id = std::this_thread::get_id();
    // 这段代码实际上有问题
    // std::cout 可以看作一个全局资源，不应该使用的。可能存在多线程的并发(访问)问题
    std::cout << "Unloading Info Module: Thread ID: " << thread_id << std::endl;
}

void getInitInfo(std::string& result) {
    std::ostringstream os;
    os << init_thread_id_;
    result = os.str();
}