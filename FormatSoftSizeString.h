
#pragma once

#if defined UNICODE || defined _UNICODE
#	define FormatSoftSizeString FormatSoftSizeStringW
#else
#	define FormatSoftSizeString FormatSoftSizeStringA
#endif

/**
** @brief 将指定软件大小，格式化为字符串描述
** @param[in] uSoftSizeInBytes 软件大小（单位：Byte）
** @param[out] szString 保存格式化后的字符串
** @param[in] dwSize szString 参数的容量（单位：字符）
** @return TRUE 表示成功，其余值表示失败
**/
extern bool FormatSoftSizeStringA(const unsigned long long uSoftSizeInByte, char * szString, const unsigned int uSize);
extern bool FormatSoftSizeStringW(const unsigned long long uSoftSizeInByte, wchar_t * szString, const unsigned int uSize);
