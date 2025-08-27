#ifndef __INSERT_ALL_H_
#define __INSERT_ALL_H_

#include "dir_detect.h"
#include "tar_file.h"

class InsertAll: public DirDetect {
public:
    InsertAll(TarFile& tar_file, const std::string& dir_prefix, const std::string& dir);

protected:
    void OnDetectDir(const std::string& dir) override;
    void OnDetectLink(const std::string& link) override;
    void OnDetectFile(const std::string& file) override;

private:
    TarFile& tar_file_;
    std::string dir_prefix_;
    std::string cur_dir_;
};

#endif // __INSERT_ALL_H_