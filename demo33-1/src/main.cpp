// 文件 src/main.cpp
#include <chrono>
#include <string>
#include <thread>

// 通常 main 的返回值就是程序的退出值
// 通常 退出值不为0 则认为程序运行结果不符合预期(没有完成运行程序的预期目标)
int main(int argc, char const* argv[]) {
    int seconds = 0;

    if (argc != 2) {
        // 我们预期有2个参数，因为第一个参数是当前可执行程序
        return 1;
    }
        
    try {
        seconds = std::stoi(argv[1]);
    }
    catch(...) {
        // 参数解析失败
        return 2;
    }

    if (seconds < 0) {
        // 参数不合法
        return 3;
    }

    if (seconds > 100) {
        // 参数不合法
        return 4;
    }

    std::this_thread::sleep_for(std::chrono::seconds(seconds));

    return 0;
}