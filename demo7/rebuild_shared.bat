:: �ļ� rebuild.bat

:: ע��: ���ļ������ģ���Ҫʹ��GBK��������GBK�ı��� (����Windowsϵͳ)
:: ����bat�ļ�������
:: bat�ļ�����һ��Ҫ�����н��ܱ�־ΪCRLF

@echo off

:: ���뵱��ű�����Ŀ¼
CD /d %~dp0

:: ������������ �ֱ��ʾ����Ŀ¼�ͱ�������
SET BUILD_DIR=build
SET BUILD_TYPE=Release

:: VC_VERSION������ʾ����ʹ�õ�VS�汾
::SET VC_VERSION=Visual Studio 15 2017
SET VC_VERSION=Visual Studio 17 2022

:: Windows�����Ϊ64λ��32λ, ʹ�����������ʾ
SET ARCH_TYPE=x64
::SET ARCH_TYPE=win32

:: ��� ����Ŀ¼
:: ���֮ǰ������������������±���
IF EXIST "%BUILD_DIR%" (
    RMDIR /s /q "%BUILD_DIR%"
)

:: ��֮ǰ�� rebuild.bat �ű���� ������������� ���� -DBUILD_SHARED_LIBS=ON
:: ��Ȼû����� BUILD_SHARED_LIBS��ʹ��Ĭ��ֵ��Ҳ��ON
:: Ҳ����˵��ʹ��֮ǰ�Ľű� rebuild.bat Ҳ�Ǳ��붯̬��
cmake -B "%BUILD_DIR%" -S src -G "%VC_VERSION%" -A %ARCH_TYPE% -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -DBUILD_SHARED_LIBS=ON
IF %ERRORLEVEL% neq 0 (
    echo cmake������Ŀʧ��
    goto end
)

cmake --build "%BUILD_DIR%" --config %BUILD_TYPE%
IF %ERRORLEVEL% neq 0 (
    echo cmake����ʧ��
    goto end
)