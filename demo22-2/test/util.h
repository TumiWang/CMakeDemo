// 文件 test/util.h

#ifndef __TEST_UTIL_H_
#define __TEST_UTIL_H_

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif // _WIN32

#include <string>

#ifndef _WIN32
using HMODULE = void*;
#endif // _WIN32

using GetInitInfo_Func_Type = void(*)(std::string&);

// 获取Info库文件的全路径名
// 传入参数是进程名 -- 可能是相对路径
std::string GetInfoFullPath(const char* processname);

// 加载库
HMODULE LoadInfoLib(const std::string& filename);

// 卸载库
void UnloadInfoLib(HMODULE module);

// 获取 Info 中 void getInitInfo(std::string& result) 函数的指针
GetInitInfo_Func_Type GetInfoFunc(HMODULE module);

#endif // __TEST_UTIL_H_