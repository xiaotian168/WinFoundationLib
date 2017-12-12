
#include "GetFileList.h"

bool GetFileListA(const char * pszPath, const char * pszFileExt, bool bSubDir, std::list<std::string> & FileList)
{
	bool bRet = false;
	HANDLE hFindFile = 0;
	WIN32_FIND_DATAA WinFindData = { 0 };
	std::string strPath;
	std::string strFindPath;
	std::string strSubDir;
	std::string strFilePath;

	if (pszPath && pszFileExt)
	{
		strPath = pszPath;
		AppendStdStringBackslashA(strPath, '\\');
		strFindPath = strPath + "*.*";

		hFindFile = FindFirstFileA(strFindPath.c_str(), &WinFindData);
		if (INVALID_HANDLE_VALUE != hFindFile)
		{
			do 
			{
				if (WinFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (bSubDir)
					{
						if ('.' != WinFindData.cFileName[0])
						{
							strPath += WinFindData.cFileName;
							AppendStdStringBackslashA(strPath, '\\');

							GetFileListA(strPath.c_str(), pszFileExt, bSubDir, FileList);
						}
					}
				}
				else
				{
					strFilePath = strPath + WinFindData.cFileName;
					FileList.push_back(strFilePath);
				}

			} while (FindNextFileA(hFindFile, &WinFindData));

			FindClose(hFindFile);
			hFindFile = 0;

			bRet = true;
		}
	}

	return bRet;
}

bool GetFileListW(const wchar_t * pszPath, const wchar_t * pszFileExt, bool bSubDir, std::list<std::wstring> & FileList)
{
	bool bRet = false;
	HANDLE hFindFile = 0;
	WIN32_FIND_DATAW WinFindData = { 0 };
	std::wstring strPath;
	std::wstring strFindPath;
	std::wstring strSubDir;
	std::wstring strFilePath;

	if (pszPath && pszFileExt)
	{
		strPath = pszPath;
		AppendStdStringBackslashW(strPath, L'\\');
		strFindPath = strPath + L"*.*";

		hFindFile = FindFirstFileW(strFindPath.c_str(), &WinFindData);
		if (INVALID_HANDLE_VALUE != hFindFile)
		{
			do
			{
				if (WinFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
				{
					if (bSubDir)
					{
						if (L'.' != WinFindData.cFileName[0])
						{
							strPath += WinFindData.cFileName;
							AppendStdStringBackslashW(strPath, L'\\');

							GetFileListW(strPath.c_str(), pszFileExt, bSubDir, FileList);
						}
					}
				}
				else
				{
					strFilePath = strPath + WinFindData.cFileName;
					FileList.push_back(strFilePath);
				}

			} while (FindNextFileW(hFindFile, &WinFindData));

			FindClose(hFindFile);
			hFindFile = 0;

			bRet = true;
		}
	}

	return bRet;
}

void AppendStdStringBackslashA(std::string & strPath, const char cSlash)
{
	char szSlash[2] = { 0 };

	if (strPath.length())
	{
		if (cSlash != strPath[strPath.length() - 1])
		{
			szSlash[0] = cSlash;
			strPath += szSlash;
		}
	}
}

void AppendStdStringBackslashW(std::wstring & strPath, const wchar_t cSlash)
{
	wchar_t szSlash[2] = { 0 };

	if (strPath.length())
	{
		if (cSlash != strPath[strPath.length() - 1])
		{
			szSlash[0] = cSlash;
			strPath += szSlash;
		}
	}
}
