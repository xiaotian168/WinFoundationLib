
#pragma once

#if defined UNICODE || defined _UNICODE
#define DeleteModuleDirectoryFile DeleteModuleDirectoryFileW
#else
#define DeleteModuleDirectoryFile DeleteModuleDirectoryFileA
#endif

//----------------------------------------------------------------------------------------------------------------------------------
// @brief 删除调用者模块所在目录下的指定文件
//----------------------------------------------------------------------------------------------------------------------------------

extern bool DeleteModuleDirectoryFileA(const char * szFile);
extern bool DeleteModuleDirectoryFileW(const wchar_t * szFile);
