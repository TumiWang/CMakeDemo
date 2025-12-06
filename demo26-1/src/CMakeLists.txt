# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo26-1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_cpp main.cpp)

install(TARGETS test_cpp DESTINATION ${CMAKE_SYSTEM_PROCESSOR})