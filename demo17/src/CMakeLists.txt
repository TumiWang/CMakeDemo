cmake_minimum_required(VERSION 3.16)

project(demo17)

set(CUR_TYPE "$<CONFIG>")

add_executable(test main.cpp)

# 在cmake创建项目时，打印变量 CUR_TYPE的值
message(STATUS "CUR_TYPE -- ${CUR_TYPE}")

target_compile_definitions(
    test PUBLIC
    # 这是定义了一个宏 CURRENT_TYPE
    # 这样运行时，就可以通过执行结果看到在编译时，变量 CUR_TYPE的值
    CURRENT_TYPE="${CUR_TYPE}"
)