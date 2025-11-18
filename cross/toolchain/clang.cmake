# 指定使用Ninja
set(CMAKE_GENERATOR "Ninja" CACHE STRING "")

set(CMAKE_C_FLAGS_INIT "-fuse-ld=lld -Wno-unused-command-line-argument")
set(CMAKE_CXX_FLAGS_INIT "-fuse-ld=lld -Wno-c++11-narrowing  -Wno-unused-command-line-argument")

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_AR "llvm-ar-18" CACHE STRING "")
set(CMAKE_RANLIB "llvm-ranlib-18" CACHE STRING "")