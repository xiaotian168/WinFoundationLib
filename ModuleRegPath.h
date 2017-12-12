
#pragma once

#include "WFLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define WriteModulePathToReg WriteModulePathToRegW
#	define ReadModulePathFromReg ReadModulePathFromRegW
#else
#	define WriteModulePathToReg WriteModulePathToRegA
#	define ReadModulePathFromReg ReadModulePathFromRegA
#endif

//------------------------------------------------------------------------------------------------------------------------------
// @brief 将调用者模块文件路径写入到注册表指定位置
//------------------------------------------------------------------------------------------------------------------------------

extern bool WriteModulePathToRegA(const HKEY hKeyRoot, const char * szSubKey, const char * szValueName);
extern bool WriteModulePathToRegW(const HKEY hKeyRoot, const wchar_t * szSubKey, const wchar_t * szValueName);

//------------------------------------------------------------------------------------------------------------------------------
// @brief 从注册表指定路径读取模块文件路径，并判断改路径指向的模块文件是否存在
//------------------------------------------------------------------------------------------------------------------------------

extern bool ReadModulePathFromRegA(const HKEY hKeyRoot, const char * szSubKey, const char * szValueName, char * szModulePath, const DWORD dwSize);
extern bool ReadModulePathFromRegW(const HKEY hKeyRoot, const wchar_t * szSubKey, const wchar_t * szValueName, wchar_t * szModulePath, const DWORD dwSize);
