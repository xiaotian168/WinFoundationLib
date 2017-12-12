
#pragma once

#if defined UNICODE || defined _UNICODE
#	define CalcFileSize CalcFileSizeW
#else
#	define CalcFileSize CalcFileSizeA
#endif

//----------------------------------------------------------------------------------------------------------------------------------
// @brief ����ָ���ļ���С����λ���ֽڣ�
//----------------------------------------------------------------------------------------------------------------------------------

extern unsigned long long CalcFileSizeA(const char * szFile);
extern unsigned long long CalcFileSizeW(const wchar_t * szFile);
