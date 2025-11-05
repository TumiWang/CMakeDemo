# 文件 CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo21-1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include 目录作为公共头文件
# 如果使用 target_include_directories 
# 需要设置很多 TARGET -- 麻烦！
# 所以，使用下面命令
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(info)
add_subdirectory(wrapper)
add_subdirectory(test)