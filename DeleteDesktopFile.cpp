
#include "DeleteDesktopFile.h"
#include "WFLibConfig.h"

bool DeleteCurrentUserDesktopFileA(const char * szFileName)
{
	bool bRet = false;
	char szDesktopDir[MAX_PATH] = { 0 };
	char szLinkPath[MAX_PATH] = { 0 };

	if (0 != szFileName && 0 != strlen(szFileName))
	{
		if (SHGetSpecialFolderPathA(NULL, szDesktopDir, CSIDL_DESKTOPDIRECTORY, FALSE))
		{
			PathAddBackslashA(szDesktopDir);
			sprintf_s(szLinkPath, MAX_PATH, "%s%s", szDesktopDir, szFileName);

			if (0 != DeleteFileA(szLinkPath))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool DeleteCurrentUserDesktopFileW(const wchar_t * szFileName)
{
	bool bRet = false;
	wchar_t szDesktopDir[MAX_PATH] = { 0 };
	wchar_t szLinkPath[MAX_PATH] = { 0 };

	if (0 != szFileName && 0 != wcslen(szFileName))
	{
		if (SHGetSpecialFolderPathW(NULL, szDesktopDir, CSIDL_DESKTOPDIRECTORY, FALSE))
		{
			PathAddBackslashW(szDesktopDir);
			swprintf_s(szLinkPath, MAX_PATH, L"%s%s", szDesktopDir, szFileName);

			if (0 != DeleteFileW(szLinkPath))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool DeleteAllUserDesktopFileA(const char * szFileName)
{
	bool bRet = false;
	char szDesktopDir[MAX_PATH] = { 0 };
	char szLinkPath[MAX_PATH] = { 0 };

	if (0 != szFileName && 0 != strlen(szFileName))
	{
		if (SHGetSpecialFolderPathA(NULL, szDesktopDir, CSIDL_COMMON_DESKTOPDIRECTORY, FALSE))
		{
			PathAddBackslashA(szDesktopDir);
			sprintf_s(szLinkPath, MAX_PATH, "%s%s", szDesktopDir, szFileName);

			if (0 != DeleteFileA(szLinkPath))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool DeleteAllUserDesktopFileW(const wchar_t * szFileName)
{
	bool bRet = false;
	wchar_t szDesktopDir[MAX_PATH] = { 0 };
	wchar_t szLinkPath[MAX_PATH] = { 0 };

	if (0 != szFileName && 0 != wcslen(szFileName))
	{
		if (SHGetSpecialFolderPathW(NULL, szDesktopDir, CSIDL_COMMON_DESKTOPDIRECTORY, FALSE))
		{
			PathAddBackslashW(szDesktopDir);
			swprintf_s(szLinkPath, MAX_PATH, L"%s%s", szDesktopDir, szFileName);

			if (0 != DeleteFileW(szLinkPath))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}
