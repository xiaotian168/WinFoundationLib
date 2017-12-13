
#include "SetEventByName.h"
#include "WFLibConfig.h"

bool SetEventByNameW(const wchar_t * szEventName)
{
	bool bRet = false;
	HANDLE hEvent = NULL;

	if (NULL != szEventName && 0 != wcslen(szEventName))
	{
		if (NULL == (hEvent = OpenEventW(EVENT_ALL_ACCESS, false, szEventName)))
		{
			hEvent = CreateEventW(0, false, false, szEventName);
		}

		if (NULL != hEvent)
		{
			if (0 != SetEvent(hEvent))
			{
				bRet = true;
			}

			CloseHandle(hEvent);
			hEvent = NULL;
		}
	}

	return bRet;
}

bool SetEventByNameA(const char * szEventName)
{
	bool bRet = false;
	HANDLE hEvent = NULL;

	if (NULL != szEventName && 0 != strlen(szEventName))
	{
		if (NULL == (hEvent = OpenEventA(EVENT_ALL_ACCESS, false, szEventName)))
		{
			hEvent = CreateEventA(0, false, false, szEventName);
		}

		if (NULL != hEvent)
		{
			if (0 != SetEvent(hEvent))
			{
				bRet = true;
			}

			CloseHandle(hEvent);
			hEvent = NULL;
		}
	}

	return bRet;
}
