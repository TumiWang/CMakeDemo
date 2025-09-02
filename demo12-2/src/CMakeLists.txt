# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo-12-2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

set(SOURCES main.cpp)

# 这里根据不同的平台，使用了不同的源文件
if (WIN32)
list(APPEND SOURCES fibonacci_windows.cpp)
else()
list(APPEND SOURCES fibonacci_posix.cpp)
endif()

add_executable(test ${SOURCES})