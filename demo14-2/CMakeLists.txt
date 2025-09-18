# 文件 CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo-14-2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(info)
add_subdirectory(test)