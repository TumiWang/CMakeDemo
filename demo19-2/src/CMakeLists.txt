# 文件 src/CMakeLists.txt
cmake_minimum_required(VERSION 3.16)

project(demo19-2)

find_package(PkgConfig REQUIRED)

# OpenSSL包含两个库, libcryto.so 和 libssl.so
pkg_check_modules(EVP REQUIRED libcrypto)

add_executable(test main.cpp)


target_include_directories(test PRIVATE ${EVP_STATIC_INCLUDE_DIRS})

target_link_libraries(test PRIVATE ${EVP_STATIC_LDFLAGS})