// 文件 info/info_inner.h

#ifndef __INFO_INFO_INNER_H_
#define __INFO_INFO_INNER_H_

// 该动态库加载时，调用
void InitModule();

// 该动态库卸载时，调用
void DeinitModule();

#endif // __INFO_INFO_INNER_H_