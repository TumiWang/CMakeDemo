# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BUILD_GMOCK OFF CACHE BOOL "")

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY git@github.com:google/googletest.git
    GIT_TAG v1.17.0
    # GIT_REPOSITORY https://github.com/google/googletest.git
    # GIT_TAG 52eb8108c5bdec04579160ae17225d66034bd723
)
FetchContent_Declare(
    gflags
    GIT_REPOSITORY git@github.com:gflags/gflags.git
    GIT_TAG v2.2.2
)
FetchContent_MakeAvailable(googletest gflags)

# set(BUILD_GMOCK OFF CACHE BOOL "")
set(SOURCE info.cpp)

add_library(info SHARED ${SOURCE})

include(GoogleTest)
# include(CTest)
enable_testing()
add_executable(testAdd test.cpp)

target_link_libraries(testAdd PUBLIC info gtest gtest_main)

gtest_discover_tests(testAdd)

