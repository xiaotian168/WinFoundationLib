
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
// @brief ��������ģ���ļ�·��д�뵽ע���ָ��λ��
//------------------------------------------------------------------------------------------------------------------------------

extern bool WriteModulePathToRegA(const HKEY hKeyRoot, const char * szSubKey, const char * szValueName);
extern bool WriteModulePathToRegW(const HKEY hKeyRoot, const wchar_t * szSubKey, const wchar_t * szValueName);

//------------------------------------------------------------------------------------------------------------------------------
// @brief ��ע���ָ��·����ȡģ���ļ�·�������жϸ�·��ָ���ģ���ļ��Ƿ����
//------------------------------------------------------------------------------------------------------------------------------

extern bool ReadModulePathFromRegA(const HKEY hKeyRoot, const char * szSubKey, const char * szValueName, char * szModulePath, const DWORD dwSize);
extern bool ReadModulePathFromRegW(const HKEY hKeyRoot, const wchar_t * szSubKey, const wchar_t * szValueName, wchar_t * szModulePath, const DWORD dwSize);
