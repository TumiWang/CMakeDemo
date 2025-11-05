# 文件 CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo21-2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(info)
add_subdirectory(wrapper)
add_subdirectory(test)