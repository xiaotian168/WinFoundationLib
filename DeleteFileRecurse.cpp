
#include "DeleteFileRecurse.h"
#include "WFLibConfig.h"

void DeleteFileRecurseA(const char * szDirectory, const bool bDeleteDirectory)
{
	char szPathFind[MAX_PATH] = { 0 };
	char szPathFindNext[MAX_PATH] = { 0 };
	char szPathDirectory[MAX_PATH] = { 0 };
	char szPathFile[MAX_PATH] = { 0 };
	WIN32_FIND_DATAA wfd = { 0 };
	HANDLE hFind = INVALID_HANDLE_VALUE;

	if (NULL != szDirectory)
	{
		strcpy_s(szPathFind, MAX_PATH, szDirectory);
		PathAddBackslashA(szPathFind);
		strcat_s(szPathFind, MAX_PATH, "*.*");

		hFind = FindFirstFileA(szPathFind, &wfd);

		if (INVALID_HANDLE_VALUE != hFind)
		{
			do 
			{
				if (0 != (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
				{
					// 递归删除子目录与文件

					if ('.' != wfd.cFileName[0])
					{
						strcpy_s(szPathFindNext, MAX_PATH, szDirectory);
						PathAddBackslashA(szPathFindNext);
						strcat_s(szPathFindNext, MAX_PATH, wfd.cFileName);

						DeleteFileRecurseA(szPathFindNext, bDeleteDirectory);

						if (true == bDeleteDirectory)
						{
							// 删除目录

							strcpy_s(szPathDirectory, MAX_PATH, szDirectory);
							PathAddBackslashA(szPathDirectory);
							strcat_s(szPathDirectory, MAX_PATH, wfd.cFileName);

							RemoveDirectoryA(szPathDirectory);
						}
					}
				}
				else
				{
					// 删除文件

					strcpy_s(szPathFile, MAX_PATH, szDirectory);
					PathAddBackslashA(szPathFile);
					strcat_s(szPathFile, MAX_PATH, wfd.cFileName);

					DeleteFileA(szPathFile);
				}

			} while (0 != FindNextFileA(hFind, &wfd));
		}

		FindClose(hFind);
	}
}

void DeleteFileRecurseW(const wchar_t * szDirectory, const bool bDeleteDirectory)
{
	wchar_t szPathFind[MAX_PATH] = { 0 };
	wchar_t szPathFindNext[MAX_PATH] = { 0 };
	wchar_t szPathDirectory[MAX_PATH] = { 0 };
	wchar_t szPathFile[MAX_PATH] = { 0 };
	WIN32_FIND_DATAW wfd = { 0 };
	HANDLE hFind = INVALID_HANDLE_VALUE;

	if (NULL != szDirectory)
	{
		wcscpy_s(szPathFind, MAX_PATH, szDirectory);
		PathAddBackslashW(szPathFind);
		wcscat_s(szPathFind, MAX_PATH, L"*.*");

		hFind = FindFirstFileW(szPathFind, &wfd);

		if (INVALID_HANDLE_VALUE != hFind)
		{
			do
			{
				if (0 != (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
				{
					if ('.' != wfd.cFileName[0])
					{
						wcscpy_s(szPathFindNext, MAX_PATH, szDirectory);
						PathAddBackslashW(szPathFindNext);
						wcscat_s(szPathFindNext, MAX_PATH, wfd.cFileName);

						DeleteFileRecurseW(szPathFindNext, bDeleteDirectory);

						if (true == bDeleteDirectory)
						{
							wcscpy_s(szPathDirectory, MAX_PATH, szDirectory);
							PathAddBackslashW(szPathDirectory);
							wcscat_s(szPathDirectory, MAX_PATH, wfd.cFileName);

							RemoveDirectoryW(szPathDirectory);
						}
					}
				}
				else
				{
					wcscpy_s(szPathFile, MAX_PATH, szDirectory);
					PathAddBackslashW(szPathFile);
					wcscat_s(szPathFile, MAX_PATH, wfd.cFileName);

					DeleteFileW(szPathFile);
				}

			} while (0 != FindNextFileW(hFind, &wfd));
		}

		FindClose(hFind);
	}
}
