# 交叉编译
set(CMAKE_SYSTEM_NAME Darwin)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(TARGET_TRIPLE aarch64-apple-darwin)

# 指定使用Ninja
set(CMAKE_GENERATOR "Ninja" CACHE STRING "")

# 这是我本地环境 X86_64 ubuntu 需要的SDK的位置
set(CMAKE_SYSROOT /sdk/MacOSX26.1.sdk)

set(CMAKE_C_FLAGS_INIT "-fuse-ld=lld -Wno-unused-command-line-argument")
set(CMAKE_CXX_FLAGS_INIT "-fuse-ld=lld -Wno-c++11-narrowing  -Wno-unused-command-line-argument")

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_C_COMPILER_TARGET ${TARGET_TRIPLE})
set(CMAKE_CXX_COMPILER_TARGET ${TARGET_TRIPLE})

set(CMAKE_LINKER "ld.lld" CACHE STRING "")

# 下面两个是静态库需要的工具
set(CMAKE_AR "llvm-ar-18" CACHE STRING "")
set(CMAKE_RANLIB "llvm-ranlib-18" CACHE STRING "")

set(CMAKE_RC_COMPILER "llvm-rc-18" CACHE STRING "")

# 支持的最低的MacOS系统版本
set(CMAKE_OSX_DEPLOYMENT_TARGET "11.0" CACHE STRING "")

# 下面通常不需要设置
add_compile_definitions(__APPLE__)
set(APPLE ON CACHE BOOL "")