
#pragma once

#define WF_STATIC_BUILD
#define WF_DYNAMIC_BUILD

#if defined WF_STATIC_BUILD
#	define WF_API
#	define WF_CAPI extern "C"
#else
#	if defined _WF_API
#		define WF_API __declspec(dllexport)
#		define WF_CAPI extern "C" __declspec(dllexport)
#	else
#		define WF_API __declspec(dllimport)
#		define WF_CAPI extern "C" __declspec(dllimport)
#	endif
#endif

#define INITGUID
#include <Windows.h>
#include <mmsystem.h>
#include <tchar.h>
#include <shellapi.h>
#include <shobjidl.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <shlguid.h>
#include <TlHelp32.h>
#include <Psapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <Gdiplus.h>
#include <assert.h>
#include <memory.h>
#include <list>
#include <string>

#pragma comment(lib, "Gdiplus.lib")
#pragma comment(lib, "ws2_32.lib")
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "Kernel32.lib")
#pragma comment(lib, "Psapi.lib")
#pragma comment(lib, "Winmm.lib")
