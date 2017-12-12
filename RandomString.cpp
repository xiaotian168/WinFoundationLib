
#include "RandomString.h"
#include "WFLibConfig.h"

static char g_MultibyteCharTable[] =
{
	'a', 'b', 'c', 'd', 'e', 'f',
	'g', 'h', 'i', 'j', 'k', 'l',
	'2', '3', '4', '5', '6', '7',
	'm', 'n', 'o', 'p', 'q', 'r',
	's', 't', 'u', 'v', 'w', 'x',
	'_', '=', '\\', '~', '@', '#',
	'y', 'z', 'A', 'B', 'C', 'D',
	'E', 'F', 'G', 'H', 'I', 'J',
	'$', '%', '^', '&',
	'K', 'L', 'M', 'N', 'O', 'P',
	'Q', 'R', 'S', 'T', 'U', 'V',
	'W', 'X', 'Y', 'Z', '0', '1',
	'8', '9', '+', '-', '*', '/',
};

static wchar_t g_UnicodeCharTable[] =
{
	L'a', L'b', L'c', L'd', L'e', L'f',
	L'g', L'h', L'i', L'j', L'k', L'l',
	L'2', L'3', L'4', L'5', L'6', L'7',
	L'm', L'n', L'o', L'p', L'q', L'r',
	L's', L't', L'u', L'v', L'w', L'x',
	L'_', L'=', L'\\', L'~', L'@', L'#',
	L'y', L'z', L'A', L'B', L'C', L'D',
	L'E', L'F', L'G', L'H', L'I', L'J',
	L'$', L'%', L'^', L'&',
	L'K', L'L', L'M', L'N', L'O', L'P',
	L'Q', L'R', L'S', L'T', L'U', L'V',
	L'W', L'X', L'Y', L'Z', L'0', L'1',
	L'8', L'9', L'+', L'-', L'*', L'/',
};

static const unsigned int g_MultibyteCharTableSize = sizeof(g_MultibyteCharTable) / sizeof(g_MultibyteCharTable[0]);
static const unsigned int g_UnicodeCharTableSize = sizeof(g_UnicodeCharTable) / sizeof(g_UnicodeCharTable[0]);

int BuildRandomStringA(char * pszRandomString, const unsigned int uBufferSize, const unsigned int uRandomStringLength)
{
	int nRet = 0;
	bool bRet = false;

	srand((unsigned int)GetTickCount());

	if (pszRandomString && uRandomStringLength && uBufferSize >= uRandomStringLength)
	{
		for (unsigned int i = 0; i < uRandomStringLength; ++i)
		{
			pszRandomString[i] = g_MultibyteCharTable[rand() % g_MultibyteCharTableSize];
		}

		nRet = 1;
	}

	return nRet;
}

int BuildRandomStringW(wchar_t * pszRandomString, const unsigned int uBufferSize, const unsigned int uRandomStringLength)
{
	int nRet = 0;
	bool bRet = false;

	srand((unsigned int)GetTickCount());

	if (pszRandomString && uRandomStringLength && uBufferSize >= uRandomStringLength)
	{
		for (unsigned int i = 0; i < uRandomStringLength; ++i)
		{
			pszRandomString[i] = g_UnicodeCharTable[rand() % g_UnicodeCharTableSize];
		}

		nRet = 1;
	}

	return nRet;
}
