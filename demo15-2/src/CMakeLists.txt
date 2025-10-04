cmake_minimum_required(VERSION 3.16)

project(demo-15-2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_USE_STATIC_LIBS ON)

find_package(Boost COMPONENTS locale)

if(MSVC)
    add_compile_options(/utf-8)
endif()

add_executable(test test.cpp)

target_link_libraries(test PRIVATE Boost::locale)