
#include "FormatSoftSizeString.h"
#include "WFLibConfig.h"

bool FormatSoftSizeStringA(const unsigned long long uSoftSizeInByte, char * szString, const unsigned int uSize)
{
	bool bRet = FALSE;

	if (0 != szString && 0 != uSize)
	{
		if (uSoftSizeInByte < (unsigned long long)(1024))
		{
			sprintf_s(szString, uSize, "%lld Byte", uSoftSizeInByte);
			bRet = TRUE;
		}
		else if (uSoftSizeInByte < (unsigned long long)(1024 * 1024))
		{
			sprintf_s(szString, uSize, "%lld KB", uSoftSizeInByte / 1024);
			bRet = TRUE;
		}
		else if (uSoftSizeInByte < (unsigned long long)(1024 * 1024 * 1024))
		{
			sprintf_s(szString, uSize, "%lld MB", uSoftSizeInByte / 1024 / 1024);
			bRet = TRUE;
		}
		else if (uSoftSizeInByte < (unsigned long long)(1024i64 * 1024i64 * 1024i64 * 1024i64))
		{
			sprintf_s(szString, uSize, "%lld GB", uSoftSizeInByte / 1024 / 1024 / 1024);
			bRet = TRUE;
		}
	}

	return bRet;
}

bool FormatSoftSizeStringW(const unsigned long long uSoftSizeInByte, wchar_t * szString, const unsigned int uSize)
{
	bool bRet = FALSE;

	if (0 != szString && 0 != uSize)
	{
		if (uSoftSizeInByte < (unsigned long long)(1024))
		{
			swprintf_s(szString, uSize, L"%lld Byte", uSoftSizeInByte);
			bRet = TRUE;
		}
		else if (uSoftSizeInByte < (unsigned long long)(1024 * 1024))
		{
			swprintf_s(szString, uSize, L"%lld KB", uSoftSizeInByte / 1024);
			bRet = TRUE;
		}
		else if (uSoftSizeInByte < (unsigned long long)(1024 * 1024 * 1024))
		{
			swprintf_s(szString, uSize, L"%lld MB", uSoftSizeInByte / 1024 / 1024);
			bRet = TRUE;
		}
		else if (uSoftSizeInByte < (unsigned long long)(1024i64 * 1024i64 * 1024i64 * 1024i64))
		{
			swprintf_s(szString, uSize, L"%lld GB", uSoftSizeInByte / 1024 / 1024 / 1024);
			bRet = TRUE;
		}
	}

	return bRet;
}
