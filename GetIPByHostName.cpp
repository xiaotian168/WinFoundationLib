
#include "GetIPByHostName.h"
#include "WFLibConfig.h"

bool GetIPByHostNameA(const char * szHostName, char * szIP, const unsigned int dwSize)
{
	bool bRet = false;
	hostent * pHostEnt = NULL;
	sockaddr_in addr = { 0 };

	if (NULL != szHostName && NULL != szIP && 0 != dwSize)
	{
		pHostEnt = gethostbyname(szHostName);

		if (NULL != pHostEnt)
		{
			if (AF_INET == pHostEnt->h_addrtype || AF_INET6 == pHostEnt->h_addrtype)
			{
				memcpy(&addr.sin_addr, pHostEnt->h_addr_list[0], pHostEnt->h_length);
				
				const char * szIPTemp = inet_ntoa(addr.sin_addr);

				if (NULL != szIPTemp)
				{
					strcpy_s(szIP, dwSize, szIPTemp);

					bRet = true;
				}
			}
		}
	}

	return bRet;
}

bool GetIPByHostNameW(const wchar_t * szHostName, wchar_t * szIP, const unsigned int dwSize)
{
	bool bRet = false;
	hostent * pHostEnt = NULL;
	sockaddr_in addr = { 0 };
	char * pszHostNameA = NULL;
	int nLen = 0;

	if (NULL != szHostName && NULL != szIP && 0 != dwSize)
	{
		if (0 != (nLen = WideCharToMultiByte(CP_ACP, 0, szHostName, -1, NULL, 0, NULL, NULL)))
		{
			if (NULL != (pszHostNameA = new char[nLen + 1]))
			{
				if (0 != WideCharToMultiByte(CP_ACP, 0, szHostName, -1, pszHostNameA, nLen + 1, NULL, NULL))
				{
					pszHostNameA[nLen] = 0;

					pHostEnt = gethostbyname(pszHostNameA);

					if (NULL != pHostEnt)
					{
						if (AF_INET == pHostEnt->h_addrtype || AF_INET6 == pHostEnt->h_addrtype)
						{
							memcpy(&addr.sin_addr, pHostEnt->h_addr_list[0], pHostEnt->h_length);

							const char * szIPTemp = inet_ntoa(addr.sin_addr);

							if (NULL != szIPTemp)
							{
								if (0 != MultiByteToWideChar(CP_ACP, 0, szIPTemp, -1, szIP, dwSize))
								{
									bRet = true;
								}
							}
						}
					}
				}

				delete[] pszHostNameA;
			}
		}
	}

	return bRet;
}
