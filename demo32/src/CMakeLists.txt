# 文件 src/CMakeLists.txt
cmake_minimum_required(VERSION 3.21)

project(demo32)

add_executable(test main.cpp)

install(TARGETS test DESTINATION .)