:: 文件 rebuild.bat

:: 注意: 该文件有中文，需要使用GBK编码或兼容GBK的编码 (中文Windows系统)
:: 否则bat文件有问题
:: bat文件的另一个要求是行介绍标志为CRLF

@echo off

:: 进入当今脚本所在目录
CD /d %~dp0

:: 当前目录全路径
SET ROOT_DIR=%CD%

:: 设置三个变量 分别表示安装目录、编译目录和编译类型
SET PRUDOCT_DIR=product
SET BUILD_DIR=build
SET BUILD_TYPE=Release

:: VC_VERSION变量表示的是使用的VS版本
::SET VC_VERSION=Visual Studio 15 2017
SET VC_VERSION=Visual Studio 17 2022

:: Windows程序分为64位和32位, 使用下面变量表示
::SET ARCH_TYPE=x64
SET ARCH_TYPE=win32

:: 清除 编译目录
:: 如果之前编译过，这样就是重新编译
IF EXIST "%BUILD_DIR%" (
    RMDIR /s /q "%BUILD_DIR%"
)
:: 清理安装目录
IF EXIST "%PRUDOCT_DIR%" (
    RMDIR /s /q "%PRUDOCT_DIR%"
)

cmake -B "%BUILD_DIR%" -S . -G "%VC_VERSION%" -A %ARCH_TYPE% -DCMAKE_BUILD_TYPE=%BUILD_TYPE%
IF %ERRORLEVEL% neq 0 (
    echo cmake创建项目失败
    goto end
)

cmake --build "%BUILD_DIR%" --config %BUILD_TYPE%
IF %ERRORLEVEL% neq 0 (
    echo cmake编译失败
    goto end
)

cmake --install "%BUILD_DIR%" --config %BUILD_TYPE% --prefix "%ROOT_DIR%\\%PRUDOCT_DIR%"
IF %ERRORLEVEL% neq 0 (
    echo CMake安装失败
    goto end
)

:end