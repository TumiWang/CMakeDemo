# 文件 fibonacci/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

add_library(info SHARED info.cpp)

target_compile_definitions(info PRIVATE INFO_IMPL)

target_include_directories(info PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(info PUBLIC version_info)