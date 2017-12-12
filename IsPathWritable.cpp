
#include "IsPathWritable.h"
#include "WFLibConfig.h"

static const char * g_szTempFileNameA = "{FEF8C65C-3390-43EC-AAB3-86533019355E}.tmp";
static const wchar_t * g_szTempFileNameW = L"{FEF8C65C-3390-43EC-AAB3-86533019355E}.tmp";

bool IsPathWriableA(const char * szPath)
{
	bool bRet = false;
	unsigned int uPathLen = 0;
	unsigned int uPathBuildLen = 0;
	char * pszPathBuild = 0;
	FILE * pFile = 0;

	if (0 != szPath && (0 != (uPathLen = strlen(szPath))))
	{
		// 尝试创建目录链

		uPathBuildLen = uPathLen + 1 + strlen(g_szTempFileNameA) + 1; // path + '\\' + tempfile + '\0'

		if (0 != (pszPathBuild = new char[uPathBuildLen]))
		{
			memset(pszPathBuild, 0, sizeof(char) * uPathBuildLen);

			for (unsigned int i = 0; i < uPathLen; ++i)
			{
				pszPathBuild[i] = szPath[i];

				if ('\\' == pszPathBuild[i] || '/' == pszPathBuild[i])
				{
					CreateDirectoryA(pszPathBuild, 0);
				}
			}

			strcat_s(pszPathBuild, uPathBuildLen, g_szTempFileNameA);

			if (0 == (fopen_s(&pFile, pszPathBuild, "wb")))
			{
				// 创建成功，该目录可写

				fclose(pFile);
				DeleteFileA(pszPathBuild);

				bRet = true;
			}

			delete[] pszPathBuild;
		}
	}

	return bRet;
}

bool IsPathWriableW(const wchar_t * szPath)
{
	bool bRet = false;
	unsigned int uPathLen = 0;
	unsigned int uPathBuildLen = 0;
	wchar_t * pszPathBuild = 0;
	FILE * pFile = 0;

	if (0 != szPath && (0 != (uPathLen = wcslen(szPath))))
	{
		uPathBuildLen = uPathLen + 1 + wcslen(g_szTempFileNameW) + 1;

		if (0 != (pszPathBuild = new wchar_t[uPathBuildLen]))
		{
			memset(pszPathBuild, 0, sizeof(wchar_t) * uPathBuildLen);

			for (unsigned int i = 0; i < uPathLen; ++i)
			{
				pszPathBuild[i] = szPath[i];

				if (L'\\' == pszPathBuild[i] || L'/' == pszPathBuild[i])
				{
					CreateDirectoryW(pszPathBuild, 0);
				}
			}

			wcscat_s(pszPathBuild, uPathBuildLen, g_szTempFileNameW);

			if (0 == (_wfopen_s(&pFile, pszPathBuild, L"wb")))
			{
				fclose(pFile);
				DeleteFileW(pszPathBuild);

				bRet = true;
			}

			delete[] pszPathBuild;
		}
	}

	return bRet;
}
