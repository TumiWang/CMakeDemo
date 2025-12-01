# CMakeDemo

# 编译环境

Linux 使用 docker 运行 ubuntu

需要安装：
- build-essential
- cmake
- tree
- curl

# demo23序列图

```mermaid
sequenceDiagram
    participant T as 可执行程序 test
    participant M3 as 库 Module3
    participant M2 as 库 Module2
    participant M1 as 库 Module1
    T->>M1: 调用GetName
    activate M1
    M1-->>T: GetName返回
    deactivate M1
    T->>M3: 调用GetInfo
    activate M3
    M3->>M2: 调用GetName
    activate M2
    M2-->>M3: GetName返回
    deactivate M2
    M3-->>T: GetInfo返回
    deactivate M3
```

# demo25

使用 libc++ 静态库
```
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -static-libstdc++ -stdlib=libc++")
```

如果SDK抽取ubuntu 20.04 默认 libc++的版本是10
```
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -L${CMAKE_SYSROOT}/usr/lib/llvm-10/lib")
set(CMAKE_CXX_FLAGS_INIT "${CMAKE_CXX_FLAGS_INIT} -I${CMAKE_SYSROOT}/usr/lib/llvm-10/include/c++/v1")
```
# demo26

MacOS可以合并
```sh
llvm-lipo-18 -create ./product/macos-aarch64/test ./product/macos-x86_64/test -output ./product/test
```
# demo27

编译Windows时，docker 要提权运行，例如

```sh
docker run --rm -it --privileged -v /Users/tumi/source/github/CMakeDemo:/source clang18-cross-ubuntu24:aarch64 bash