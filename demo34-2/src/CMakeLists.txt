# 文件 src/CMakeLists.txt

# c++ 源码 就是demo12-1

cmake_minimum_required(VERSION 3.16)

project(demo34)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/utf-8)
endif()

# 版本号
set(FibonacciMajorVersion 1)
set(FibonacciMinorVersion 0)
set(FibonacciPatchVersion 0)

set(FibonacciVersion ${FibonacciMajorVersion}.${FibonacciMinorVersion}.${FibonacciPatchVersion})

add_library(fibonacci SHARED fibonacci.cpp)
set_target_properties(fibonacci PROPERTIES VERSION ${FibonacciMajorVersion}.${FibonacciMinorVersion}.${FibonacciPatchVersion})

# 安装编译目标
# install(TARGETS fibonacci)
install(TARGETS fibonacci EXPORT FibonacciConfig COMPONENT libs)

# 安装头文件
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/fibonacci.h TYPE INCLUDE COMPONENT headers)

# 安装cmake配置
install(
    EXPORT FibonacciConfig
    FILE FibonacciConfig.cmake
    DESTINATION lib/cmake/Fibonacci-${FibonacciVersion}
    COMPONENT cmake_configs
)


# CPack 基础配置

# 包名称
set(CPACK_PACKAGE_NAME "FibonacciCalc")

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


include(CPack)

cpack_add_component(libs DISPLAY_NAME "菲波那契动态库组件")
cpack_add_component(headers DISPLAY_NAME "菲波那契库的头文件" DEPENDS libs)
cpack_add_component(cmake_configs DISPLAY_NAME "菲波那契动态库的cmake配置" DEPENDS headers)