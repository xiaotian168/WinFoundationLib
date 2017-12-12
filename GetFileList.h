
#pragma once

#include "WFLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define GetFileList GetFileListW
#	define AppendStdStringBackslash AppendStdStringBackslashW
#else
#	define GetFileList GetFileListA
#	define AppendStdStringBackslash AppendStdStringBackslashA
#endif

/**
** @brief ��ȡָ��Ŀ¼�µ������ļ�
*/
extern bool GetFileListA(const char * pszPath, const char * pszFileExt, bool bSubDir, std::list<std::string> & FileList);
extern bool GetFileListW(const wchar_t * pszPath, const wchar_t * pszFileExt, bool bSubDir, std::list<std::wstring> & FileList);

/**
** @brief ���ַ���ĩβ���ָ���ַ�����������ڣ�
*/
extern void AppendStdStringBackslashA(std::string & strPath, const char cSlash = '\\');
extern void AppendStdStringBackslashW(std::wstring & strPath, const wchar_t cSlash = L'\\');
