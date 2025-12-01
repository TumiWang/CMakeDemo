# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo26)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test main.cpp)

install(TARGETS test DESTINATION .)