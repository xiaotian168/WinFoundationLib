
#pragma once

#if defined UNICODE || defined _UNICODE
#	define DeleteCurrentUserDesktopFile DeleteCurrentUserDesktopFileW
#	define DeleteAllUserDesktopFile DeleteAllUserDesktopFileW
#else
#	define DeleteCurrentUserDesktopFile DeleteCurrentUserDesktopFileA
#	define DeleteAllUserDesktopFile DeleteAllUserDesktopFileA
#endif

extern bool DeleteCurrentUserDesktopFileA(const char * szFileName);
extern bool DeleteCurrentUserDesktopFileW(const wchar_t * szFileName);

extern bool DeleteAllUserDesktopFileA(const char * szFileName);
extern bool DeleteAllUserDesktopFileW(const wchar_t * szFileName);
