# 文件 CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(sdk)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    check_dir.cpp
    dir_detect.cpp
    info.cpp
    insert_all.cpp
    lib_detect.cpp
    main.cpp
    tar_file.cpp
)

add_executable(tar_sdk ${SOURCES})

find_package(LibArchive)
target_link_libraries(tar_sdk PUBLIC LibArchive::LibArchive)