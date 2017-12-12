
#include "CUnicodeString2StdMultiByteString.h"

bool CUnicodeString2StdMultiByteString(const wchar_t * pszUnicodeString, std::string & strMultiByteString, const unsigned int uCodePage)
{
	bool bRet = false;
	int nRet = 0;
	char * pszMultiByteString = 0;

	if (pszUnicodeString)
	{
		nRet = WideCharToMultiByte(uCodePage, 0, pszUnicodeString, -1, 0, 0, 0, 0);

		if (nRet)
		{
			pszMultiByteString = new char[nRet + 1];

			if (pszMultiByteString)
			{
				nRet = WideCharToMultiByte(uCodePage, 0, pszUnicodeString, -1, pszMultiByteString, nRet + 1, 0, 0);

				if (nRet)
				{
					pszMultiByteString[nRet] = '0';
					strMultiByteString = pszMultiByteString;

					bRet = true;
				}

				delete pszMultiByteString;
				pszMultiByteString = 0;
			}
		}
	}

	return bRet;
}

bool CMultiByteString2StdUnicodeString(const char * pszMultiByteString, std::wstring & strUnicodeString, const unsigned int uCodePage)
{
	bool bRet = false;
	int nRet = 0;
	wchar_t * pszUnicodeString = 0;

	if (pszMultiByteString)
	{
		nRet = MultiByteToWideChar(uCodePage, 0, pszMultiByteString, -1, 0, 0);

		if (nRet)
		{
			pszUnicodeString = new wchar_t[nRet + 1];

			if (pszUnicodeString)
			{
				nRet = MultiByteToWideChar(uCodePage, 0, pszMultiByteString, -1, pszUnicodeString, nRet + 1);

				if (nRet)
				{
					pszUnicodeString[nRet] = L'\0';
					strUnicodeString = pszUnicodeString;

					bRet = true;
				}

				delete pszUnicodeString;
				pszUnicodeString = 0;
			}
		}
	}

	return bRet;
}

bool CTString2StdMultiByteString(const TCHAR * pszTString, std::string & strMultiByteString, const unsigned int uCodePage /*= CP_ACP*/)
{
	bool bRet = false;

	if (pszTString)
	{
#if defined UNICODE || defined _UNICODE
		bRet = CUnicodeString2StdMultiByteString(pszTString, strMultiByteString, uCodePage);
#else
		strMultiByteString = pszTString;

		bRet = true;
#endif
	}

	return bRet;
}

bool CTString2StdUnicodeString(const TCHAR * pszTString, std::wstring & strUnicodeString, const unsigned int uCodePage /*= CP_ACP*/)
{
	bool bRet = false;

	if (pszTString)
	{
#if defined UNICODE || defined _UNICODE
		strUnicodeString = pszTString;

		bRet = true;
#else
		bRet = CMultiByteString2StdUnicodeString(pszTString, strUnicodeString, uCodePage);
#endif
	}

	return bRet;
}
