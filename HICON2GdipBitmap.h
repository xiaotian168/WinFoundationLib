
#pragma once

#include "WFLibConfig.h"

/**
** @brief 通过 HICON 创建 GDI+ Bitmap 对象
*/
extern Gdiplus::Bitmap * MakeGDIPBitmapFromHICON(const HICON hIcon, Gdiplus::Graphics * pGraph, const Gdiplus::Color & BgColor = Gdiplus::Color(0, 255, 255, 255));
