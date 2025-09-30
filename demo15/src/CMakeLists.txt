# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo-15-1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 下面这句指定boost使用静态库
# Boost_USE_STATIC_LIBS 要在 find_package(Boost ...) 前
set(Boost_USE_STATIC_LIBS ON)

find_package(Boost COMPONENTS locale)

if(MSVC)
    add_compile_options(/utf-8)
endif()

add_library(trans SHARED trans.cpp)

target_link_libraries(trans PRIVATE Boost::locale)