#include "module3/api.h"

#include "module2/api.h"

#include <sstream>

std::string GetInfo()
{
    std::ostringstream os;
    os << "Module3封装: " << GetName();
    return os.str();
}