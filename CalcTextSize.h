
#pragma once

#include "WFLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define CalcTextSizeUseDesktopDC CalcTextSizeWithDesktopDCW
#else
#	define CalcTextSizeUseDesktopDC CalcTextSizeWithDesktopDCA
#endif

extern bool CalcTextSizeWithDesktopDCA(const HFONT hFont, const char * pszText, const int nCalcTextLength, unsigned int & uWidth, unsigned int & uHeight);
extern bool CalcTextSizeWithDesktopDCW(const HFONT hFont, const wchar_t * pszText, const int nCalcTextLength, unsigned int & uWidth, unsigned int & uHeight);
