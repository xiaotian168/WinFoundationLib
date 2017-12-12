
#include "MakeFullPath.h"

char * MakeFullPathA(const char * pszPath, const char * pszFileName)
{
	size_t nPathLen = 0;
	size_t nFileNameLen = 0;
	size_t uFullPathLen = 0;
	char * pszFullPath = 0;

	if (pszPath && pszFileName)
	{
		nPathLen = strlen(pszPath);
		nFileNameLen = strlen(pszFileName);

		if (nPathLen && nFileNameLen)
		{
			uFullPathLen = nPathLen + nFileNameLen + 2;

			pszFullPath = new char[uFullPathLen];
			if (pszFullPath)
			{
				strcpy_s(pszFullPath, uFullPathLen, pszPath);

				if ('\\' != pszFullPath[nPathLen - 1] && '/' != pszFullPath[nPathLen - 1])
				{
					pszFullPath[nPathLen] = '\\';
					pszFullPath[nPathLen + 1] = '\0';
				}

				strcat_s(pszFullPath, uFullPathLen, pszFileName);
				pszFullPath[uFullPathLen - 1] = '\0';
			}
		}
	}

	return pszFullPath;
}

wchar_t * MakeFullPathW(const wchar_t * pszPath, const wchar_t * pszFileName)
{
	size_t nPathLen = 0;
	size_t nFileNameLen = 0;
	size_t uFullPathLen = 0;
	wchar_t * pszFullPath = 0;

	if (pszPath && pszFileName)
	{
		nPathLen = wcslen(pszPath);
		nFileNameLen = wcslen(pszFileName);

		if (nPathLen && nFileNameLen)
		{
			uFullPathLen = nPathLen + nFileNameLen + 2;

			pszFullPath = new wchar_t[uFullPathLen];
			if (pszFullPath)
			{
				wcscpy_s(pszFullPath, uFullPathLen, pszPath);

				if (L'\\' != pszFullPath[nPathLen - 1] && L'/' != pszFullPath[nPathLen - 1])
				{
					pszFullPath[nPathLen] = L'\\';
					pszFullPath[nPathLen + 1] = L'\0';
				}

				wcscat_s(pszFullPath, uFullPathLen, pszFileName);
				pszFullPath[uFullPathLen - 1] = L'\0';
			}
		}
	}

	return pszFullPath;
}

void FreeFullPathA(const char * pszFullPath)
{
	if (pszFullPath)
	{
		delete[] pszFullPath;
	}
}

void FreeFullPathW(const wchar_t * pszFullPath)
{
	if (pszFullPath)
	{
		delete[] pszFullPath;
	}
}
