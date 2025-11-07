// 文件 test/main.cpp

#include "util.h"

#include <cstdlib>
#include <chrono>
#include <ctime>
#include <iostream>
#include <mutex>
#include <thread>

int main(int argc, char* argv[]) {
    std::cout << "Main Thread ID: " << std::this_thread::get_id() << " -- Start" << std::endl;

    std::srand(std::time(0));

    // 随机睡眠 [1, 100) 毫秒
    auto rand_sleep = [] {
        std::this_thread::sleep_for(std::chrono::milliseconds((std::rand() % 100) + 1));
    };

    // 保护 std::cout
    std::mutex mutex_cout;

    // 工作线程的工作
    auto thread_proc = [&]() {
        std::thread::id thread_id = std::this_thread::get_id();
        // argv[0] 是当前进程文件
        // 因为系统和启动方式的差异，它可能是相对路径或绝对路径
        // 但注意：在Windows上，通常是GBK编码的
        std::string filename = GetInfoFullPath(argv[0]);

        rand_sleep();

        {
            // 这个是为了控制 lock变量的生命周期
            const std::lock_guard<decltype(mutex_cout)> lock(mutex_cout);
            std::cout << "Thread ID:" << thread_id << " -- Will load Info module" << std::endl;
        }

        HMODULE module = LoadInfoLib(filename);
        if (module == nullptr) return; // 偷懒：不打印错误信息了

        rand_sleep();

        GetInitInfo_Func_Type get_info = GetInfoFunc(module);
        if (get_info == nullptr) return; // 偷懒：不打印错误信息了

        std::string text;
        get_info(text);

        {
            const std::lock_guard<decltype(mutex_cout)> lock(mutex_cout);
            std::cout << "Thread ID:" << thread_id << " -- Show: load info module thread id: " << text << std::endl;
        }

        rand_sleep();

        {
            const std::lock_guard<decltype(mutex_cout)> lock(mutex_cout);
            std::cout << "Thread ID:" << thread_id << " -- Will Unload Info module" << std::endl;
        }

        UnloadInfoLib(module);

        {
            const std::lock_guard<decltype(mutex_cout)> lock(mutex_cout);
            std::cout << "Thread ID:" << thread_id << " -- Has Unloaded Info module" << std::endl;
        }

        {
            const std::lock_guard<decltype(mutex_cout)> lock(mutex_cout);
            std::cout << "Thread ID:" << thread_id << " -- getInitInfo addr: 0x"
                      << std::hex << reinterpret_cast<uintptr_t>(get_info) << std::oct << std::endl;
        }
    };

    // 工作线程池
    std::thread threads[3];

    // 启动所有工作线程
    for (int i = 0; i < sizeof(threads) / sizeof(threads[0]); ++i) {
        threads[i] = std::thread(thread_proc);
    }

    // 等待所有线程结束
    for (int i = 0; i < sizeof(threads) / sizeof(threads[0]); ++i) {
        threads[i].join();
    }
}