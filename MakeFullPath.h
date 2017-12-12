
#pragma once

#include "WFLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define MakeFullPath MakeFullPathW
#else
#	define MakeFullPath MakeFullPathA
#endif

extern char * MakeFullPathA(const char * pszPath, const char * pszFileName);
extern wchar_t * MakeFullPathW(const wchar_t * pszPath, const wchar_t * pszFileName);
extern void FreeFullPathA(const char * pszFullPath);
extern void FreeFullPathW(const wchar_t * pszFullPath);
