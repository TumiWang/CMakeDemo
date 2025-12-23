# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo28)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 编译资源需要的工具 ---- glib-compile-resources
find_program(GLIB_RC_COMPILE NAMES glib-compile-resources REQUIRED)

# 把资源编译成c的源码 grc.h 和 grc.c
# 不同版本的 glib-compile-resources 的使用参数可能不同
set(GRC_H grc.h)
set(GRC_C grc.c)
# 生成 头文件 grc.h
add_custom_command(
    OUTPUT ${GRC_H}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ${GLIB_RC_COMPILE}
    ARGS
        --generate-header
        --target=${CMAKE_CURRENT_BINARY_DIR}/${GRC_H}
        Test.gresource.xml
    VERBATIM
    MAIN_DEPENDENCY Test.gresource.xml
)
# 生成 源文件 grc.c
add_custom_command(
    OUTPUT ${GRC_C}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMAND ${GLIB_RC_COMPILE}
    ARGS
        --generate-source
        --target=${CMAKE_CURRENT_BINARY_DIR}/${GRC_C}
        Test.gresource.xml
    VERBATIM
    MAIN_DEPENDENCY Test.gresource.xml
)
add_custom_target(
    XML_RC DEPENDS
    ${CMAKE_CURRENT_BINARY_DIR}/${GRC_H}
    ${CMAKE_CURRENT_BINARY_DIR}/${GRC_C}
)

# grc.h 和 grc.c 需要使用 gio-2.0
# 这里通过 pkg-config 使用 库gio-2.0
find_package(PkgConfig REQUIRED)
pkg_check_modules(GIO2 REQUIRED gio-2.0)

add_executable(test main.cpp ${CMAKE_CURRENT_BINARY_DIR}/${GRC_C})
target_include_directories(
    test PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${GIO2_INCLUDE_DIRS}
)

target_link_libraries(test PRIVATE ${GIO2_LDFLAGS})

# 上面定义 目标XML_RC 就是为了这里建立依赖关系
add_dependencies(test XML_RC)

install(TARGETS test DESTINATION .)