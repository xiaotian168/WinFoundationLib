
#pragma once

#if defined UNICODE || defined _UNICODE
#define DeleteModuleDirectoryFile DeleteModuleDirectoryFileW
#else
#define DeleteModuleDirectoryFile DeleteModuleDirectoryFileA
#endif

//----------------------------------------------------------------------------------------------------------------------------------
// @brief ɾ��������ģ������Ŀ¼�µ�ָ���ļ�
//----------------------------------------------------------------------------------------------------------------------------------

extern bool DeleteModuleDirectoryFileA(const char * szFile);
extern bool DeleteModuleDirectoryFileW(const wchar_t * szFile);
