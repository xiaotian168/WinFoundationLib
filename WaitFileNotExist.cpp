
#include "WaitFileNotExist.h"
#include "WFLibConfig.h"

bool WaitFileNotExistA(const char * pszFile, const unsigned int uTryCount, const unsigned int uTryElapse)
{
	bool bRet = false;
	unsigned int uTryedCount = 0;

	if (pszFile)
	{
		while (uTryedCount < uTryCount)
		{
			if (FALSE == PathFileExistsA(pszFile))
			{
				bRet = true;
				break;
			}

			++uTryedCount;
			Sleep(uTryElapse);
		}
	}

	return bRet;
}

bool WaitFileNotExistW(const wchar_t * pszFile, const unsigned int uTryCount, const unsigned int uTryElapse)
{
	bool bRet = false;
	unsigned int uTryedCount = 0;

	if (pszFile)
	{
		while (uTryedCount < uTryCount)
		{
			if (FALSE == PathFileExistsW(pszFile))
			{
				bRet = true;
				break;
			}

			++uTryedCount;
			Sleep(uTryElapse);
		}
	}

	return bRet;
}

bool DeleteFileAndWaitA(const char * pszFile, const unsigned int uTryCount /*= 0xFFFFFFFF*/, const unsigned int uTryElapse /*= 500*/)
{
	bool bRet = false;
	unsigned int uTryedCount = 0;

	if (pszFile)
	{
		while (uTryedCount < uTryCount)
		{
			DeleteFileA(pszFile);

			if (FALSE == PathFileExistsA(pszFile))
			{
				bRet = true;
				break;
			}

			++uTryedCount;
			Sleep(uTryElapse);
		}
	}

	return bRet;
}

bool DeleteFileAndWaitW(const wchar_t * pszFile, const unsigned int uTryCount /*= 0xFFFFFFFF*/, const unsigned int uTryElapse /*= 500*/)
{
	bool bRet = false;
	unsigned int uTryedCount = 0;

	if (pszFile)
	{
		while (uTryedCount < uTryCount)
		{
			DeleteFileW(pszFile);

			if (FALSE == PathFileExistsW(pszFile))
			{
				bRet = true;
				break;
			}

			++uTryedCount;
			Sleep(uTryElapse);
		}
	}

	return bRet;
}

bool RemoveFileReadOnlyAttrubiteA(const char * pszFile)
{
	bool bRet = false;
	DWORD dwFileAttribute = INVALID_FILE_ATTRIBUTES;

	if (pszFile)
	{
		dwFileAttribute = GetFileAttributesA(pszFile);

		if (INVALID_FILE_ATTRIBUTES != dwFileAttribute)
		{
			dwFileAttribute &= ~FILE_ATTRIBUTE_READONLY;

			if (SetFileAttributesA(pszFile, dwFileAttribute))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool RemoveFileReadOnlyAttrubiteW(const wchar_t * pszFile)
{
	bool bRet = false;
	DWORD dwFileAttribute = INVALID_FILE_ATTRIBUTES;

	if (pszFile)
	{
		dwFileAttribute = GetFileAttributesW(pszFile);

		if (INVALID_FILE_ATTRIBUTES != dwFileAttribute)
		{
			dwFileAttribute &= ~FILE_ATTRIBUTE_READONLY;

			if (SetFileAttributesW(pszFile, dwFileAttribute))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}
