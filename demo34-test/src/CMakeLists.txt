# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo34-test)

# 配合 install 命令
set(CMAKE_INSTALL_RPATH "$ORIGIN")

find_package(Fibonacci REQUIRED)

add_executable(test main.cpp)

target_link_libraries(test PUBLIC fibonacci)

# install 命令
install(TARGETS test DESTINATION .)
