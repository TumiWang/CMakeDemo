// 文件 src/win_main.cpp

#include "resource.h"

#include <windows.h>

#include <cstring>
#include <string>

// 从资源中获取
std::string GetContent() {
    std::string content;

    do {
        // 表示的是资源中的文件 mycontent.txt
        // 这个关联文件 resource.rc 中定义
        // MAKEINTRESOURCEA 是宏
        HRSRC hRes = ::FindResourceA(NULL, MAKEINTRESOURCEA(IDR_MYCONTENT), "TXT");
        if (hRes == NULL) break;

        DWORD dwSize = ::SizeofResource(NULL, hRes);
        if (dwSize == 0) break;

        HGLOBAL hGlobal = ::LoadResource(NULL, hRes);
        if (hGlobal == NULL) break;

        void* p = ::LockResource(hGlobal);
        if (p) {
            content.resize(dwSize + 1);
            memcpy((void*)content.c_str(), p, dwSize);
        }

        // UnlockResource 目前是没用的宏
        // 反倒会导致 定义的变量未使用的警告
        // UnlockResource(hGlobal);

        ::FreeResource(hGlobal);
    } while(false);

    return content;
}

// 使用Windows API 实现 utf8 到 utf16 的编码转换
std::wstring Utf8ToUtf16(const std::string& text) {
    std::wstring result;
    wchar_t* buffer = nullptr;

    do {
        if (text.empty()) break;

        int len = MultiByteToWideChar(CP_UTF8, 0, text.c_str(), text.size(), NULL, 0);
        if (len <= 0) break;

        buffer = new wchar_t[len];
        if (buffer == nullptr) break;

        MultiByteToWideChar(CP_UTF8, 0, text.c_str(), text.size(), buffer, len);

        result = std::wstring(buffer, len);
    } while(false);

    if (buffer) {
        delete[] buffer;
    }

    return result;
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    std::string utf8_content = GetContent();
    // MessageBoxA 参数的字符串编码为 ANSI
    // Windows的ANSI编码方式 和Windows的所在地区相关
    // 例如：在中国通常是GBK
    // 所以，这里把 utf8 转为 utf16
    // 然后，使用 MessageBoxW

    std::wstring utf16_content = Utf8ToUtf16(utf8_content);

    return MessageBoxW(NULL, utf16_content.c_str(), L"demo27", MB_OK | MB_ICONINFORMATION);
}