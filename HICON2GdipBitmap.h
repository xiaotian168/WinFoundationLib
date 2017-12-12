
#pragma once

#include "WFLibConfig.h"

/**
** @brief ͨ�� HICON ���� GDI+ Bitmap ����
*/
extern Gdiplus::Bitmap * MakeGDIPBitmapFromHICON(const HICON hIcon, Gdiplus::Graphics * pGraph, const Gdiplus::Color & BgColor = Gdiplus::Color(0, 255, 255, 255));
