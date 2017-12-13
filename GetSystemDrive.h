
#pragma once

#if defined UNICODE || defined _UNICODE
#	define GetSystemDrive GetSystemDriveW
#else
#	define GetSystemDrive GetSystemDriveA
#endif

//-------------------------------------------------------------------------------------------------
// @brief 获取系统目录的盘符
// @return TRUE 表示成功，其余值表示失败
//-------------------------------------------------------------------------------------------------

extern bool GetSystemDriveA(char * pszDrive, const unsigned int uSize);
extern bool GetSystemDriveW(wchar_t * pszDrive, const unsigned int uSize);
