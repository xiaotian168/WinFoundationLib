
#include "BuildTempFile.h"
#include "WFLibConfig.h"

bool BuildTempFilePathA(char * pszPath, const unsigned int uSize)
{
	bool bRet = FALSE;
	char szTempPath[MAX_PATH] = { 0 };

	if (NULL != pszPath && 0 != uSize)
	{
		if (0 != GetTempPathA(MAX_PATH, szTempPath))
		{
			PathAddBackslashA(szTempPath);

			sprintf_s(pszPath, uSize, "%s%d.tmp", szTempPath, GetTickCount());
			Sleep(1);

			bRet = TRUE;
		}
	}

	return bRet;
}

bool BuildTempFilePathW(wchar_t * pszPath, const unsigned int uSize)
{
	bool bRet = FALSE;
	wchar_t szTempPath[MAX_PATH] = { 0 };

	if (NULL != pszPath && 0 != uSize)
	{
		if (0 != GetTempPathW(MAX_PATH, szTempPath))
		{
			PathAddBackslashW(szTempPath);
			Sleep(1);

			swprintf_s(pszPath, uSize, L"%s%d.tmp", szTempPath, GetTickCount());

			bRet = TRUE;
		}
	}

	return bRet;
}
