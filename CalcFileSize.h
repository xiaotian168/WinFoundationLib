
#pragma once

#if defined UNICODE || defined _UNICODE
#	define CalcFileSize CalcFileSizeW
#else
#	define CalcFileSize CalcFileSizeA
#endif

//----------------------------------------------------------------------------------------------------------------------------------
// @brief 计算指定文件大小（单位：字节）
//----------------------------------------------------------------------------------------------------------------------------------

extern unsigned long long CalcFileSizeA(const char * szFile);
extern unsigned long long CalcFileSizeW(const wchar_t * szFile);
