// 文件 info/info.cpp

#include "info.h"
#include "info_inner.h"

#include <sstream>
#include <thread>

namespace {
    std::thread::id init_thread_id_;
}

void InitModule() {
    init_thread_id_ = std::this_thread::get_id();
}

void DeinitModule() {
    // 因为在这个demo中，使用静态加载，所以卸载库不演示了
}

void getInitInfo(std::string& result) {
    // 这里注意 该函数是给外部模块使用的
    // 我们不确定外部使用时,是否有多线程并发问题
    // 但这里只有读取 变量init_thread_id_ 才有这个风险
    // 但我知道init_thread_id_ 变量的读取是安全的，所以这里就没有使用 std::mutex 等进行保护
    std::ostringstream os;
    os << init_thread_id_;
    result = os.str();
}