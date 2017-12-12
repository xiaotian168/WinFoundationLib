
#pragma once

#if defined UNICODE || defined _UNICODE
#	define BuildRandomString BuildRandomStringW
#else
#	define BuildRandomString BuildRandomStringA
#endif

/**
** @brief 产生包含随机字符的字符串
** @param pszRandomString 保存随机字符的字符串缓冲区
** @param uBufferSize 保存随机字符的字符串缓冲区大小（单位：字符）
** @param uRandomStringLength 产生多少个随机字符
** @return 非 0 表示成功，0 表示失败
** @note
**
** 本函数生成的随机字符，全部都是可打印字符
**/
extern int BuildRandomStringA(char * pszRandomString, const unsigned int uBufferSize, const unsigned int uRandomStringLength);
extern int BuildRandomStringW(wchar_t * pszRandomString, const unsigned int uBufferSize, const unsigned int uRandomStringLength);
