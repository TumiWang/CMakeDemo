# 文件 src/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(demo33-3)

include(CTest)
include(GoogleTest)

include(FetchContent)

set(BUILD_GMOCK OFF CACHE BOOL "")
set(INSTALL_GTEST OFF CACHE BOOL "")

FetchContent_Declare(
    gtest
    # 因为 github的访问问题，这里使用一个国内的镜像库
    GIT_REPOSITORY https://gitee.com/spearNeil/googletest.git
    # GIT_REPOSITORY https://github.com/google/googletest.git
    # GIT_REPOSITORY git@github.com:google/googletest.git
    GIT_SHALLOW    ON
    GIT_TAG        v1.17.0
)

FetchContent_MakeAvailable(gtest)

add_executable(TestModel increase_model_test.cpp)
target_link_libraries(TestModel PUBLIC gtest_main)
gtest_discover_tests(TestModel)

add_library(fibonacci SHARED fibonacci.cpp)

target_include_directories(fibonacci
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(TestFibonacci fibonacci_test.cpp)
target_link_libraries(TestFibonacci PUBLIC gtest_main fibonacci)
gtest_discover_tests(TestFibonacci)
