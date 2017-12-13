
#include "CStartMenuProgramGroup.h"

CStartMenuProgramGroup::CStartMenuProgramGroup()
{

}

CStartMenuProgramGroup::~CStartMenuProgramGroup()
{

}

bool CStartMenuProgramGroup::GetAllUserProgramGroupDirectoryW(wchar_t * szDirectory, const unsigned int uSize, const bool bCreate /*= false*/)
{
	bool bRet = false;

	if (0 != szDirectory && uSize >= MAX_PATH)
	{
		bRet = SHGetSpecialFolderPathW(0, szDirectory, CSIDL_COMMON_PROGRAMS, bCreate) ? true : false;
	}

	return bRet;
}

bool CStartMenuProgramGroup::GetAllUserProgramGroupDirectoryA(char * szDirectory, const unsigned int uSize, const bool bCreate /*= false*/)
{
	bool bRet = false;

	if (0 != szDirectory && uSize >= MAX_PATH)
	{
		bRet = SHGetSpecialFolderPathA(0, szDirectory, CSIDL_COMMON_PROGRAMS, bCreate) ? true : false;
	}

	return bRet;
}

bool CStartMenuProgramGroup::CreateAllUserProgramGroupDirectoryW(const wchar_t * szGroupName)
{
	bool bRet = false;
	wchar_t szAllUserProgramGroupDirectory[MAX_PATH] = { 0 };
	wchar_t szProgramGroupDirectory[MAX_PATH] = { 0 };

	if (0 != szGroupName)
	{
		if (GetAllUserProgramGroupDirectoryW(szAllUserProgramGroupDirectory, MAX_PATH, true))
		{
			swprintf_s(
				szProgramGroupDirectory,
				MAX_PATH,
				L"%s\\%s",
				szAllUserProgramGroupDirectory,
				szGroupName);

			if (CreateDirectoryW(szProgramGroupDirectory, 0) || ERROR_ALREADY_EXISTS == GetLastError())
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool CStartMenuProgramGroup::CreateAllUserProgramGroupDirectoryA(const char * szGroupName)
{
	bool bRet = false;
	char szAllUserProgramGroupDirectory[MAX_PATH] = { 0 };
	char szProgramGroupDirectory[MAX_PATH] = { 0 };

	if (0 != szGroupName)
	{
		if (GetAllUserProgramGroupDirectoryA( szAllUserProgramGroupDirectory, MAX_PATH, true))
		{
			sprintf_s(
				szProgramGroupDirectory,
				MAX_PATH,
				"%s\\%s",
				szAllUserProgramGroupDirectory,
				szGroupName);

			if (CreateDirectoryA(szProgramGroupDirectory, 0) || ERROR_ALREADY_EXISTS == GetLastError())
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool CStartMenuProgramGroup::DeleteAllUserProgramGroupDirectoryFileW(const wchar_t * szGroupName, const wchar_t * szFileName)
{
	bool bRet = false;
	wchar_t szAllUserProgramGroupDirectory[MAX_PATH] = { 0 };
	wchar_t szFilePath[MAX_PATH] = { 0 };

	if (GetAllUserProgramGroupDirectoryW(szAllUserProgramGroupDirectory, MAX_PATH, true))
	{
		PathAddBackslashW(szAllUserProgramGroupDirectory);

		if (0 == szGroupName && 0 != szFileName)
		{
			swprintf_s(
				szFilePath,
				MAX_PATH,
				L"%s%s",
				szGroupName,
				szFileName);
		}
		else if(0 != szGroupName && 0 != szFileName)
		{
			swprintf_s(
				szFilePath,
				MAX_PATH,
				L"%s%s\\%s",
				szAllUserProgramGroupDirectory,
				szGroupName,
				szFileName);
		}

		if (0 != DeleteFileW(szFilePath))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool CStartMenuProgramGroup::DeleteAllUserProgramGroupDirectoryFileA(const char * szGroupName, const char * szFileName)
{
	bool bRet = false;
	char szAllUserProgramGroupDirectory[MAX_PATH] = { 0 };
	char szFilePath[MAX_PATH] = { 0 };

	if (GetAllUserProgramGroupDirectoryA(szAllUserProgramGroupDirectory, MAX_PATH, true))
	{
		PathAddBackslashA(szAllUserProgramGroupDirectory);

		if (0 == szGroupName && 0 != szFileName)
		{
			sprintf_s(
				szFilePath,
				MAX_PATH,
				"%s%s",
				szGroupName,
				szFileName);
		}
		else if (0 != szGroupName && 0 != szFileName)
		{
			sprintf_s(
				szFilePath,
				MAX_PATH,
				"%s%s\\%s",
				szAllUserProgramGroupDirectory,
				szGroupName,
				szFileName);
		}

		if (0 != DeleteFileA(szFilePath))
		{
			bRet = true;
		}
	}

	return bRet;
}

bool CStartMenuProgramGroup::DeleteAllUserProgramGroupDirectoryW(const wchar_t * szGroupName)
{
	bool bRet = false;
	wchar_t szAllUserProgramGroupDirectory[MAX_PATH] = { 0 };
	wchar_t szFilePath[MAX_PATH] = { 0 };

	if (0 != szGroupName)
	{
		if (GetAllUserProgramGroupDirectoryW(szAllUserProgramGroupDirectory, MAX_PATH, true))
		{
			PathAddBackslashW(szAllUserProgramGroupDirectory);

			swprintf_s(
				szFilePath,
				MAX_PATH,
				L"%s%s",
				szAllUserProgramGroupDirectory,
				szGroupName);

			if (0 != RemoveDirectoryW(szFilePath))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool CStartMenuProgramGroup::DeleteAllUserProgramGroupDirectoryA(const char * szGroupName)
{
	bool bRet = false;
	char szAllUserProgramGroupDirectory[MAX_PATH] = { 0 };
	char szFilePath[MAX_PATH] = { 0 };

	if (0 != szGroupName)
	{
		if (GetAllUserProgramGroupDirectoryA(szAllUserProgramGroupDirectory, MAX_PATH, true))
		{
			PathAddBackslashA(szAllUserProgramGroupDirectory);

			sprintf_s(
				szFilePath,
				MAX_PATH,
				"%s%s",
				szAllUserProgramGroupDirectory,
				szGroupName);

			if (0 != RemoveDirectoryA(szFilePath))
			{
				bRet = true;
			}
		}
	}

	return bRet;
}

bool CStartMenuProgramGroup::CreateStartMenuAllUserProgramGroup(
	const TCHAR * szGroupName,
	const TCHAR * szProgramPath,
	const TCHAR * szLinkIconPath,
	const TCHAR * szProgramLinkFileName)
{
	bool bRet = true;
	TCHAR szAllUserProgramGroupDirectory[MAX_PATH] = { 0 };
	TCHAR szProgramLinkPath[MAX_PATH] = { 0 };

	if (0 != szGroupName &&
		0 != szProgramPath &&
		0 != szProgramLinkFileName)
	{
		// 为程序组创建目录 

		if (true == CStartMenuProgramGroup::CreateAllUserProgramGroupDirectory(szGroupName))
		{
			// 将程序的快捷方式写入到程序组目录中

			if (true == CStartMenuProgramGroup::GetAllUserProgramGroupDirectory(szAllUserProgramGroupDirectory, MAX_PATH, true))
			{
				_stprintf_s(
					szProgramLinkPath,
					MAX_PATH,
					_T("%s\\%s\\%s"),
					szAllUserProgramGroupDirectory,
					szGroupName,
					szProgramLinkFileName);

				if (true != CreateShortCut(
					szProgramLinkPath,
					szProgramPath,
					szLinkIconPath))
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
	}
	else
	{
		bRet = false;
	}

	return bRet;
}

bool CStartMenuProgramGroup::CreateShortCut(
	const TCHAR * szLinkPath,
	const TCHAR * szExePath,
	const TCHAR * szIconPath)
{
	bool bRet = false;
	IShellLink * pShellLink = 0;
	IPersistFile * pPersistFile = 0;
	TCHAR szWorkingDir[MAX_PATH] = { 0 };

	if (SUCCEEDED(CoInitialize(NULL)))
	{
		if (PathFileExists(szLinkPath))
		{
			DeleteFile(szLinkPath);
		}

		if (SUCCEEDED(CoCreateInstance(
			CLSID_ShellLink,
			NULL,
			CLSCTX_INPROC_SERVER,
			IID_IShellLink,
			(void **)&pShellLink)))
		{
			pShellLink->SetPath(szExePath);

			if (0 != szIconPath &&
				PathFileExists(szIconPath))
			{
				pShellLink->SetIconLocation(szIconPath, 0);
			}

			_tcsncpy_s(szWorkingDir, MAX_PATH, szExePath, 3);
			pShellLink->SetWorkingDirectory(szWorkingDir);

			if (SUCCEEDED(pShellLink->QueryInterface(
				IID_IPersistFile,
				(void **)&pPersistFile)))
			{
				if (SUCCEEDED(pPersistFile->Save(szLinkPath, true)))
				{
					bRet = true;
				}

				pPersistFile->Release();
			}

			pShellLink->Release();
		}

		CoUninitialize();
	}

	return bRet;
}
