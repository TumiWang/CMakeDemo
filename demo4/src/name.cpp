// 文件 src/name.cpp

#include <string>

// 添加下面这段
// 含义是，如果定义了宏 CPP_FANTASY_CHINESE
// 则 取消这个宏的定义 -- 相当于未定义
#ifdef CPP_FANTASY_CHINESE
#undef CPP_FANTASY_CHINESE
#endif

std::string GetName() {
#ifdef CPP_FANTASY_CHINESE
    return "C++幻想";
#else 
    return "c++ fantasy";
#endif
}