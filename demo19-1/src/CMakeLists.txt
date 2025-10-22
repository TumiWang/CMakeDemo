cmake_minimum_required(VERSION 3.16)

project(demo19-1)

find_package(PkgConfig REQUIRED)

pkg_check_modules(OpenSSL REQUIRED openssl)

pkg_check_modules(Crypto REQUIRED libcrypto)
pkg_check_modules(SSL REQUIRED libssl)

message(STATUS "OpenSSL 头文件目录 ${OpenSSL_INCLUDE_DIRS}")
message(STATUS "OpenSSL 链接参数 ${OpenSSL_LDFLAGS}")

message(STATUS "Crypto动态库链接参数 ${Crypto_LDFLAGS}")
message(STATUS "Crypto静态库链接参数 ${Crypto_STATIC_LDFLAGS}")

message(STATUS "SSL动态库链接参数 ${SSL_LDFLAGS}")
message(STATUS "SSL静态库链接参数 ${SSL_STATIC_LDFLAGS}")