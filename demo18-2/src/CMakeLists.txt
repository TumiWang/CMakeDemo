cmake_minimum_required(VERSION 3.16)

project(demo18-2)

set(CMAKE_PREFIX_PATH ${CMAKE_SOURCE_DIR}/config)

message(STATUS "find_package(MyTest) -- start")

find_package(MyTest CONFIG)

message(STATUS "find_package(MyTest) -- end")

message(STATUS "MyTest_FOUND -- ${MyTest_FOUND}")