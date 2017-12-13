
#pragma once

#if defined UNICODE || defined _UNICODE
#	define DeleteFileRecurse DeleteFileRecurseW
#else
#	define DeleteFileRecurse DeleteFileRecurseA
#endif

extern void DeleteFileRecurseA(const char * szDirectory, const bool bDeleteDirectory);
extern void DeleteFileRecurseW(const wchar_t * szDirectory, const bool bDeleteDirectory);
