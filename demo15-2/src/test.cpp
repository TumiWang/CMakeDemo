#include <boost/locale.hpp>

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// 把内容转换为二进制
std::string GetBin(const std::string& text)
{
    std::ostringstream os;

    do {
        auto iter = text.begin();
        if (iter == text.end()) break;
        os << std::hex << std::setfill('0') ;
        os << std::setw(2) << +(static_cast<unsigned char>(*iter));
        for(++iter; iter != text.end(); ++iter) {
            os << ' ' << std::setw(2) << +(static_cast<unsigned char>(*iter));
        }
    } while (false);
    
    return os.str();
}

int main()
{
    std::string utf8 = "C++幻想";
    std::string gbk = boost::locale::conv::from_utf<char>(utf8, "GBK");

    std::cout << utf8 << " utf8: " << GetBin(utf8) << std::endl;
    std::cout << utf8 << " gbk: " << GetBin(gbk) << std::endl;

    return 0;
}