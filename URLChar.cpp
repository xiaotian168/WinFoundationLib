
#include "URLChar.h"
#include "WFLibConfig.h"

bool IsURLCharSpecialCharA(const char c)
{
	static const char szSpecialCharList[] =
	{
		' ', '"', '#', '%', '&', '(', ')', '+', ',', '/', ':',
		';', '<', '=', '>', '?', '@', '\\', '|',
	};

	static const size_t uDim = sizeof(szSpecialCharList) / sizeof(szSpecialCharList[0]);

	for (size_t i = 0; i < uDim; ++i)
	{
		if (c == szSpecialCharList[i])
		{
			return true;
		}
	}

	return false;
}

bool IsURLCharSpecialCharW(const wchar_t c)
{
	static const wchar_t szSpecialCharList[] =
	{
		L' ', L'"', L'#', L'%', L'&', L'(', L')', L'+', L',', L'/',
		L':', L';', L'<', L'=', L'>', L'?', L'@', L'\\', L'|',
	};

	static const size_t uDim = sizeof(szSpecialCharList) / sizeof(szSpecialCharList[0]);

	for (size_t i = 0; i < uDim; ++i)
	{
		if (c == szSpecialCharList[i])
		{
			return true;
		}
	}

	return false;
}

bool ConvertURLSpecialCharA(const char c, char * szC, const unsigned int uSize)
{
	if (szC && uSize)
	{
		sprintf_s(szC, uSize, "%%%.2X", c);

		return true;
	}

	return false;
}

bool ConvertURLSpecialCharW(const wchar_t c, wchar_t * szC, const unsigned int uSize)
{
	if (szC && uSize)
	{
		swprintf_s(szC, uSize, L"%%%.2X", c);

		return true;
	}

	return false;
}

unsigned int CalcURLStringSizeAfterConvertA(const char * pszURL)
{
	unsigned int uSizeAfterConvert = 0;
	size_t uURLLen = 0;
	char szSpecialChar[6] = { 0 };

	if (pszURL)
	{
		uURLLen = strlen(pszURL);

		if (uURLLen)
		{
			for (unsigned int i = 0; i < uURLLen; ++i)
			{
				if (IsURLCharSpecialCharA(pszURL[i]))
				{
					memset(szSpecialChar, 0, sizeof(szSpecialChar));

					if (ConvertURLSpecialCharA(pszURL[i], szSpecialChar, 6))
					{
						uSizeAfterConvert += strlen(szSpecialChar);
					}
					else
					{
						uSizeAfterConvert += 6;
					}
				}
				else
				{
					uSizeAfterConvert += 1;
				}
			}
		}
	}

	return uSizeAfterConvert;
}

unsigned int CalcURLStringSizeAfterConvertW(const wchar_t * pszURL)
{
	unsigned int uSizeAfterConvert = 0;
	size_t uURLLen = 0;
	wchar_t szSpecialChar[6] = { 0 };

	if (pszURL)
	{
		uURLLen = wcslen(pszURL);

		if (uURLLen)
		{
			for (unsigned int i = 0; i < uURLLen; ++i)
			{
				if (IsURLCharSpecialCharW(pszURL[i]))
				{
					memset(szSpecialChar, 0, sizeof(szSpecialChar));

					if (ConvertURLSpecialCharW(pszURL[i], szSpecialChar, 6))
					{
						uSizeAfterConvert += wcslen(szSpecialChar);
					}
					else
					{
						uSizeAfterConvert += 6;
					}
				}
				else
				{
					uSizeAfterConvert += 1;
				}
			}
		}
	}

	return uSizeAfterConvert;
}

bool ConvertURLA(const char * pszURL, char * pszURLAfterConvert, const unsigned int uSize)
{
	bool bRet = false;
	size_t uURLLen = 0;
	char szSpecialChar[6] = { 0 };

	if (pszURL && pszURLAfterConvert && uSize)
	{
		uURLLen = strlen(pszURL);

		if (uURLLen)
		{
			memset(pszURLAfterConvert, 0, uSize);

			for (unsigned int i = 0; i < uURLLen; ++i)
			{
				memset(szSpecialChar, 0, sizeof(szSpecialChar));

				if (IsURLCharSpecialCharA(pszURL[i]))
				{
					ConvertURLSpecialCharA(pszURL[i], szSpecialChar, 6);
				}
				else
				{
					szSpecialChar[0] = pszURL[i];
					szSpecialChar[1] = '\0';
				}

				strcat_s(pszURLAfterConvert, uSize, szSpecialChar);
			}

			bRet = true;
		}
	}

	return bRet;
}

bool ConvertURLW(const wchar_t * pszURL, wchar_t * pszURLAfterConvert, const unsigned int uSize)
{
	bool bRet = false;
	size_t uURLLen = 0;
	wchar_t szSpecialChar[6] = { 0 };

	if (pszURL && pszURLAfterConvert && uSize)
	{
		uURLLen = wcslen(pszURL);

		if (uURLLen)
		{
			memset(pszURLAfterConvert, 0, uSize);

			for (unsigned int i = 0; i < uURLLen; ++i)
			{
				memset(szSpecialChar, 0, sizeof(szSpecialChar));

				if (IsURLCharSpecialCharW(pszURL[i]))
				{
					ConvertURLSpecialCharW(pszURL[i], szSpecialChar, 6);
				}
				else
				{
					szSpecialChar[0] = pszURL[i];
					szSpecialChar[1] = L'\0';
				}

				wcscat_s(pszURLAfterConvert, uSize, szSpecialChar);
			}

			bRet = true;
		}
	}

	return bRet;
}
