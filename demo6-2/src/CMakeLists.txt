# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo-6-2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE main.cpp info.cpp)

add_executable(test2 ${SOURCE})