#ifndef __DIR_DETECT_H_
#define __DIR_DETECT_H_

#include <string>

class DirDetect {
public:
    DirDetect(const std::string& dir);
    virtual ~DirDetect();

public:
    void Detect();

    virtual void OnDetectDir(const std::string& dir) = 0;
    virtual void OnDetectLink(const std::string& link) = 0;
    virtual void OnDetectFile(const std::string& file) = 0;

protected:
    const std::string dir_;
    std::string full_path_;
};

#endif // __DIR_DETECT_H_