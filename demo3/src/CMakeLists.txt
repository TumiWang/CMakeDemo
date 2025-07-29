# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo-3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test main.cpp number.cpp)