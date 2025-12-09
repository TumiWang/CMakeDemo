// 文件 src/win_main.cpp

#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    // 注意：
    // MessageBox(NULL, "我是C++幻想", "demo27", MB_OK | MB_ICONINFORMATION);
    // 的中文大概率会是乱码
    // 这是因为上面的编码方式是UTF-8
    // 而上面的API要求的是 多字节编码
    // 实际上 多字节编码不是一种编码方式，在Windows平台，通常是指所在地区的编码方式
    // 国内的通常是GBK编码 更多介绍看我之前关于编码的介绍吧
    return MessageBoxW(NULL, L"我是C++幻想", L"demo27", MB_OK | MB_ICONINFORMATION);
}