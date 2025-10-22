#ifndef __MODULE2_API_H__
#define __MODULE2_API_H__

#include "module2/export_decorated.h"

#ifdef __cplusplus
extern "C" {
#endif

MODULE2_EXPORT_DECORATED const char* GetName();

#ifdef __cplusplus
}
#endif

#endif // __MODULE2_API_H__