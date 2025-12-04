// 文件 src/resource/main.cpp

#include <CoreFoundation/CoreFoundation.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main(int argc, char* argv[])
{
    CFBundleRef br = CFBundleGetMainBundle();
    (void)br;
    
    std::string exe_name = argv[0];
    auto pos = exe_name.rfind('/');
    if (pos == std::string::npos) {
        std::cout << "不能判断程序路径" << std::endl;
        return 1;
    }

    std::string res_filename = exe_name.substr(0, pos);
    res_filename += "/Other/content.txt";
    
    std::ifstream fs(res_filename);
    if (!fs.is_open()) {
        std::cout << "资源文件打开失败" << std::endl;
        return 1;
    }

    std::string content;
    fs >> content;
    fs.close();

    std::cout << "资源文件内容为:" << std::endl;
    std::cout << content << std::endl;

    return 0;
}