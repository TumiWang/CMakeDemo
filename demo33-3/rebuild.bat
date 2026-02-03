:: GB3212 CRLF

@echo off

:: 进入当今脚本所在目录
CD /d %~dp0

SET BUILD_DIR=build

cmake -S src -B %BUILD_DIR% -DCMAKE_BUILD_TYPE=Release
cmake --build %BUILD_DIR%
ctest --test-dir %BUILD_DIR%