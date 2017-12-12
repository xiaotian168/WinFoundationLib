
#include "WindowMessageFilter.h"

typedef WINUSERAPI BOOL (WINAPI * WMF_ChangeWindowMessageFilterEx)(
	__in HWND hwnd,
	__in UINT message,
	__in DWORD action,
	__inout_opt PCHANGEFILTERSTRUCT pChangeFilterStruct);

static HMODULE g_hDLLUser32 = 0;
static WMF_ChangeWindowMessageFilterEx g_pfnChangeWindowsMessageFilterEx = NULL;

bool AddWindowMessageFilter(const HWND hWnd, const unsigned int uMsg)
{
	bool bRet = false;

	if (IsWindow(hWnd))
	{
		if (!g_hDLLUser32)
		{
			g_hDLLUser32 = LoadLibraryW(L"user32.dll");
		}

		if (g_hDLLUser32)
		{
			g_pfnChangeWindowsMessageFilterEx = (WMF_ChangeWindowMessageFilterEx)GetProcAddress(
				g_hDLLUser32,
				"ChangeWindowMessageFilterEx");
		}

		if (g_pfnChangeWindowsMessageFilterEx)
		{
			if (g_pfnChangeWindowsMessageFilterEx(hWnd, uMsg, 1, NULL))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool RemoveWindowMessageFilter(const HWND hWnd, const unsigned int uMsg)
{
	bool bRet = false;

	if (IsWindow(hWnd))
	{
		if (!g_hDLLUser32)
		{
			g_hDLLUser32 = LoadLibraryW(L"user32.dll");
		}

		if (g_hDLLUser32)
		{
			g_pfnChangeWindowsMessageFilterEx = (WMF_ChangeWindowMessageFilterEx)GetProcAddress(
				g_hDLLUser32,
				"ChangeWindowMessageFilterEx");
		}

		if (g_pfnChangeWindowsMessageFilterEx)
		{
			if (g_pfnChangeWindowsMessageFilterEx(hWnd, uMsg, 2, NULL))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}
