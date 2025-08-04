// 文件 src/info.cpp

#include "info.h"

#include "name.cpp"

std::string GetInfo() {
    std::string text("I am ");
    text += GetName();
    return text;
}