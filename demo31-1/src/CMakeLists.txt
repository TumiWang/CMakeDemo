# 文件 src/CMakeLists.txt
cmake_minimum_required(VERSION 3.21)

project(demo31-1)

# 下面这句是 决定 find_package(OpenSSL ...) 使用静态库的关键
# 一定要在find_package前面
set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL 3.5 REQUIRED)

add_executable(test main.cpp)

target_link_libraries(test PRIVATE OpenSSL::Crypto)

install(TARGETS test DESTINATION .)