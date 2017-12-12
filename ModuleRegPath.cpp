
#include "ModuleRegPath.h"

bool WriteModulePathToRegA(const HKEY hKeyRoot, const char * szSubKey, const char * szValueName)
{
	bool bRet = false;
	HKEY hKey = NULL;
	LONG nRet = 0;
	char szModulePath[MAX_PATH] = { 0 };

	if (NULL != hKeyRoot && NULL != szSubKey && NULL != szValueName)
	{
		if (0 != GetModuleFileNameA(NULL, szModulePath, MAX_PATH))
		{
			nRet = RegCreateKeyExA(hKeyRoot, szSubKey, 0, NULL, 0, KEY_WRITE | KEY_WOW64_64KEY, NULL, &hKey, NULL);

			if (ERROR_SUCCESS != nRet)
			{
				nRet = RegCreateKeyExA(hKeyRoot, szSubKey, 0, NULL, 0, KEY_WRITE | KEY_WOW64_32KEY, NULL, &hKey, NULL);
			}

			if (ERROR_SUCCESS == nRet && NULL != hKey)
			{
				nRet = RegSetValueExA(hKey, szValueName, 0, REG_SZ, (const BYTE *)szModulePath, (DWORD)strlen(szModulePath));

				if (ERROR_SUCCESS == nRet)
				{
					bRet = true;
				}

				RegCloseKey(hKey);
			}
		}
	}

	return bRet;
}

bool WriteModulePathToRegW(const HKEY hKeyRoot, const wchar_t * szSubKey, const wchar_t * szValueName)
{
	bool bRet = false;
	HKEY hKey = NULL;
	long nRet = 0;
	wchar_t szModulePath[MAX_PATH] = { 0 };

	if (NULL != hKeyRoot && NULL != szSubKey && NULL != szValueName)
	{
		if (0 != GetModuleFileNameW(NULL, szModulePath, MAX_PATH))
		{
			nRet = RegCreateKeyExW(hKeyRoot, szSubKey, 0, NULL, 0, KEY_WRITE | KEY_WOW64_64KEY, NULL, &hKey, NULL);

			if (ERROR_SUCCESS != nRet)
			{
				nRet = RegCreateKeyExW(hKeyRoot, szSubKey, 0, NULL, 0, KEY_WRITE | KEY_WOW64_32KEY, NULL, &hKey, NULL);
			}

			if (ERROR_SUCCESS == nRet && NULL != hKey)
			{
				nRet = RegSetValueExW(hKey, szValueName, 0, REG_SZ, (const BYTE *)szModulePath, (DWORD)wcslen(szModulePath) * sizeof(wchar_t));

				if (ERROR_SUCCESS == nRet)
				{
					bRet = true;
				}

				RegCloseKey(hKey);
			}
		}
	}

	return bRet;
}

bool ReadModulePathFromRegA(const HKEY hKeyRoot, const char * szSubKey, const char * szValueName, char * szModulePath, const DWORD dwSize)
{
	bool bRet = false;
	HKEY hKey = NULL;
	long nRet = 0;
	DWORD dwValueType = 0;
	DWORD dwDataSize = 0;
	FILE * pFile = NULL;

	if (NULL != hKeyRoot && NULL != szSubKey && NULL != szValueName && NULL != szModulePath && 0 != dwSize)
	{
		nRet = RegOpenKeyExA(hKeyRoot, szSubKey, 0, KEY_READ | KEY_WOW64_64KEY, &hKey);

		if (ERROR_SUCCESS != nRet)
		{
			nRet = RegOpenKeyExA(hKeyRoot, szSubKey, 0, KEY_READ | KEY_WOW64_32KEY, &hKey);
		}

		if (ERROR_SUCCESS == nRet && NULL != hKey)
		{
			dwValueType = REG_SZ;
			dwDataSize = dwSize;

			nRet = RegQueryValueExA(hKey, szValueName, NULL, &dwValueType, (LPBYTE)szModulePath, (LPDWORD)&dwDataSize);

			if (ERROR_SUCCESS == nRet)
			{
				if (0 == fopen_s(&pFile, szModulePath, "rb"))
				{
					fclose(pFile);

					bRet = true;
				}
			}

			RegCloseKey(hKey);
		}
	}

	return bRet;
}

bool ReadModulePathFromRegW(const HKEY hKeyRoot, const wchar_t * szSubKey, const wchar_t * szValueName, wchar_t * szModulePath, const DWORD dwSize)
{
	bool bRet = false;
	HKEY hKey = NULL;
	long nRet = 0;
	DWORD dwValueType = 0;
	DWORD dwDataSize = 0;
	FILE * pFile = NULL;

	if (NULL != hKeyRoot && NULL != szSubKey && NULL != szValueName && NULL != szModulePath && 0 != dwSize)
	{
		nRet = RegOpenKeyExW(hKeyRoot, szSubKey, 0, KEY_READ | KEY_WOW64_64KEY, &hKey);

		if (ERROR_SUCCESS != nRet)
		{
			nRet = RegOpenKeyExW(hKeyRoot, szSubKey, 0, KEY_READ | KEY_WOW64_32KEY, &hKey);
		}

		if (ERROR_SUCCESS == nRet && NULL != hKey)
		{
			dwValueType = REG_SZ;
			dwDataSize = dwSize;

			nRet = RegQueryValueExW(hKey, szValueName, NULL, &dwValueType, (LPBYTE)szModulePath, (LPDWORD)&dwDataSize);

			if (ERROR_SUCCESS == nRet)
			{
				if (0 == _wfopen_s(&pFile, szModulePath, L"rb"))
				{
					fclose(pFile);

					bRet = true;
				}
			}

			RegCloseKey(hKey);
		}
	}

	return bRet;
}
