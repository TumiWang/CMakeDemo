# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo34-test)

if(MSVC)
    add_compile_options(/utf-8)
endif()

# 配合 install 命令
set(CMAKE_INSTALL_RPATH "$ORIGIN")

find_package(Fibonacci REQUIRED)

add_executable(test main.cpp)

target_link_libraries(test PUBLIC fibonacci)

# install 命令
install(TARGETS test DESTINATION .)

# 这里偷懒了，断言是RELEASE
get_target_property(result fibonacci IMPORTED_LOCATION_RELEASE)
if (result)
    install(FILES ${result} DESTINATION .)
endif()