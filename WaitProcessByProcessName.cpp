
#include "WaitProcessByProcessName.h"
#include "WFLibConfig.h"

bool WaitProcessByProcessNameW(const wchar_t * szProcessName, const unsigned int uTimeOut)
{
	bool bRet = false;
	DWORD dwProcessID = 0;
	HANDLE hSnapshot = INVALID_HANDLE_VALUE;
	PROCESSENTRY32W ProcessEntry = { 0 };
	HANDLE hProcess = 0;

	if (szProcessName && wcslen(szProcessName))
	{
		hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hSnapshot)
		{
			ProcessEntry.dwSize = sizeof(ProcessEntry);

			if (Process32FirstW(hSnapshot, &ProcessEntry))
			{
				do
				{
					if (0 == wcscmp(szProcessName, ProcessEntry.szExeFile))
					{
						dwProcessID = ProcessEntry.th32ProcessID;
						break;
					}

				} while (Process32NextW(hSnapshot, &ProcessEntry));
			}

			CloseHandle(hSnapshot);
			hSnapshot = 0;

			if (dwProcessID)
			{
				hProcess = OpenProcess(SYNCHRONIZE, FALSE, dwProcessID);
				if (hProcess)
				{
					if (WAIT_OBJECT_0 == WaitForSingleObject(hProcess, uTimeOut))
					{
						bRet = true;
					}

					CloseHandle(hProcess);
					hProcess = 0;
				}
			}
		}
	}

	return bRet;
}
