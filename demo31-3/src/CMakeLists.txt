# 文件 src/CMakeLists.txt
cmake_minimum_required(VERSION 3.21)

project(demo31-3)

add_executable(test main.cpp)

# 把 MyCrypto.cmake 所在目录 添加到 CMAKE_MODULE_PATH 中
# 这样 include 时，才能找到
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/module)

# 引入 MyCrypto.cmake
include(MyCrypto)

# StaticCrypto 定义在 MyCrypto.cmake 中
target_link_libraries(test PRIVATE StaticCrypto)

install(TARGETS test DESTINATION .)