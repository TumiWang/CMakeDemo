// 文件 src/win_main.cpp

#include <windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return MessageBox(NULL, "我是C++幻想", "demo27", MB_OK | MB_ICONINFORMATION);
}