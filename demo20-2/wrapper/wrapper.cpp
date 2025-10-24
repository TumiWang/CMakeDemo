// 文件 wrapper/wrapper.cpp

#include "wrapper.h"

#include "info.h"

#include <sstream>

std::string GetWrapperInfo()
{
    std::ostringstream os;
    os << "这里是 ---- " << GetName();
    return os.str();
}