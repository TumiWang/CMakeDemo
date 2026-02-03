// 文件 src/fibonacci_test.cpp

#include "gtest/gtest.h"

#include "fibonacci.h"

#include <thread>

// 这个测试用例的用法和 increase_model_test.cpp 的一致
// 实际上更像是用法的简单示例
TEST(FibonacciExtend, TestExtend) {
    FibonacciInterface* impl = CreateFibonacciInstance(FibonacciInterface::FibonacciType::Extend);
    ASSERT_NE(nullptr, impl);

    EXPECT_EQ(1, impl->GetValue(0));
    EXPECT_EQ(1, impl->GetValue(1));
    EXPECT_EQ(2, impl->GetValue(2));
    EXPECT_EQ(3, impl->GetValue(3));
    EXPECT_EQ(5, impl->GetValue(4));
    EXPECT_EQ(1134903170, impl->GetValue(44));
    EXPECT_EQ(1836311903, impl->GetValue(45));
    EXPECT_EQ(2971215073, impl->GetValue(46));

    // 已经溢出
    EXPECT_EQ(0, impl->GetValue(47));

    impl->Cleanup();
}

// 每一个 TEST(FibonacciStandard, ...)
// 在运行前，都会执行 FibonacciStandard::SetUp
// 在运行后，都会执行 FibonacciStandard::TearDown
class FibonacciStandard : public testing::Test {
protected:
    void SetUp() override {
        finonacci_ = CreateFibonacciInstance(FibonacciInterface::FibonacciType::Standard);
    }

    void TearDown() override {
        finonacci_->Cleanup();
    }

    FibonacciInterface* finonacci_ = nullptr;
};

// 下面的例子，可以和 FibonacciExtend.TestExtend 对比
// 可以Standard的第n项 和 Extend 的第n-1项对应
TEST_F(FibonacciStandard, TestStandard) {
    ASSERT_NE(nullptr, finonacci_);

    EXPECT_EQ(0, finonacci_->GetValue(0));
    EXPECT_EQ(1, finonacci_->GetValue(1));
    EXPECT_EQ(1, finonacci_->GetValue(2));
    EXPECT_EQ(2, finonacci_->GetValue(3));
    EXPECT_EQ(3, finonacci_->GetValue(4));
    EXPECT_EQ(1134903170, finonacci_->GetValue(45));
    EXPECT_EQ(1836311903, finonacci_->GetValue(46));
    EXPECT_EQ(2971215073, finonacci_->GetValue(47));

    // 已经溢出
    EXPECT_EQ(0, finonacci_->GetValue(48));
}

TEST_F(FibonacciStandard, TestThreads) {
    // 两个线程并发访问 finonacci_
    std::thread t1([&]{
        EXPECT_EQ(2971215073, finonacci_->GetValue(47));
        EXPECT_EQ(3, finonacci_->GetValue(4));
        EXPECT_EQ(1134903170, finonacci_->GetValue(45));
    });

    std::thread t2([&]{
        EXPECT_EQ(1836311903, finonacci_->GetValue(46));
        EXPECT_EQ(5, finonacci_->GetValue(5));
        EXPECT_EQ(1134903170, finonacci_->GetValue(45));
    });

    t2.join();
    t1.join();
}