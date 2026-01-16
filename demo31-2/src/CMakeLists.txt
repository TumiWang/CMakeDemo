# 文件 src/CMakeLists.txt
cmake_minimum_required(VERSION 3.21)

project(demo31-2)

find_path(CRYPTO_INCLUDE_DIR
    NAMES openssl/evp.h
    REQUIRED
)

# 下面这句会让 find_library 命令只查找静态库
# 扩张名 .a 和 .lib
set(CMAKE_FIND_LIBRARY_SUFFIXES .a .lib)
find_library(CRYPTO_LIB
    NAMES crypto
)

add_library(CRYPTO UNKNOWN IMPORTED)

set_target_properties(
    CRYPTO PROPERTIES
    INTERFACE_INCLUDE_DIRECTORIES "${CRYPTO_INCLUDE_DIR}"
    IMPORTED_LOCATION "${CRYPTO_LIB}"
)

# 静态库 libcrypto.a 还需要链接 pthread 和 dl
set_property(
    TARGET CRYPTO
    PROPERTY
    INTERFACE_LINK_LIBRARIES pthread dl
)

add_executable(test main.cpp)

target_link_libraries(test PRIVATE CRYPTO)

install(TARGETS test DESTINATION .)