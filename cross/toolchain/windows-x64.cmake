# 交叉编译
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_PROCESSOR x86_64)
set(TARGET_TRIPLE x86_64-pc-win32)

# 指定使用Ninja
set(CMAKE_GENERATOR "Ninja" CACHE STRING "")

# 这是我本地环境 windows 需要的SDK的位置
set(CMAKE_SYSROOT /sdk/winsdk)

set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} -fuse-ld=lld")
set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} -Wno-unused-command-line-argument")
set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} -L\"/sdk/winsdk/windows kits/10/lib/10.0.22621.0/um/x64\"")
set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} -L\"/sdk/winsdk/windows kits/10/lib/10.0.22621.0/ucrt/x64\"")
set(CMAKE_C_FLAGS_INIT "${CMAKE_C_FLAGS_INIT} -L\"/sdk/winsdk/vc/tools/msvc/14.16.27023/lib/onecore/x64\"")

set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -fuse-ld=lld")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -Wno-unused-command-line-argument")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -Wno-c++11-narrowing")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -L\"/sdk/winsdk/windows kits/10/lib/10.0.22621.0/um/x64\"")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -L\"/sdk/winsdk/windows kits/10/lib/10.0.22621.0/ucrt/x64\"")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -L\"/sdk/winsdk/vc/tools/msvc/14.16.27023/lib/onecore/x64\"")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -I\"/sdk/winsdk/windows kits/10/include/10.0.22621.0/ucrt\"")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -I\"/sdk/winsdk/windows kits/10/bin/x64/include\"")


set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_C_COMPILER_TARGET ${TARGET_TRIPLE})
set(CMAKE_CXX_COMPILER_TARGET ${TARGET_TRIPLE})

set(CMAKE_LINKER "ld.lld" CACHE STRING "")

# 静态库需要的工具
set(CMAKE_AR "llvm-ar-18" CACHE STRING "")
set(CMAKE_RANLIB "llvm-ranlib-18" CACHE STRING "")

# 资源编译工具
set(CMAKE_RC_COMPILER "llvm-rc-18" CACHE STRING "")

# 下面通常不需要设置
add_compile_definitions(__WIN32__)
set(WIN32 ON CACHE BOOL "")