cmake_minimum_required(VERSION 3.16)

project(demo18-3)

# 实际上，可以不用 MODULE 参数
# 只要不使用 CONFIG 或 NO_MODULE 参数，就可以
find_package(OpenSSL MODULE)

message(STATUS "OpenSSL_FOUND ${OpenSSL_FOUND}")

if (TARGET OpenSSL::Crypto)
    message(STATUS "Cropto Found")
endif()