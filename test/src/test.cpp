// 文件 src/name.cpp

#include "info.h"

#include "gtest/gtest.h"

TEST(InfoTest, Add1) {
    EXPECT_EQ(3, add(1, 2));
}

TEST(InfoTest, Add2) {
    EXPECT_EQ(3, add(1, 2));
    EXPECT_EQ(5, add(3, 2));
}