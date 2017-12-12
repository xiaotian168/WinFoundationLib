
#include "CreateShortcut.h"
#include "WFLibConfig.h"

bool CreateShortcutA(
	const char * szTargetPath,
	const char * szIconPath,
	const int nIconIndex,
	const char * szShortcutPath,
	const bool bRemember)
{
	bool bRet = false;
	IShellLinkA * pIShellLink = 0;
	IPersistFile * pIPersistFile = 0;
	wchar_t * pszShortcutPathW = 0;
	size_t uShortcutPathLen = 0;

	if (0 != szTargetPath && 0 != szShortcutPath)
	{
		if (SUCCEEDED(CoInitialize(0)))
		{
			if (SUCCEEDED(CoCreateInstance(
				CLSID_ShellLink,
				0,
				CLSCTX_INPROC_SERVER,
				IID_IShellLink,
				(void **)&pIShellLink)))
			{
				pIShellLink->SetPath(szTargetPath);

				if (0 != szIconPath && nIconIndex >= 0)
				{
					pIShellLink->SetIconLocation(szIconPath, nIconIndex);
				}

				if (SUCCEEDED(pIShellLink->QueryInterface(
					IID_IPersistFile,
					(void **)&pIPersistFile)))
				{
					if (0 != (uShortcutPathLen = strlen(szShortcutPath)) &&
						0 != (pszShortcutPathW = new wchar_t[uShortcutPathLen + 1]))
					{
						MultiByteToWideChar(
							CP_ACP,
							0,
							szShortcutPath,
							uShortcutPathLen,
							pszShortcutPathW,
							uShortcutPathLen + 1);

						pszShortcutPathW[uShortcutPathLen] = 0;

						if (SUCCEEDED(pIPersistFile->Save(pszShortcutPathW, bRemember)))
						{
							bRet = true;
						}

						delete[] pszShortcutPathW;
						pszShortcutPathW = 0;
					}

					pIPersistFile->Release();
					pIPersistFile = 0;
				}

				pIShellLink->Release();
				pIShellLink = 0;
			}

			CoUninitialize();
		}
	}

	return bRet;
}

bool CreateShortcutW(
	const wchar_t * szTargetPath,
	const wchar_t * szIconPath,
	const int nIconIndex,
	const wchar_t * szShortcutPath,
	const bool bRemember)
{
	bool bRet = false;
	IShellLinkW * pIShellLink = 0;
	IPersistFile * pIPersistFile = 0;

	if (0 != szTargetPath && 0 != szShortcutPath)
	{
		if (SUCCEEDED(CoInitialize(0)))
		{
			if (SUCCEEDED(CoCreateInstance(
				CLSID_ShellLink,
				0,
				CLSCTX_INPROC_SERVER,
				IID_IShellLink,
				(void **)&pIShellLink)))
			{
				pIShellLink->SetPath(szTargetPath);

				if (0 != szIconPath && nIconIndex >= 0)
				{
					pIShellLink->SetIconLocation(szIconPath, nIconIndex);
				}

				if (SUCCEEDED(pIShellLink->QueryInterface(
					IID_IPersistFile,
					(void **)&pIPersistFile)))
				{
					if (SUCCEEDED(pIPersistFile->Save(szShortcutPath, bRemember)))
					{
						bRet = true;
					}

					pIPersistFile->Release();
					pIPersistFile = 0;
				}

				pIShellLink->Release();
				pIShellLink = 0;
			}

			CoUninitialize();
		}
	}

	return bRet;
}

bool ReadShortcutInfoA(
	const char * szShortcutFile,
	char * szTargetPath,
	const unsigned int uTargetPathSize,
	char * szArgument,
	const unsigned int uArgumentSize,
	char * szIconPath,
	const unsigned int uIconPathSize)
{
	bool bRet = true;
	IShellLinkA * pIShellLink = 0;

	if (NULL != szShortcutFile)
	{
		if (SUCCEEDED(CoInitialize(0)))
		{
			if (SUCCEEDED(CoCreateInstance(
				CLSID_ShellLink,
				0,
				CLSCTX_INPROC_SERVER,
				IID_IShellLink,
				(void **)&pIShellLink)))
			{
				if (NULL != szTargetPath && 0 != uTargetPathSize)
				{
					if (FAILED(pIShellLink->GetPath(szTargetPath, uTargetPathSize, NULL, 0)))
					{
						bRet = false;
					}
				}

				if (NULL != szIconPath && 0 != uIconPathSize)
				{
					if (FAILED(pIShellLink->GetIconLocation(szIconPath, uIconPathSize, NULL)))
					{
						bRet = false;
					}
				}

				if (NULL != szArgument && 0 != uArgumentSize)
				{
					if (FAILED(pIShellLink->GetArguments(szArgument, uArgumentSize)))
					{
						bRet = false;
					}
				}

				pIShellLink->Release();
				pIShellLink = 0;
			}
			else
			{
				bRet = false;
			}

			CoUninitialize();
		}
		else
		{
			bRet = false;
		}
	}
	else
	{
		bRet = false;
	}

	return bRet;
}

bool ReadShortcutInfoW(
	const wchar_t * szShortcutFile,
	wchar_t * szTargetPath,
	const unsigned int uTargetPathSize,
	wchar_t * szArgument,
	const unsigned int uArgumentSize,
	wchar_t * szIconPath,
	const unsigned int uIconPathSize)
{
	bool bRet = true;
	IShellLinkW * pIShellLink = 0;

	if (NULL != szShortcutFile)
	{
		if (SUCCEEDED(CoInitialize(0)))
		{
			if (SUCCEEDED(CoCreateInstance(
				CLSID_ShellLink,
				0,
				CLSCTX_INPROC_SERVER,
				IID_IShellLink,
				(void **)&pIShellLink)))
			{
				if (NULL != szTargetPath && 0 != uTargetPathSize)
				{
					if (FAILED(pIShellLink->GetPath(szTargetPath, uTargetPathSize, NULL, 0)))
					{
						bRet = false;
					}
				}

				if (NULL != szIconPath && 0 != uIconPathSize)
				{
					if (FAILED(pIShellLink->GetIconLocation(szIconPath, uIconPathSize, NULL)))
					{
						bRet = false;
					}
				}

				if (NULL != szArgument && 0 != uArgumentSize)
				{
					if (FAILED(pIShellLink->GetArguments(szArgument, uArgumentSize)))
					{
						bRet = false;
					}
				}

				pIShellLink->Release();
				pIShellLink = 0;
			}
			else
			{
				bRet = false;
			}

			CoUninitialize();
		}
		else
		{
			bRet = false;
		}
	}
	else
	{
		bRet = false;
	}

	return bRet;
}

bool IsShortcutTargetA(const char * szShortcutFile, const char * szTarget)
{
	bool bRet = false;
	char szTargetTemp[MAX_PATH] = { 0 };

	if (NULL != szShortcutFile && NULL != szTarget)
	{
		if (true == ReadShortcutInfoA(szShortcutFile, szTargetTemp, MAX_PATH, NULL, 0, NULL, 0))
		{
			if (0 == strcmp(szTargetTemp, szTarget))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool IsShortcutTargetW(const wchar_t * szShortcutFile, const wchar_t * szTarget)
{
	bool bRet = false;
	wchar_t szTargetTemp[MAX_PATH] = { 0 };

	if (NULL != szShortcutFile && NULL != szTarget)
	{
		if (true == ReadShortcutInfoW(szShortcutFile, szTargetTemp, MAX_PATH, NULL, 0, NULL, 0))
		{
			if (0 == wcscmp(szTargetTemp, szTarget))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool IsDesktopExistFileA(const char * szFileName, const bool bCurrentUser)
{
	bool bRet = false;
	char szDesktopPath[MAX_PATH] = { 0 };
	char szFullFilePath[MAX_PATH] = { 0 };
	FILE * pFile = NULL;

	if (NULL != szFileName)
	{
		if (true == bCurrentUser)
		{
			bRet = SHGetSpecialFolderPathA(NULL, szDesktopPath, CSIDL_DESKTOPDIRECTORY, false) ? true : false;
		}
		else
		{
			bRet = SHGetSpecialFolderPathA(NULL, szDesktopPath, CSIDL_COMMON_DESKTOPDIRECTORY, false) ? true : false;
		}

		if (true == bRet && 0 != strlen(szDesktopPath))
		{
			PathAddBackslashA(szDesktopPath);

			sprintf_s(szFullFilePath, MAX_PATH, "%s%s", szDesktopPath, szFileName);

			if (0 == fopen_s(&pFile, szFullFilePath, "rb"))
			{
				fclose(pFile);

				bRet = true;
			}
		}
	}

	return bRet;
}

bool IsDesktopExistFileW(const wchar_t * szFileName, const bool bCurrentUser)
{
	bool bRet = false;
	wchar_t szDesktopPath[MAX_PATH] = { 0 };
	wchar_t szFullFilePath[MAX_PATH] = { 0 };
	FILE * pFile = NULL;

	if (NULL != szFileName)
	{
		if (true == bCurrentUser)
		{
			bRet = SHGetSpecialFolderPathW(NULL, szDesktopPath, CSIDL_DESKTOPDIRECTORY, false) ? true : false;
		}
		else
		{
			bRet = SHGetSpecialFolderPathW(NULL, szDesktopPath, CSIDL_COMMON_DESKTOPDIRECTORY, false) ? true : false;
		}

		if (true == bRet && 0 != wcslen(szDesktopPath))
		{
			PathAddBackslashW(szDesktopPath);

			swprintf_s(szFullFilePath, MAX_PATH, L"%s%s", szDesktopPath, szFileName);

			if (0 == _wfopen_s(&pFile, szFullFilePath, L"rb"))
			{
				fclose(pFile);

				bRet = true;
			}
		}
	}

	return bRet;
}

bool DeleteDesktopFileA(const char * szFileName, const bool bCurrentUser)
{
	bool bRet = true;
	char szDesktopPath[MAX_PATH] = { 0 };
	char szFullFilePath[MAX_PATH] = { 0 };

	if (NULL != szFileName)
	{
		if (true == bCurrentUser)
		{
			bRet = SHGetSpecialFolderPathA(NULL, szDesktopPath, CSIDL_DESKTOPDIRECTORY, false) ? true : false;
		}
		else
		{
			bRet = SHGetSpecialFolderPathA(NULL, szDesktopPath, CSIDL_COMMON_DESKTOPDIRECTORY, false) ? true : false;
		}

		if (true == bRet && 0 != strlen(szDesktopPath))
		{
			PathAddBackslashA(szDesktopPath);

			sprintf_s(szFullFilePath, MAX_PATH, "%s%s", szDesktopPath, szFileName);

			if (0 == DeleteFileA(szFullFilePath))
			{
				bRet = false;
			}
		}
		else
		{
			bRet = false;
		}
	}
	else
	{
		bRet = false;
	}

	return bRet;
}

bool DeleteDesktopFileW(const wchar_t * szFileName, const bool bCurrentUser)
{
	bool bRet = true;
	wchar_t szDesktopPath[MAX_PATH] = { 0 };
	wchar_t szFullFilePath[MAX_PATH] = { 0 };

	if (NULL != szFileName)
	{
		if (true == bCurrentUser)
		{
			bRet = SHGetSpecialFolderPathW(NULL, szDesktopPath, CSIDL_DESKTOPDIRECTORY, false) ? true : false;
		}
		else
		{
			bRet = SHGetSpecialFolderPathW(NULL, szDesktopPath, CSIDL_COMMON_DESKTOPDIRECTORY, false) ? true : false;
		}

		if (true == bRet && 0 != wcslen(szDesktopPath))
		{
			PathAddBackslashW(szDesktopPath);

			swprintf_s(szFullFilePath, MAX_PATH, L"%s%s", szDesktopPath, szFileName);

			if (0 == DeleteFileW(szFullFilePath))
			{
				bRet = false;
			}
		}
		else
		{
			bRet = false;
		}
	}
	else
	{
		bRet = false;
	}

	return bRet;
}

bool IsModuleFileInDesktop(const bool bCurrentUser)
{
	bool bRet = false;
	wchar_t szDesktopPath[MAX_PATH] = { 0 };
	wchar_t szModulePath[MAX_PATH] = { 0 };

	if (true == bCurrentUser)
	{
		SHGetSpecialFolderPathW(NULL, szDesktopPath, CSIDL_DESKTOPDIRECTORY, false);
	}
	else
	{
		SHGetSpecialFolderPathW(NULL, szDesktopPath, CSIDL_COMMON_DESKTOPDIRECTORY, false);
	}

	if (0 != wcslen(szDesktopPath))
	{
		PathAddBackslashW(szDesktopPath);

		if (0 != GetModuleFileNameW(NULL, szModulePath, MAX_PATH))
		{
			PathRemoveFileSpecW(szModulePath);
			PathAddBackslashW(szModulePath);

			if (0 == _wcsicmp(szDesktopPath, szModulePath))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}
