
// #include "tar_file.h"
// #include "tar_link.h"

#include "check_dir.h"
#include "info.h"
#include "insert_all.h"
#include "lib_detect.h"
#include "tar_file.h"

#include <iostream>
#include <string>
#include <vector>

#include <unistd.h>
#include <limits.h>

enum class LibType {
    link,
    lib,
    header
};

struct ItemInfo {
    std::string filename;
    LibType type;
};

int main() {
    // std::vector<std::string> header_paths;
    // std::vector<std::string> lib_paths;
    // std::vector<std::string> link_paths;
    // auto header_cb = [&header_paths](const std::string& dir) {
    //     std::string temp = dir;
    //     if (!temp.empty() && temp[0] == '/') temp = temp.substr(1);
    //     header_paths.push_back(temp);
    // };
    // auto lib_cb = [&lib_paths](const std::string& dir) {
    //     std::string temp = dir;
    //     if (!temp.empty() && temp[0] == '/') temp = temp.substr(1);
    //     lib_paths.push_back(temp);
    // };
    // auto link_cb = [&link_paths](const std::string& link) {
    //     std::string temp = link;
    //     if (!temp.empty() && temp[0] == '/') temp = temp.substr(1);
    //     link_paths.push_back(temp);
    // };
    std::vector<ItemInfo> items;
    auto header_cb = [&items](const std::string& dir) {
        items.push_back({dir, LibType::header});
    };
    auto lib_cb = [&items](const std::string& dir) {
        items.push_back({dir, LibType::lib});
    };
    auto link_cb = [&items](const std::string& link) {
        items.push_back({link, LibType::link});
    };

    {
        CheckDir check("/", header_cb, lib_cb, link_cb);
        check.Detect();
    }

    {
        CheckDir check("/usr", header_cb, lib_cb, link_cb);
        check.Detect();
    }

    // std::cout << "头文件目录:" << std::endl;
    // for (const auto& item: header_paths) {
    //     std::cout << item << std::endl;
    // }
    // std::cout << std::endl;
    // std::cout << "库文件目录:" << std::endl;
    // for (const auto& item: lib_paths)
    //     std::cout << item << std::endl;
    // std::cout << std::endl;
    // std::cout << "链接文件:" << std::endl;
    // for (const auto& item: link_paths)
    //     std::cout << item << std::endl;

    std::string filename = "linux-sdk-";
    filename += GetArch();
    filename += ".tar";

    if (access(filename.c_str(), F_OK) == 0) {
        unlink(filename.c_str());
    }

    TarFile file(filename, "/");

    file.AddDir("usr");

    for (const auto& item: items) {
        switch (item.type)
        {
        case LibType::lib:
            if (item.filename.size() > 1 && item.filename[0] == '/') {
                LibDetect lib(file, "/", item.filename.substr(1));
                lib.Detect();
            }
            break;
        case LibType::link:
            file.AddLink(item.filename.substr(1));
            break;
        case LibType::header:
            if (item.filename.size() > 1 && item.filename[0] == '/') {
                InsertAll insert(file, "/", item.filename.substr(1));
                insert.Detect();
            }
            break;
        default:
            break;
        }
    }

    char cwd[PATH_MAX] = { 0 };
    if (getcwd(cwd, sizeof(cwd))) {
        std::string temp = cwd;
        filename = temp + "/" + filename;
    }


    std::cout << "提取SDK到文件: " << filename << std::endl;

    return 0;
}