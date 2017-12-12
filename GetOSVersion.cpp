
#include "GetOSVersion.h"
#include "WFLibConfig.h"

typedef void(WINAPI *LPFNRTLGETNTVERSIONNUMBERS)(DWORD *, DWORD *, DWORD *);

bool GetOSVersion(OSVERSION & OSVer)
{
	bool bRet = false;
	HMODULE hDLLNTDLL = NULL;
	LPFNRTLGETNTVERSIONNUMBERS pfnRtlGetNtVersionNumbers = NULL;
	DWORD dwVerMajor = 0;
	DWORD dwVerMinor = 0;
	DWORD dwVerBuildNum = 0;

	hDLLNTDLL = LoadLibraryW(L"ntdll.dll");

	if (hDLLNTDLL)
	{
		pfnRtlGetNtVersionNumbers = (LPFNRTLGETNTVERSIONNUMBERS)GetProcAddress(hDLLNTDLL, "RtlGetNtVersionNumbers");

		if (pfnRtlGetNtVersionNumbers)
		{
			pfnRtlGetNtVersionNumbers(&dwVerMajor, &dwVerMinor, &dwVerBuildNum);
			dwVerBuildNum &= 0x8FFFFFFF;

			OSVer.uMajor = dwVerMajor;
			OSVer.uMinor = dwVerMinor;
			OSVer.uBuildNum = dwVerBuildNum;
			
			bRet = true;
		}
	}

	return bRet;
}
