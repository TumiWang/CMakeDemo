# 文件 CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo22-2)

# 要使用 C++17 的 filesystem
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

add_subdirectory(info)
add_subdirectory(test)