:: GB2312 CRLF
@echo off

CD /d %~dp0

IF EXIST build (
    RMDIR /s /q build
)

IF EXIST product (
    RMDIR /s /q product
)

CD fibonacci

:: cmake --workflow --list-presets

:: Windows VS2017 32λ
cmake --workflow --preset vs2017

:: Windows VS2022 32λ
:: cmake --workflow --preset vs2022
