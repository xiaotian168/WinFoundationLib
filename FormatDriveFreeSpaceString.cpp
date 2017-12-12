
#include "FormatDriveFreeSpaceString.h"
#include "WFLibConfig.h"

bool FormatDriveFreeSpaceStringA(const char * szDrive, char * szSpaceString, const unsigned int uSize)
{
	bool bRet = true;
	ULARGE_INTEGER uFreeAvg = { 0 };
	ULARGE_INTEGER uFreeSize = { 0 };
	ULARGE_INTEGER uTotalSize = { 0 };
	char _szDrive[6] = { 0 };

	if (0 != szDrive && strlen(szDrive) > 2 && 0 != szSpaceString && 0 != uSize)
	{
		strncpy_s(_szDrive, 6, szDrive, 3);

		if (0 != GetDiskFreeSpaceExA(_szDrive, &uFreeAvg, &uTotalSize, &uFreeSize))
		{
			if (uFreeSize.QuadPart < ULONGLONG(1024) * ULONGLONG(1024))
			{
				sprintf_s(
					szSpaceString,
					uSize,
					"%d KB",
					ULONG(uFreeSize.QuadPart / 1024));
			}
			else if (uFreeSize.QuadPart < ULONGLONG(1024) * ULONGLONG(1024) * ULONGLONG(1024))
			{
				sprintf_s(
					szSpaceString,
					uSize,
					"%d MB",
					ULONG(uFreeSize.QuadPart / 1024 / 1024));
			}
			else if (uFreeSize.QuadPart < ULONGLONG(1024) * ULONGLONG(1024) * ULONGLONG(1024) * ULONGLONG(1024))
			{
				sprintf_s(
					szSpaceString,
					uSize,
					"%d GB",
					ULONG(uFreeSize.QuadPart / 1024 / 1024 / 1024));
			}

			bRet = true;
		}
	}
	else
	{
		bRet = false;
	}

	return bRet;
}

bool FormatDriveFreeSpaceStringW(const wchar_t * szDrive, wchar_t * szSpaceString, const unsigned int uSize)
{
	bool bRet = true;
	ULARGE_INTEGER uFreeAvg = { 0 };
	ULARGE_INTEGER uFreeSize = { 0 };
	ULARGE_INTEGER uTotalSize = { 0 };
	wchar_t _szDrive[6] = { 0 };

	if (0 != szDrive && wcslen(szDrive) > 2 && 0 != szSpaceString && 0 != uSize)
	{
		wcsncpy_s(_szDrive, 6, szDrive, 3);

		if (0 != GetDiskFreeSpaceExW(_szDrive, &uFreeAvg, &uTotalSize, &uFreeSize))
		{
			if (uFreeSize.QuadPart < ULONGLONG(1024) * ULONGLONG(1024))
			{
				swprintf_s(
					szSpaceString,
					uSize,
					L"%d KB",
					ULONG(uFreeSize.QuadPart / 1024));
			}
			else if (uFreeSize.QuadPart < ULONGLONG(1024) * ULONGLONG(1024) * ULONGLONG(1024))
			{
				swprintf_s(
					szSpaceString,
					uSize,
					L"%d MB",
					ULONG(uFreeSize.QuadPart / 1024 / 1024));
			}
			else if (uFreeSize.QuadPart < ULONGLONG(1024) * ULONGLONG(1024) * ULONGLONG(1024) * ULONGLONG(1024))
			{
				swprintf_s(
					szSpaceString,
					uSize,
					L"%d GB",
					ULONG(uFreeSize.QuadPart / 1024 / 1024 / 1024));
			}

			bRet = true;
		}
	}
	else
	{
		bRet = false;
	}

	return bRet;
}
