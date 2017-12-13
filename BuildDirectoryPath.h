
#pragma once

#ifdef _UNICODE
#define BuildDirectoryPath BuildDirectoryPathW
#else
#define BuildDirectoryPath BuildDirectoryPathA
#endif

//-------------------------------------------------------------------------------
// @brif 创建完整的目录链 
//-------------------------------------------------------------------------------

extern bool BuildDirectoryPathA(const char * szPath);
extern bool BuildDirectoryPathW(const wchar_t * szPath);
