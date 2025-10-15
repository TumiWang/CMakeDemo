#include <iostream>

int main()
{
#ifdef CURRENT_TYPE
    std::cout << "宏CURRENT_TYPE -- " << CURRENT_TYPE << std::endl;
#else
    std::cout << "未定义宏 -- CURRENT_TYPE" << std::endl;
#endif
}