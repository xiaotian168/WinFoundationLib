
#pragma once

#if defined UNICODE || defined _UNICODE
#	define GetIPByHostName GetIPByHostNameW
#else
#	define GetIPByHostName GetIPByHostNameA
#endif

/**
** @brief ��ȡָ�������ĵ�һ�� IPv4 ��ַ
*/
extern bool GetIPByHostNameA(const char * szHostName, char * szIP, const unsigned int dwSize);
extern bool GetIPByHostNameW(const wchar_t * szHostName, wchar_t * szIP, const unsigned int dwSize);
