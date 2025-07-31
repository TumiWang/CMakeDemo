// 文件 src/name.cpp

#include <string>

std::string GetName() {
#ifdef CPP_FANTASY_CHINESE
    return "C++幻想";
#else 
    return "c++ fantasy";
#endif
}