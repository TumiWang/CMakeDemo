// 文件 version/version.cpp

#include "version.h"

#ifndef __APPLE__

__attribute__((used,section(".version_info"))) const char build_version[] = VERSION_INFO;

#endif // __APPLE__