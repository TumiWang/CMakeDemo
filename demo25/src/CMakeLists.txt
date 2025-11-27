# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo25)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 通过 CMAKE_CROSSCOMPILING 来判断是否使用交叉编译
if (CMAKE_CROSSCOMPILING)
    message(STATUS "using CROSSCOMPILING")
else ()
    message(STATUS "NO using CROSSCOMPILING")
endif ()

add_executable(test main.cpp)

install(TARGETS test DESTINATION .)