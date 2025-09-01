// 文件 src/main.cpp

#include "fibonacci.h"

#include <chrono>
#include <iostream>
#include <string>

class CalcDuration {
public:
    CalcDuration(const std::string& info): info_(info) {
        begin_ = std::chrono::high_resolution_clock::now();
    }
    ~CalcDuration() {
        auto end = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<float, std::milli> d = end - begin_;
        std::cout << info_ << " ---- " << d.count() << "ms" << std::endl;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> begin_;
    const std::string info_;
};

int main() {
    FibonacciInterface* f1 = nullptr;
    FibonacciInterface* f2 = nullptr;

    {
        // 这里用{} 是为了限制CalcDuration实例的生命周期(下同)
        CalcDuration c("Create f1");
        f1 = CreateFibonacciInterface();
    }

    {
        CalcDuration c("Create f2");
        f2 = CreateFibonacciInterface();
    }
    if (!f1 || !f2) {
        std::cout << "CreateFibonacciInterface -- Failed" << std::endl;
        return 1;
    }

    std::cout << "===========================" << std::endl;

    {
        CalcDuration c("f1 Calc 101");
        std::cout << "101 -> " << f1->GetValue(101) << std::endl;
    }

    {
        CalcDuration c("f1 Calc 102");
        std::cout << "102 -> " << f1->GetValue(102) << std::endl;
    }

    std::cout << "---------------------------" << std::endl;

    {
        CalcDuration c("f2 Calc 100");
        std::cout << "100 -> " << f2->GetValue(100) << std::endl;
    }

    std::cout << "===========================" << std::endl;

    {
        CalcDuration c("cleanup f1 and f2");
        f1->Cleanup();
        f2->Cleanup();
    }

    return 0;
}