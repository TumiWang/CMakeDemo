# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo-20)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

if (BUILD_SHARED_LIBS)
    add_compile_definitions(USING_DYNAMIC_LIB)
endif()

add_subdirectory(module1)
add_subdirectory(module2)
add_subdirectory(module3)
add_subdirectory(test)