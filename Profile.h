
#pragma once

#if defined ENABLE_PROFILE

#ifndef BEGIN_PROFILE_W
#define BEGIN_PROFILE_W(_ProfileName) { \
	const wchar_t * pszProfileName = _ProfileName; \
	wchar_t szMessage[MAX_PATH] = { 0 }; \
	LARGE_INTEGER liTickFrequency = { 0 }; \
	LARGE_INTEGER liTickPrev = { 0 }; \
	LARGE_INTEGER liTickNow = { 0 }; \
	LARGE_INTEGER liTickElapse = { 0 }; \
	QueryPerformanceFrequency(&liTickFrequency); \
	QueryPerformanceCounter(&liTickPrev);
#endif

#ifndef END_PROFILE
#define END_PROFILE \
	QueryPerformanceCounter(&liTickNow); \
	liTickElapse.QuadPart = liTickNow.QuadPart - liTickPrev.QuadPart; \
	swprintf_s(szMessage, MAX_PATH, L"Profile [%s] In [%lld] Tick [%f] Second \r\n", \
		pszProfileName, \
		liTickElapse.QuadPart, \
		(double)liTickElapse.QuadPart / (double)liTickFrequency.QuadPart); \
	OutputDebugStringW(szMessage); \
}
#endif

#else

#ifndef BEGIN_PROFILE_W
#define BEGIN_PROFILE_W(_ProfileName)
#endif

#ifndef END_PROFILE
#define END_PROFILE
#endif

#endif
