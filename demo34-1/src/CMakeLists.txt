# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.16)

project(demo34-1)

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
install(TARGETS fibonacci 
    EXPORT FibonacciConfig
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    INCLUDES DESTINATION include)

# 安装头文件
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/fibonacci.h TYPE INCLUDE)

# 安装cmake配置
install(
    EXPORT FibonacciConfig
    FILE FibonacciConfig.cmake
    DESTINATION lib/cmake/Fibonacci-${FibonacciVersion}
)


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

# set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)

# Linux DEB

# deb 安装包的依赖
# 设置 CPACK_DEBIAN_PACKAGE_DEPENDS 例如
# set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.3.1-6), libc (< 2.4)")
# list(APPEND CPACK_DEBIAN_PACKAGE_DEPENDS cmake)
# 同
# set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6 (>= 2.3.1-6), libc (< 2.4);cmake")


# Windows NSIS
# 需要nsis
# Windows 上安装方法 winget install NSIS.NSIS
set(CPACK_NSIS_DISPLAY_NAME "Fibonacci库")

# 默认安装目录
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")

# 不允许修改安装目录
set(CPACK_NSIS_MODIFY_PATH OFF)

# 安装程序图标
set(CPACK_NSIS_MUI_ICON "${CMAKE_CURRENT_SOURCE_DIR}/win_nsis/install.ico")

# 卸载程序图标
set(CPACK_NSIS_MUI_UNICON "${CMAKE_CURRENT_SOURCE_DIR}/win_nsis/install.ico")

# 安装时执行安装目录的 init.bat
# set(CPACK_NSIS_EXTRA_INSTALL "ExecWait $INSTDIR/init.bat")

# 卸载时执行安装目录的 uninit.bat
# set(CPACK_NSIS_EXTRA_UNINSTALL "ExecWait $INSTDIR/uninit.bat")


# MacOS Bundle 
set(CPACK_BUNDLE_NAME "Fibonacci Library")
set(CPACK_BUNDLE_ICON "${CMAKE_CURRENT_SOURCE_DIR}/mac_bundle/AppIcon.icns")
set(CPACK_BUNDLE_PLIST "${CMAKE_CURRENT_SOURCE_DIR}/mac_bundle/Info.plist")
# set(CPACK_BUNDLE_STARTUP_COMMAND "${CMAKE_CURRENT_SOURCE_DIR}/mac_bundle/StartupCommand")

include(CPack)