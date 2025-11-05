// 文件 include/export_decorated.h

#ifndef __EXPORT_DECORATED_H_
#define __EXPORT_DECORATED_H_

// linux下动态库 导出函数的修饰词
#if __has_attribute(visibility)
    #define EXPORT_DECORATED __attribute__((visibility("default")))
#else
    #define EXPORT_DECORATED
#endif

#endif // __EXPORT_DECORATED_H_