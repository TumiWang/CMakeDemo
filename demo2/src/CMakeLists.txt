# 文件 src/CMakeLists.txt

# 这句是cmake项目的一个必须项
# 意思是指定cmake的最小版本
# 这里指定最小版本为3.21 是随便写的(我本地的cmake版本)
# 但不推荐使用 小于3.16的版本 (用着不方便，除非为了兼容老项目)
cmake_minimum_required(VERSION 3.21)

# 这个通常也是必须，设置项目名称
project(demo-2)

# 下面两句表示使用 C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 下面这句表示编译可执行程序 test
# 源码为 main.cpp 和 name.cpp
add_executable(test main.cpp name.cpp)