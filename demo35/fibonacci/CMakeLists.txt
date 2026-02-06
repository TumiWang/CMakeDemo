# 文件 src/CMakeLists.txt

# 虽然使用 preset 需要 3.25, 但是这个项目本身并不要求 3.25以上
# 所以，这里还是随便写了一个 3.16
cmake_minimum_required(VERSION 3.16)

project(demo35)

if(MSVC)
    add_compile_options(/utf-8)
endif()

# 版本号
set(FibonacciMajorVersion 1)
set(FibonacciMinorVersion 0)
set(FibonacciPatchVersion 1)

set(FibonacciVersion ${FibonacciMajorVersion}.${FibonacciMinorVersion}.${FibonacciPatchVersion})

add_library(fibonacci SHARED src/fibonacci.cpp)

set_target_properties(fibonacci PROPERTIES VERSION ${FibonacciMajorVersion}.${FibonacciMinorVersion}.${FibonacciPatchVersion})

# 这里和demo33-4 不同
# 该项目内使用时, 还是使用 #include "fibonacci.h"
# 安装 rpm 包的 使用 #include "fibonacci/fibonacci.h"
# 实际上，内部也应该使用 使用 #include "fibonacci/fibonacci.h"
# 但这样有修改cpp，这样就要列出修改后的源码，会导致文章内容太长了
target_include_directories(
    fibonacci
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/fibonacci>
    INTERFACE
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# 安装编译目标
install(TARGETS fibonacci 
    EXPORT FibonacciConfig
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include)

# 安装头文件
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/fibonacci TYPE INCLUDE)

# 安装cmake配置
install(
    EXPORT FibonacciConfig
    FILE FibonacciConfig.cmake
    DESTINATION lib/cmake/Fibonacci-${FibonacciVersion}
)

# 下面的test部分
include(CTest)

if(BUILD_TESTING)
    # 下面的两个 include 可以在顶层, 而且在复杂项目里通常会这样
    # 或者和 include(CTest) 在一起
    include(GoogleTest)
    include(FetchContent)

    # 编译 gtest
    set(BUILD_GMOCK OFF CACHE BOOL "")
    set(INSTALL_GTEST OFF CACHE BOOL "")
    FetchContent_Declare(
        gtest
        GIT_REPOSITORY https://gitee.com/spearNeil/googletest.git
        GIT_SHALLOW    ON
        GIT_TAG        v1.17.0
    )
    FetchContent_MakeAvailable(gtest)

    # increase_model.hpp 的测试
    # 可以认为是白盒测试
    add_executable(TestModel src/increase_model_test.cpp)
    target_link_libraries(TestModel PUBLIC gtest_main)
    gtest_discover_tests(TestModel)

    # 动态库 fibonacci 的测试
    # 可以认为是黑盒测试
    add_executable(TestFibonacci src/fibonacci_test.cpp)
    target_link_libraries(TestFibonacci PUBLIC gtest_main fibonacci)
    gtest_discover_tests(TestFibonacci)
endif()


# CPack 基础配置

# 包名称
set(CPACK_PACKAGE_NAME "Fibonacci")

# 安装许可
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/pack/InstallLicense.txt")

# 安装说明 -- 这个用的不多
set(CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/pack/InstallReadme.txt")

# 安装欢迎页 -- 这个用的也不多
set(CPACK_RESOURCE_FILE_WELCOME "${CMAKE_CURRENT_SOURCE_DIR}/pack/InstallWelcome.txt")

# 安装包的版本号 -- 这里使用的编译的版本号
set(CPACK_PACKAGE_VERSION_MAJOR "${FibonacciMajorVersion}")
set(CPACK_PACKAGE_VERSION_MINOR "${FibonacciMinorVersion}")
set(CPACK_PACKAGE_VERSION_PATCH "${FibonacciPatchVersion}")

# 开发商名称
set(CPACK_PACKAGE_VEDDOR "C++幻想")

# 开发商联系方式
set(CPACK_PACKAGE_CONTACT "mymail@test.com")

# 描述信息
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "计算菲波那契数列的动态库")
set(CPACK_PACKAGE_DESCRIPTION "计算菲波那契数列的动态库 这个是更详细的描述")


# Windows NSIS
set(CPACK_NSIS_DISPLAY_NAME "Fibonacci库")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_MODIFY_PATH OFF)
set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/pack/install.ico")
set(CPACK_NSIS_MUI_UNICON "${CMAKE_CURRENT_SOURCE_DIR}/pack/install.ico")

include(CPack)