# 文件 src/CMakeLists.txt

cmake_minimum_required(VERSION 3.21)

project(demo30)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CheckCXXSourceCompiles)
check_cxx_source_compiles(
# 检查下面代码是否可以编译通过
# 结果放在变量 COMPLETED_STDLIBCXX 中
"
#include <thread>
int main() { 
    int i = 0;
    std::thread t([&] {++i;});
}
" 
COMPLETED_STDLIBCXX)

add_executable(test main.cpp)

if (NOT COMPLETED_STDLIBCXX)
    # 这里 简单的认为，COMPLETED_STDLIBCXX 为FALSE 时
    # 就是缺少 pthread 库
    target_link_libraries(test PRIVATE pthread)
endif()

install(TARGETS test DESTINATION .)