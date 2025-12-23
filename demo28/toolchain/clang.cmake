# 指定使用Ninja
set(CMAKE_GENERATOR "Ninja" CACHE STRING "")

set(CMAKE_C_FLAGS_INIT "-fuse-ld=lld -Wno-unused-command-line-argument")
set(CMAKE_CXX_FLAGS_INIT "-fuse-ld=lld -Wno-c++11-narrowing  -Wno-unused-command-line-argument")

set(CMAKE_C_COMPILER clang-19)
set(CMAKE_CXX_COMPILER clang++-19)

set(CMAKE_AR "llvm-ar-19" CACHE STRING "")
set(CMAKE_RANLIB "llvm-ranlib-19" CACHE STRING "")