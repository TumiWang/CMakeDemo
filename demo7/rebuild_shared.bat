:: 文件 rebuild.bat

:: 注意: 该文件有中文，需要使用GBK编码或兼容GBK的编码 (中文Windows系统)
:: 否则bat文件有问题
:: bat文件的另一个要求是行介绍标志为CRLF

@echo off

:: 进入当今脚本所在目录
CD /d %~dp0

:: 设置两个变量 分别表示编译目录和编译类型
SET BUILD_DIR=build
SET BUILD_TYPE=Release

:: VC_VERSION变量表示的是使用的VS版本
::SET VC_VERSION=Visual Studio 15 2017
SET VC_VERSION=Visual Studio 17 2022

:: Windows程序分为64位和32位, 使用下面变量表示
SET ARCH_TYPE=x64
::SET ARCH_TYPE=win32

:: 清除 编译目录
:: 如果之前编译过，这样就是重新编译
IF EXIST "%BUILD_DIR%" (
    RMDIR /s /q "%BUILD_DIR%"
)

:: 和之前的 rebuild.bat 脚本相比 差别就是下面这句 多了 -DBUILD_SHARED_LIBS=ON
:: 当然没有这句 BUILD_SHARED_LIBS会使用默认值，也是ON
:: 也就是说，使用之前的脚本 rebuild.bat 也是编译动态库
cmake -B "%BUILD_DIR%" -S src -G "%VC_VERSION%" -A %ARCH_TYPE% -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DBUILD_SHARED_LIBS=ON
IF %ERRORLEVEL% neq 0 (
    echo cmake创建项目失败
    goto end
)

cmake --build "%BUILD_DIR%" --config %BUILD_TYPE%
IF %ERRORLEVEL% neq 0 (
    echo cmake编译失败
    goto end
)