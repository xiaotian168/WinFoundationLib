
#include "RunAppWait.h"

bool RunAppWaitA(const char * szApp, const char * szCmdLine, const unsigned int uShowFlag, const unsigned int uWaitTimeOut)
{
	bool bRet = false;
	DWORD dwWaitRet = 0;
	SHELLEXECUTEINFOA SEI = { 0 };

	if (NULL != szApp)
	{
		SEI.cbSize = sizeof(SEI);
		SEI.lpFile = szApp;
		SEI.lpParameters = szCmdLine;
		SEI.nShow = uShowFlag;
		SEI.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;

		if (ShellExecuteExA(&SEI))
		{
			dwWaitRet = WaitForSingleObject(SEI.hProcess, uWaitTimeOut);

			if (WAIT_OBJECT_0 == dwWaitRet || WAIT_TIMEOUT == dwWaitRet)
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool RunAppWaitW(const wchar_t * szApp, const wchar_t * szCmdLine, const unsigned int uShowFlag, const unsigned int uWaitTimeOut)
{
	bool bRet = false;
	DWORD dwWaitRet = 0;
	SHELLEXECUTEINFOW SEI = { 0 };

	if (NULL != szApp)
	{
		SEI.cbSize = sizeof(SEI);
		SEI.lpFile = szApp;
		SEI.lpParameters = szCmdLine;
		SEI.nShow = uShowFlag;
		SEI.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;

		if (ShellExecuteExW(&SEI))
		{
			dwWaitRet = WaitForSingleObject(SEI.hProcess, uWaitTimeOut);

			if (WAIT_OBJECT_0 == dwWaitRet || WAIT_TIMEOUT == dwWaitRet)
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool KillFullPathExeA(const char * szPath, const unsigned int uShowFlag, const unsigned int uWaitTimeOut)
{
	bool bRet = false;
	char * pszPathTemp = NULL;
	char szCmdLine[MAX_PATH] = { 0 };
	char szFileName[MAX_PATH] = { 0 };
	char szFileExt[MAX_PATH] = { 0 };
	size_t nPathLen = 0;
	DWORD dwWaitRet = 0;
	SHELLEXECUTEINFOA SEI = { 0 };

	if (NULL != szPath)
	{
		nPathLen = strlen(szPath);

		if (0 != nPathLen)
		{
			pszPathTemp = new char[nPathLen + 1];

			if (NULL != pszPathTemp)
			{
				sprintf_s(pszPathTemp, nPathLen + 1, "%s\0", szPath);
				_splitpath_s(pszPathTemp, 0, 0, 0, 0, szFileName, _countof(szFileName), szFileExt, _countof(szFileExt));

				if (0 == strcmp(".exe", szFileExt))
				{
					sprintf_s(szCmdLine, MAX_PATH, "/f /im %s%s", szFileName, szFileExt);

					SEI.cbSize = sizeof(SEI);
					SEI.lpFile = "taskkill";
					SEI.lpParameters = szCmdLine;
					SEI.nShow = uShowFlag;
					SEI.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;

					if (ShellExecuteExA(&SEI))
					{
						dwWaitRet = WaitForSingleObject(SEI.hProcess, uWaitTimeOut);

						if (WAIT_OBJECT_0 == dwWaitRet || WAIT_TIMEOUT == dwWaitRet)
						{
							bRet = true;
						}
					}
				}

				delete[] pszPathTemp;
			}
		}
	}

	return bRet;
}

bool KillFullPathExeW(const wchar_t * szPath, const unsigned int uShowFlag, const unsigned int uWaitTimeOut)
{
	bool bRet = false;
	wchar_t * pszPathTemp = NULL;
	wchar_t szCmdLine[MAX_PATH] = { 0 };
	wchar_t szFileName[MAX_PATH] = { 0 };
	wchar_t szFileExt[MAX_PATH] = { 0 };
	size_t nPathLen = 0;
	DWORD dwWaitRet = 0;
	SHELLEXECUTEINFOW SEI = { 0 };

	if (NULL != szPath)
	{
		nPathLen = wcslen(szPath);

		if (0 != nPathLen)
		{
			pszPathTemp = new wchar_t[nPathLen + 1];

			if (NULL != pszPathTemp)
			{
				swprintf_s(pszPathTemp, nPathLen + 1, L"%s\0", szPath);
				_wsplitpath_s(pszPathTemp, 0, 0, 0, 0, szFileName, _countof(szFileName), szFileExt, _countof(szFileExt));

				if (0 == wcscmp(L".exe", szFileExt))
				{
					swprintf_s(szCmdLine, MAX_PATH, L"/f /im %s%s", szFileName, szFileExt);

					SEI.cbSize = sizeof(SEI);
					SEI.lpFile = L"taskkill";
					SEI.lpParameters = szCmdLine;
					SEI.nShow = uShowFlag;
					SEI.fMask = SEE_MASK_NOCLOSEPROCESS | SEE_MASK_FLAG_NO_UI;

					if (ShellExecuteExW(&SEI))
					{
						dwWaitRet = WaitForSingleObject(SEI.hProcess, uWaitTimeOut);

						if (WAIT_OBJECT_0 == dwWaitRet || WAIT_TIMEOUT == dwWaitRet)
						{
							bRet = true;
						}
					}
				}

				delete[] pszPathTemp;
			}
		}
	}

	return bRet;
}
