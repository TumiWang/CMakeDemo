# 文件 CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo-10-2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

# 和RUNPATH项目的变量
# cmake有几个
# 例如：设置编译时的RUNPATH的 CMAKE_BUILD_RPATH
# 我们这里只修改了 install 命令时的RUNPATH
# $ORIGIN 表示当前目录 关于这个话题的展开请参考附录三
set(CMAKE_INSTALL_RPATH "$ORIGIN")

add_subdirectory(info)
add_subdirectory(test)