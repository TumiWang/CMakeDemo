# 文件 CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

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
if (TARGET LibArchive::LibArchive)
    target_link_libraries(tar_sdk PUBLIC LibArchive::LibArchive)
else ()
    target_include_directories(tar_sdk PUBLIC ${LibArchive_INCLUDE_DIRS})
    target_link_libraries(tar_sdk PUBLIC ${LibArchive_LIBRARIES})
endif ()

install(TARGETS tar_sdk DESTINATION .)