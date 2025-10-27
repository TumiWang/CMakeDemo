# 文件 CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo20-2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

if (APPLE)
    set(CMAKE_INSTALL_RPATH "@executable_path")
else()
    set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif ()

add_subdirectory(info)
add_subdirectory(wrapper)
add_subdirectory(test)