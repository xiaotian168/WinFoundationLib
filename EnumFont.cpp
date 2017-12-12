
#include "EnumFont.h"
#include "WFLibConfig.h"

int CALLBACK CountFontProc(ENUMLOGFONTEX *lpelfe, NEWTEXTMETRICEX *lpntme, DWORD FontType, LPARAM lParam)
{
	int nRet = 1; // 返回非 0 值表示继续枚举，返回 0 值表示停止枚举
	unsigned int * puFontFamileCount = (unsigned int *)lParam;

	if (NULL != puFontFamileCount)
	{
		*puFontFamileCount += 1;
	}

	return nRet;
}

int CALLBACK MatchFontProcA(ENUMLOGFONTEXA *lpelfe, NEWTEXTMETRICEXA *lpntme, DWORD FontType, LPARAM lParam)
{
	int nRet = 1;
	const char * szFontFamilyName = (const char *)lParam;

	if (NULL != szFontFamilyName && NULL != lpelfe)
	{
		if (0 == strcmp(szFontFamilyName, lpelfe->elfLogFont.lfFaceName))
		{
			nRet = 0;
		}
	}

	return nRet;
}

int CALLBACK MatchFontProcW(ENUMLOGFONTEXW *lpelfe, NEWTEXTMETRICEXW *lpntme, DWORD FontType, LPARAM lParam)
{
	int nRet = 1;
	const wchar_t * szFontFamilyName = (const wchar_t *)lParam;

	if (NULL != szFontFamilyName && NULL != lpelfe)
	{
		if (0 == wcscmp(szFontFamilyName, lpelfe->elfLogFont.lfFaceName))
		{
			nRet = 0;
		}
	}

	return nRet;
}

bool EnumFontCount(unsigned int & uFontCount)
{
	bool bRet = FALSE;
	HWND hWndDesktop = NULL;
	HDC hDCDesktop = NULL;
	LOGFONT LogFont = { 0 };

	uFontCount = 0;

	if (NULL != (hWndDesktop = GetDesktopWindow()))
	{
		if (NULL != (hDCDesktop = GetDC(hWndDesktop)))
		{
			LogFont.lfCharSet = DEFAULT_CHARSET;

			EnumFontFamiliesEx(hDCDesktop, &LogFont, (FONTENUMPROC)CountFontProc, (LPARAM)&uFontCount, 0);

			ReleaseDC(hWndDesktop, hDCDesktop);

			bRet = TRUE;
		}
	}

	return bRet;
}

bool IsFontFamilyExistA(const char * szFontFamilyName)
{
	bool bRet = FALSE;
	HWND hWndDesktop = NULL;
	HDC hDCDesktop = NULL;
	LOGFONTA LogFont = { 0 };

	if (NULL != szFontFamilyName && 0 != strlen(szFontFamilyName))
	{
		if (NULL != (hWndDesktop = GetDesktopWindow()))
		{
			if (NULL != (hDCDesktop = GetDC(hWndDesktop)))
			{
				LogFont.lfCharSet = DEFAULT_CHARSET;

				if (0 == EnumFontFamiliesExA(hDCDesktop, &LogFont, (FONTENUMPROCA)MatchFontProcA, (LPARAM)szFontFamilyName, 0))
				{
					bRet = TRUE;
				}

				ReleaseDC(hWndDesktop, hDCDesktop);
			}
		}
	}

	return bRet;
}

bool IsFontFamilyExistW(const wchar_t * szFontFamilyName)
{
	bool bRet = FALSE;
	HWND hWndDesktop = NULL;
	HDC hDCDesktop = NULL;
	LOGFONTW LogFont = { 0 };

	if (NULL != szFontFamilyName && 0 != wcslen(szFontFamilyName))
	{
		if (NULL != (hWndDesktop = GetDesktopWindow()))
		{
			if (NULL != (hDCDesktop = GetDC(hWndDesktop)))
			{
				LogFont.lfCharSet = DEFAULT_CHARSET;

				if (0 == EnumFontFamiliesExW(hDCDesktop, &LogFont, (FONTENUMPROCW)MatchFontProcW, (LPARAM)szFontFamilyName, 0))
				{
					bRet = TRUE;
				}

				ReleaseDC(hWndDesktop, hDCDesktop);
			}
		}
	}

	return bRet;
}
