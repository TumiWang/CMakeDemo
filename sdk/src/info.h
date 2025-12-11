#ifndef __INFO_H_
#define __INFO_H_

#include <string>
#include <vector>

const std::string& GetArch();
bool MatchLibPrefix(const std::string& name);
bool MatchBlacklistPrefix(const std::string& name);

#endif // __INFO_H_