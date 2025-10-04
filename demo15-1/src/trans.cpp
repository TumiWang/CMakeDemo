// 文件 src/trans.cpp

#include "trans.h"

// 因为 CMakeLists.txt 中
// target_link_libraries(trans PRIVATE Boost::locale)
// 确保找到正确的 boost/locale.hpp
#include <boost/locale.hpp>

#include <string>

int trans_gbk2utf8(const char* text, char* buff, int buff_len)
{
    std::string result = boost::locale::conv::to_utf<char>(text, "GBK");

    if (result.empty()) return 0;

    if (result.size() < buff_len) memcpy(buff, result.c_str(), result.size() + 1);
    return result.size() + 1;
}