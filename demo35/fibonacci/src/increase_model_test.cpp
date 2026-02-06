// 文件 src/increase_model_test.cpp

#include "gtest/gtest.h"

#include "increase_model.hpp"

// 测试 increase_model.hpp 中的 函数 UpdateIncreaseModel

TEST(Model, TestUnsignedChar) {
    std::vector<unsigned char> items;

    // 现在 items 内没有元素，所以会失败 -- 要求它至少有两个元素
    ASSERT_FALSE(UpdateIncreaseModel(items, 5));

    items.insert(items.end(), {20, 30});

    // 扩充到 5 个
    // items 为 {20, 30, 50, 80, 130}
    ASSERT_TRUE(UpdateIncreaseModel(items, 5));
    ASSERT_TRUE(items[4] == 130);

    // 扩充到 7 个
    // items 应该为 {20, 30, 50, 80, 130, 210, 340}
    // 但 340已经越界，就是超过 unsigned char 类型的最大值
    ASSERT_FALSE(UpdateIncreaseModel(items, 7));

    ASSERT_TRUE(items.size() == 6);
    ASSERT_TRUE(items[5] == 210);
}

TEST(Model, TestShort) {
    std::vector<short> items{20, 30};

    ASSERT_TRUE(UpdateIncreaseModel(items, 7));
    ASSERT_TRUE(items[6] == 340);
}

TEST(Model, TestInt) {
    std::vector<int> items;

    items.insert(items.end(), {-2, -9});

    ASSERT_TRUE(UpdateIncreaseModel(items, 40));
    // EXPECT_* 比 ASSERT_* 更温和
    // ASSERT_* 会结束
    EXPECT_EQ(-647390212, items[39]);
    // EXPECT_* 会打印出预期的值
    // 例如, 把上面这句修改为 EXPECT_EQ(-647390212, items[38]);
    // 会报告 items[38] 的值为 -400109155 而预期是 -647390212

    ASSERT_TRUE(UpdateIncreaseModel(items, 42));
    EXPECT_FALSE(UpdateIncreaseModel(items, 43));
}

TEST(Model, TestFloat) {
    std::vector<float> items = {0.1f, 1.23f};

    // items.insert(items.end(), );
    EXPECT_TRUE(UpdateIncreaseModel(items, 100));

    EXPECT_FLOAT_EQ(2.8280554e+20, items[99]);
    EXPECT_FLOAT_EQ(2.828055e+20, items[99]);
    EXPECT_FLOAT_EQ(2.828056e+20, items[99]);

    // 下面这句不满足
    // EXPECT_FLOAT_NE(2.82805e+20, items[99]);
}