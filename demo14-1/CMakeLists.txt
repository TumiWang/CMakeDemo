# 文件 CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo-14-1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT LINUX)
    message(FATAL_ERROR "当前仅支持Linux系统")
endif()

if (NOT CMAKE_SYSTEM_PROCESSOR STREQUAL "x86_64")
    message(FATAL_ERROR "当前仅支持x86_64构架")
endif()

add_subdirectory(test)