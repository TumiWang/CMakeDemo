// 文件 src/main.cpp

#include <iostream>

#include <sstream>
#include <string>


std::string GetContent() {
    // 这里使用流来接受 TEST_CONTENT宏 的内容
    // 这是因为我们不能确定其内容的类型
    // 例如
    // #define TEST_CONTENT "Text"
    // #define TEST_CONTENT 123
    // #define TEST_CONTENT 1.1f
    std::ostringstream os;
#ifdef TEST_CONTENT
    os << "[" << TEST_CONTENT << "]";
#else 
    os << "未定义宏TEST_CONTENT";
#endif
    return os.str();
}

int main(int argc, char* argv[]) {
    std::cout << "Content: " << GetContent() << std::endl;
    return 0;
}