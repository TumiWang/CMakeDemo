# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo-12-1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(info SHARED info.cpp)