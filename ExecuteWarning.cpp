
#include "ExecuteWarning.h"

static CExecuteWarningRegInfo g_ExecWarningRegInfo;

static const HKEY REG_ROOTKEY_RISKFILETYPES = HKEY_CURRENT_USER;
static const TCHAR * REG_SUBKEY_RISKFILETYPES = _T("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Associations");
static const TCHAR * REG_VALUENAME_LOWRISKFILETYPES = _T("LowRiskFileTypes");
static const TCHAR * REG_VALUENAME_MODRISKFILETYPES = _T("ModRiskFileTypes");
static const TCHAR * REG_VALUENAME_HIGHRISKFILETYPES = _T("HighRiskFileTypes");

BOOL BackupExecuteWarningRegInfo(void)
{
	BOOL bRet = TRUE;
	HKEY hKey = 0;
	REGSAM RegSam = 0;
	CExecuteWarningRegInfo RegInfo;
	DWORD dwDataSize = 0;
	LSTATUS lStatus = 0;

	RegSam = KEY_CREATE_SUB_KEY | KEY_QUERY_VALUE | KEY_WOW64_64KEY;

	if (ERROR_SUCCESS != RegCreateKeyEx(REG_ROOTKEY_RISKFILETYPES, REG_SUBKEY_RISKFILETYPES, 0, 0, 0, RegSam, 0, &hKey, 0))
	{
		RegSam = KEY_CREATE_SUB_KEY | KEY_QUERY_VALUE | KEY_WOW64_32KEY;

		if (ERROR_SUCCESS != RegCreateKeyEx(REG_ROOTKEY_RISKFILETYPES, REG_SUBKEY_RISKFILETYPES, 0, 0, 0, RegSam, 0, &hKey, 0))
		{
			bRet = FALSE;
		}
	}

	if (TRUE == bRet && 0 != hKey)
	{
		dwDataSize = sizeof(RegInfo.szOldLowRiskFileTypes);
		lStatus = RegQueryValueEx(hKey, REG_VALUENAME_LOWRISKFILETYPES, 0, 0, (LPBYTE)RegInfo.szOldLowRiskFileTypes, &dwDataSize);

		if (ERROR_SUCCESS == lStatus || ERROR_FILE_NOT_FOUND == lStatus)
		{
			dwDataSize = sizeof(RegInfo.szOldLowRiskFileTypes);
			lStatus = RegQueryValueEx(hKey, REG_VALUENAME_MODRISKFILETYPES, 0, 0, (LPBYTE)RegInfo.szOldModRiskFileTypes, &dwDataSize);

			if (ERROR_SUCCESS == lStatus || ERROR_FILE_NOT_FOUND == lStatus)
			{
				dwDataSize = sizeof(RegInfo.szOldLowRiskFileTypes);
				lStatus = RegQueryValueEx(hKey, REG_VALUENAME_HIGHRISKFILETYPES, 0, 0, (LPBYTE)RegInfo.szOldHighRiskFileTypes, &dwDataSize);

				if (ERROR_SUCCESS == lStatus || ERROR_FILE_NOT_FOUND == lStatus)
				{
					g_ExecWarningRegInfo = RegInfo;
				}
				else
				{
					bRet = FALSE;
				}
			}
			else
			{
				bRet = FALSE;
			}
		}
		else
		{
			bRet = FALSE;
		}

		RegCloseKey(hKey);
	}

	return bRet;
}

BOOL RestoreExecuteWarningRegInfo(void)
{
	BOOL bRet = TRUE;
	HKEY hKey = 0;
	REGSAM RegSam = 0;

	RegSam = KEY_SET_VALUE | KEY_WOW64_64KEY;

	if (ERROR_SUCCESS != RegCreateKeyEx(REG_ROOTKEY_RISKFILETYPES, REG_SUBKEY_RISKFILETYPES, 0, 0, 0, RegSam, 0, &hKey, 0))
	{
		RegSam = KEY_SET_VALUE | KEY_WOW64_32KEY;

		if (ERROR_SUCCESS != RegCreateKeyEx(REG_ROOTKEY_RISKFILETYPES, REG_SUBKEY_RISKFILETYPES, 0, 0, 0, RegSam, 0, &hKey, 0))
		{
			bRet = FALSE;
		}
	}

	if (TRUE == bRet && 0 != hKey)
	{
		if (ERROR_SUCCESS == RegSetValueEx(hKey, REG_VALUENAME_LOWRISKFILETYPES, 0, REG_SZ, (LPBYTE)g_ExecWarningRegInfo.szOldLowRiskFileTypes, _tcslen(g_ExecWarningRegInfo.szOldLowRiskFileTypes) * sizeof(TCHAR)))
		{
			if (ERROR_SUCCESS == RegSetValueEx(hKey, REG_VALUENAME_MODRISKFILETYPES, 0, REG_SZ, (LPBYTE)g_ExecWarningRegInfo.szOldModRiskFileTypes, _tcslen(g_ExecWarningRegInfo.szOldModRiskFileTypes) * sizeof(TCHAR)))
			{
				if (ERROR_SUCCESS == RegSetValueEx(hKey, REG_VALUENAME_HIGHRISKFILETYPES, 0, REG_SZ, (LPBYTE)g_ExecWarningRegInfo.szOldHighRiskFileTypes, _tcslen(g_ExecWarningRegInfo.szOldHighRiskFileTypes) * sizeof(TCHAR)))
				{

				}
				else
				{
					bRet = FALSE;
				}
			}
			else
			{
				bRet = FALSE;
			}
		}
		else
		{
			bRet = FALSE;
		}

		RegCloseKey(hKey);
	}

	return bRet;
}

BOOL WriteExecuteWarningRegInfo(
	const TCHAR * szLowRiskFileTypes,
	const TCHAR * szModRiskFileTypes,
	const TCHAR * szHighRiskFileTypes)
{
	BOOL bRet = TRUE;
	HKEY hKey = 0;
	REGSAM RegSam = 0;
	LSTATUS lStatus = 0;

	RegSam = KEY_SET_VALUE | KEY_WOW64_64KEY;

	if (ERROR_SUCCESS != RegCreateKeyEx(REG_ROOTKEY_RISKFILETYPES, REG_SUBKEY_RISKFILETYPES, 0, 0, 0, RegSam, 0, &hKey, 0))
	{
		RegSam = KEY_SET_VALUE | KEY_WOW64_32KEY;

		if (ERROR_SUCCESS != RegCreateKeyEx(REG_ROOTKEY_RISKFILETYPES, REG_SUBKEY_RISKFILETYPES, 0, 0, 0, RegSam, 0, &hKey, 0))
		{
			bRet = FALSE;
		}
	}

	if (TRUE == bRet && 0 != hKey)
	{
		if (0 != szLowRiskFileTypes)
		{
			if (ERROR_SUCCESS != RegSetValueEx(hKey, REG_VALUENAME_LOWRISKFILETYPES, 0, REG_SZ, (LPBYTE)szLowRiskFileTypes, _tcslen(szLowRiskFileTypes) * sizeof(TCHAR)))
			{
				bRet = FALSE;
			}
		}

		if (0 != szModRiskFileTypes)
		{
			if (ERROR_SUCCESS != RegSetValueEx(hKey, REG_VALUENAME_MODRISKFILETYPES, 0, REG_SZ, (LPBYTE)szModRiskFileTypes, _tcslen(szModRiskFileTypes) * sizeof(TCHAR)))
			{
				bRet = FALSE;
			}
		}

		if (0 != szHighRiskFileTypes)
		{
			if (ERROR_SUCCESS != RegSetValueEx(hKey, REG_VALUENAME_HIGHRISKFILETYPES, 0, REG_SZ, (LPBYTE)szHighRiskFileTypes, _tcslen(szHighRiskFileTypes) * sizeof(TCHAR)))
			{
				bRet = FALSE;
			}
		}

		RegCloseKey(hKey);
	}

	return bRet;
}
