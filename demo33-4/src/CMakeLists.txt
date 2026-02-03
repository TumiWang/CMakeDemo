# 文件 src/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(demo33-4)

if(MSVC)
    add_compile_options(/utf-8)
endif()

add_library(fibonacci SHARED fibonacci.cpp)

target_include_directories(fibonacci
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

# 下面的test部分
include(CTest)

if(BUILD_TESTING)
    # 下面的两个 include 可以在顶层, 而且在复杂项目里通常会这样
    # 或者和 include(CTest) 在一起
    include(GoogleTest)
    include(FetchContent)

    # 编译 gtest
    set(BUILD_GMOCK OFF CACHE BOOL "")
    set(INSTALL_GTEST OFF CACHE BOOL "")
    FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://gitee.com/spearNeil/googletest.git
        GIT_SHALLOW    ON
        GIT_TAG        v1.17.0
    )
    FetchContent_MakeAvailable(gtest)

    # increase_model.hpp 的测试
    # 可以认为是白盒测试
    add_executable(TestModel increase_model_test.cpp)
    target_link_libraries(TestModel PUBLIC gtest_main)
    gtest_discover_tests(TestModel)

    # 动态库 fibonacci 的测试
    # 可以认为是黑盒测试
    add_executable(TestFibonacci fibonacci_test.cpp)
    target_link_libraries(TestFibonacci PUBLIC gtest_main fibonacci)
    gtest_discover_tests(TestFibonacci)
endif()
