
#include "GetSystemDrive.h"
#include "WFLibConfig.h"

bool GetSystemDriveA(char * pszDrive, const unsigned int uSize)
{
	bool bRet = FALSE;
	char szSystemDir[MAX_PATH] = { 0 };

	if (NULL != pszDrive && 0 != uSize)
	{
		if (0 != GetSystemDirectoryA(szSystemDir, MAX_PATH))
		{
			szSystemDir[3] = 0;
			strcpy_s(pszDrive, uSize, szSystemDir);

			bRet = TRUE;
		}
	}

	return bRet;
}

bool GetSystemDriveW(wchar_t * pszDrive, const unsigned int uSize)
{
	bool bRet = FALSE;
	wchar_t szSystemDir[MAX_PATH] = { 0 };

	if (NULL != pszDrive && 0 != uSize)
	{
		if (0 != GetSystemDirectoryW(szSystemDir, MAX_PATH))
		{
			szSystemDir[3] = 0;
			wcscpy_s(pszDrive, uSize, szSystemDir);

			bRet = TRUE;
		}
	}

	return bRet;
}
