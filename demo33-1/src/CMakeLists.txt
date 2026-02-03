# 文件 src/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(demo33-1)

include(CTest)

add_executable(demo32 main.cpp)

# 添加 4个测试用例
add_test(test0 demo32)
add_test(test1 demo32 -2)
add_test(test2 demo32 5)
add_test(test2 demo32 1)
