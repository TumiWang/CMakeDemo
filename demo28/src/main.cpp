// 文件 src/main.cpp

#ifdef __cplusplus
extern "C" {
#endif

#include "grc.h"

#ifdef __cplusplus
}
#endif

#include <iostream>
#include <string>

// 读取资源文件的内容
std::string GetContent()
{
    // Test_get_resource 函数是根据文件Test.gresource.xml生成的
    // 函数的前缀 Test 实际上就是那个文件的名称
    GResource* r = Test_get_resource();

    // 资源要先注册后，才能使用
    g_resources_register(r);

    // 这里的文件名称 /test/cxx/demo28/content.txt
    // 就是资源文件的名称 由 
    //   前缀 /test/cxx/demo28
    //   名称 content.txt
    // 组成
    // 看 Test.gresource.xml 的内容
    GBytes* buffer = g_resources_lookup_data("/test/cxx/demo28/content.txt", G_RESOURCE_LOOKUP_FLAGS_NONE, NULL);
    gsize size = 0;
    auto p = g_bytes_get_data(buffer, &size);
    std::string text((char*)p, size);

    // 释放 buffer
    g_bytes_unref(buffer);

    // g_resources_register 的逆操作
    g_resources_unregister(r);

    return text;
}

int main()
{
    std::string text = GetContent();
    std::cout << text << std::endl;
}