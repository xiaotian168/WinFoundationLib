
#pragma once

#ifdef _UNICODE
#define BuildDirectoryPath BuildDirectoryPathW
#else
#define BuildDirectoryPath BuildDirectoryPathA
#endif

//-------------------------------------------------------------------------------
// @brif ����������Ŀ¼�� 
//-------------------------------------------------------------------------------

extern bool BuildDirectoryPathA(const char * szPath);
extern bool BuildDirectoryPathW(const wchar_t * szPath);
