# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo25)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_stdlibcxx main.cpp)

add_executable(test_libcxx main.cpp)
target_compile_options(test_libcxx PRIVATE -stdlib=libc++)
target_link_options(test_libcxx PRIVATE -stdlib=libc++)


install(TARGETS test_stdlibcxx test_libcxx DESTINATION .)