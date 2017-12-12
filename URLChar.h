
#pragma once

#if defined UNICODE || defined _UNICODE
#	define IsURLCharSpecialChar IsURLCharSpecialCharW
#	define ConvertURLSpecialChar ConvertURLSpecialCharW
#	define CalcURLStringSizeAfterConvert CalcURLStringSizeAfterConvertW
#	define ConvertURL ConvertURLW
#else
#	define IsURLCharSpecialChar IsURLCharSpecialCharA
#	define ConvertURLSpecialChar ConvertURLSpecialCharA
#	define CalcURLStringSizeAfterConvert CalcURLStringSizeAfterConvertA
#	define ConvertURL ConvertURLA
#endif

/**
** @brief 判断指定字符是否转义字符
** @param[in] c
** @return true 表示成功，false 表示失败
**/
extern bool IsURLCharSpecialCharA(const char c);
extern bool IsURLCharSpecialCharW(const wchar_t c);

/**
** @brief 将给定字符格式化为 16 进制字符串
** @param[in] c
** @param[out] szC
** @param[in] dwSize
** @return true 表示成功，false 表示失败
**/
extern bool ConvertURLSpecialCharA(const char c, char * szC, const unsigned int uSize);
extern bool ConvertURLSpecialCharW(const wchar_t c, wchar_t * szC, const unsigned int uSize);

/**
** @brief 计算指定字符串进行转义后需要多大缓冲区
** @param[in] pszURL 要进行处理的字符串
** @return 字符串进行转义后的缓冲区大小
**/
extern unsigned int CalcURLStringSizeAfterConvertA(const char * pszURL);
extern unsigned int CalcURLStringSizeAfterConvertW(const wchar_t * pszURL);

/**
** @brief 将指定 URL 中的转义字符进行转义
** @param[in] pszURL 要进行转义的字符串
** @param[out] pszURLAfterConvert 保存转义后的字符串缓冲区
** @param[in] uSize pszURLAfterConvert 缓冲区大小（单位：字符）
** @return true 表示成功，false 表示失败
**/
extern bool ConvertURLA(const char * pszURL, char * pszURLAfterConvert, const unsigned int uSize);
extern bool ConvertURLW(const wchar_t * pszURL, wchar_t * pszURLAfterConvert, const unsigned int uSize);
