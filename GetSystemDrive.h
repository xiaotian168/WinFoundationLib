
#pragma once

#if defined UNICODE || defined _UNICODE
#	define GetSystemDrive GetSystemDriveW
#else
#	define GetSystemDrive GetSystemDriveA
#endif

//-------------------------------------------------------------------------------------------------
// @brief ��ȡϵͳĿ¼���̷�
// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
//-------------------------------------------------------------------------------------------------

extern bool GetSystemDriveA(char * pszDrive, const unsigned int uSize);
extern bool GetSystemDriveW(wchar_t * pszDrive, const unsigned int uSize);
