# 这个例子在文章中未使用

cmake_minimum_required(VERSION 3.16)

project(demo18)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/module)
set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/config)

find_package(Test)

message(STATUS "MyTest_FOUND -- ${Test_FOUND}")