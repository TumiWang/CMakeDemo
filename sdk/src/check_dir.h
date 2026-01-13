#ifndef __CHECK_DIR_H_
#define __CHECK_DIR_H_

#include "dir_detect.h"

#include <functional>

class CheckDir: public DirDetect {
public:
    CheckDir(const std::string& dir,
        std::function<void(const std::string&)> on_res,
        std::function<void(const std::string&)> on_lib,
        std::function<void(const std::string&)> on_link);

protected:
    void OnDetectDir(const std::string& dir) override;
    void OnDetectLink(const std::string& link) override;
    void OnDetectFile(const std::string& file) override;

private:
    std::function<void(const std::string&)> on_res_;
    std::function<void(const std::string&)> on_lib_;
    std::function<void(const std::string&)> on_link_;
};

#endif // __CHECK_DIR_H_