
#pragma once

#include "WFLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define CalcTextSizeUseDesktopDC CalcTextSizeWithDesktopDCW
#else
#	define CalcTextSizeUseDesktopDC CalcTextSizeWithDesktopDCA
#endif

/**
** @brief 使用桌面 HDC 计算指定字符串的绘制大小
*/
extern bool CalcTextSizeWithDesktopDCA(const HFONT hFont, const char * pszText, const int nCalcTextLength, unsigned int & uWidth, unsigned int & uHeight);
extern bool CalcTextSizeWithDesktopDCW(const HFONT hFont, const wchar_t * pszText, const int nCalcTextLength, unsigned int & uWidth, unsigned int & uHeight);
