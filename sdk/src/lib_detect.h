#ifndef __LIB_DETECT_H_
#define __LIB_DETECT_H_

#include "dir_detect.h"
#include "tar_file.h"

class LibDetect: public DirDetect {
public:
    LibDetect(TarFile& tar_file, const std::string& dir_prefix, const std::string& dir);

protected:
    void OnDetectDir(const std::string& dir) override;
    void OnDetectLink(const std::string& link) override;
    void OnDetectFile(const std::string& file) override;

private:
    TarFile& tar_file_;
    std::string dir_prefix_;
    std::string cur_dir_;
};

#endif // __LIB_DETECT_H_