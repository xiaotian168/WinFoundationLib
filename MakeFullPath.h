
#pragma once

#include "WFLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define MakeFullPath MakeFullPathW
#else
#	define MakeFullPath MakeFullPathA
#endif

/**
** @brief 将指定路径和指定文件名拼接成一个完整的路径
*/
extern char * MakeFullPathA(const char * pszPath, const char * pszFileName);
extern wchar_t * MakeFullPathW(const wchar_t * pszPath, const wchar_t * pszFileName);

/**
** @brief 释放由 MakeFullPathA 函数和 MakeFullPathW 函数分配的内存
*/
extern void FreeFullPathA(const char * pszFullPath);
extern void FreeFullPathW(const wchar_t * pszFullPath);
