# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo-5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test2 main.cpp)

if (DEFINED TEST_CONTENT)
    target_compile_definitions(test2 PUBLIC TEST_CONTENT=${TEST_CONTENT})
endif()