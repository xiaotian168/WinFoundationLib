
#include "CalcFileSize.h"
#include "WFLibConfig.h"

unsigned long long CalcFileSizeA(const char * szFile)
{
	unsigned long long uFileSize = 0;
	FILE * pFile = NULL;

	if (NULL != szFile && 0 != strlen(szFile))
	{
		if (0 == fopen_s(&pFile, szFile, "rb"))
		{
			if (0 == _fseeki64(pFile, 0, SEEK_END))
			{
				uFileSize = _ftelli64(pFile);
			}

			fclose(pFile);
		}
	}

	return uFileSize;
}

static unsigned long long CalcFileSizeW(const wchar_t * szFile)
{
	unsigned long long uFileSize = 0;
	FILE * pFile = NULL;

	if (NULL != szFile && 0 != wcslen(szFile))
	{
		if (0 == _wfopen_s(&pFile, szFile, L"rb"))
		{
			if (0 == _fseeki64(pFile, 0, SEEK_END))
			{
				uFileSize = _ftelli64(pFile);
			}

			fclose(pFile);
		}
	}

	return uFileSize;
}
