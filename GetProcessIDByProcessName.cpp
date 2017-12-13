
#include "GetProcessIDByProcessName.h"

DWORD GetProcessIDByProcessNameW(const wchar_t * szProcessName)
{
	DWORD dwID = 0;
	HANDLE hSnapshot = INVALID_HANDLE_VALUE;
	PROCESSENTRY32W ProcessEntry = { 0 };

	if (NULL != szProcessName &&
		0 != wcslen(szProcessName) &&
		NULL != (hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0)))
	{
		ProcessEntry.dwSize = sizeof(ProcessEntry);

		if (0 != Process32FirstW(hSnapshot, &ProcessEntry))
		{
			do
			{
				if (0 == wcscmp(szProcessName, ProcessEntry.szExeFile))
				{
					dwID = ProcessEntry.th32ProcessID;
					break;
				}
				
			} while (0 != Process32NextW(hSnapshot, &ProcessEntry));
		}
	}

	return dwID;
}
