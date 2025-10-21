# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo18-1)

add_subdirectory(first)

if (TARGET Boost::locale)
    message(STATUS "Boost::locale is found in src")
else()
    message(STATUS "Boost::locale is NOT found in src")
endif()