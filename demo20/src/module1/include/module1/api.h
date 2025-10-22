#ifndef __MODULE1_API_H__
#define __MODULE1_API_H__

#include "module1/export_decorated.h"

#ifdef __cplusplus
extern "C" {
#endif

MODULE1_EXPORT_DECORATED const char* GetName();

#ifdef __cplusplus
}
#endif

#endif // __MODULE1_API_H__