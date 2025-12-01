# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo27)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test1 main.cpp)

# resource.rc 是资源文件 -- 用于展示资源编译(CMAKE_RC_COMPILER)
add_executable(test2 win_main.cpp resource.rc)
# WIN32_EXECUTABLE 属性表示 程序启动入口为WinMain
set_target_properties(test2 PROPERTIES WIN32_EXECUTABLE TRUE)

install(TARGETS test1 test2 DESTINATION .)