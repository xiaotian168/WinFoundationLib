
#pragma once

#if defined UNICODE || defined _UNICODE
#	define SetEventByName SetEventByNameW
#else
#	define SetEventByName SetEventByNameA
#endif

extern bool SetEventByNameW(const wchar_t * szEventName);
extern bool SetEventByNameA(const char * szEventName);
