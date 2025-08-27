#ifndef __TAR_FILE_H_
#define __TAR_FILE_H_


#include <archive.h>

#include <string>
#include <unordered_set>

class TarFile {
public:
    TarFile(const std::string& filename, const std::string& path_prefix);
    virtual ~TarFile();

public:
    void AddDir(const std::string& dir);
    void AddFile(const std::string& filename);
    void AddLink(const std::string& link);

private:
    struct archive* tarfile_;
    std::string path_prefix_;

    std::unordered_set<std::string> dir_cache_;
};

#endif // __TAR_FILE_H_