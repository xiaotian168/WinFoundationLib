
#include "DeleteModuleDirectoryFile.h"
#include "WFLibConfig.h"

bool DeleteModuleDirectoryFileA(const char * szFile)
{
	bool bRet = false;
	char szModulePath[MAX_PATH] = { 0 };

	if (0 != szFile && 0 != ::GetModuleFileNameA(0, szModulePath, MAX_PATH))
	{
		for (size_t i = strlen(szModulePath) - 1; i >= 0; --i)
		{
			if ('\\' == szModulePath[i] || '/' == szModulePath[i])
			{
				szModulePath[i + 1] = 0;
				strcat_s(szModulePath, MAX_PATH, szFile);

				if (DeleteFileA(szModulePath))
				{
					bRet = true;
				}

				break;
			}
		}
	}

	return bRet;
}

bool DeleteModuleDirectoryFileW(const wchar_t * szFile)
{
	bool bRet = false;
	wchar_t szModulePath[MAX_PATH] = { 0 };

	if (0 != szFile && 0 != ::GetModuleFileNameW(0, szModulePath, MAX_PATH))
	{
		for (size_t i = wcslen(szModulePath) - 1; i >= 0; --i)
		{
			if (L'\\' == szModulePath[i] || L'/' == szModulePath[i])
			{
				szModulePath[i + 1] = 0;
				wcscat_s(szModulePath, MAX_PATH, szFile);

				if (DeleteFileW(szModulePath))
				{
					bRet = true;
				}

				break;
			}
		}
	}

	return bRet;
}
