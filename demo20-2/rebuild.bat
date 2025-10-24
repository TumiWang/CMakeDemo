:: �ļ� rebuild.bat

:: ע��: ���ļ������ģ���Ҫʹ��GBK��������GBK�ı��� (����Windowsϵͳ)
:: ����bat�ļ�������
:: bat�ļ�����һ��Ҫ�����н��ܱ�־ΪCRLF

@echo off

:: ���뵱��ű�����Ŀ¼
CD /d %~dp0

:: ��ǰĿ¼ȫ·��
SET ROOT_DIR=%CD%

:: ������������ �ֱ��ʾ��װĿ¼������Ŀ¼�ͱ�������
SET PRUDOCT_DIR=product
SET BUILD_DIR=build
SET BUILD_TYPE=Release

:: VC_VERSION������ʾ����ʹ�õ�VS�汾
::SET VC_VERSION=Visual Studio 15 2017
SET VC_VERSION=Visual Studio 17 2022

:: Windows�����Ϊ64λ��32λ, ʹ�����������ʾ
::SET ARCH_TYPE=x64
SET ARCH_TYPE=win32

:: ��� ����Ŀ¼
:: ���֮ǰ������������������±���
IF EXIST "%BUILD_DIR%" (
    RMDIR /s /q "%BUILD_DIR%"
)
:: ����װĿ¼
IF EXIST "%PRUDOCT_DIR%" (
    RMDIR /s /q "%PRUDOCT_DIR%"
)

cmake -B "%BUILD_DIR%" -S . -G "%VC_VERSION%" -A %ARCH_TYPE% -DCMAKE_BUILD_TYPE=%BUILD_TYPE%
IF %ERRORLEVEL% neq 0 (
    echo cmake������Ŀʧ��
    goto end
)

cmake --build "%BUILD_DIR%" --config %BUILD_TYPE%
IF %ERRORLEVEL% neq 0 (
    echo cmake����ʧ��
    goto end
)

cmake --install "%BUILD_DIR%" --config %BUILD_TYPE% --prefix "%ROOT_DIR%\\%PRUDOCT_DIR%"
IF %ERRORLEVEL% neq 0 (
    echo CMake��װʧ��
    goto end
)

:end