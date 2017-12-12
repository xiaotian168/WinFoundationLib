
#pragma once

#if defined UNICODE || defined _UNICODE
#	define IsFontFamilyExist IsFontFamilyExistW
#else
#	define IsFontFamilyExist IsFontFamilyExistA
#endif

/**
** @brief 计算系统中安装了多少种字体
** @return 系统中已经安装的字体数量
**/
extern bool EnumFontCount(unsigned int & uFontCount);

/**
** @brief 判断系统中是否安装了指定字体家族字体
** @param[in] szFontFamilyName 字体家族名称
** @return TRUE 表示已经安装，其余值表示没有安装
**/
extern bool IsFontFamilyExistA(const char * szFontFamilyName);
extern bool IsFontFamilyExistW(const wchar_t * szFontFamilyName);
