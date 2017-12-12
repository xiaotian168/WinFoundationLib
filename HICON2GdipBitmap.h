
#pragma once

#include "WFLibConfig.h"

extern Gdiplus::Bitmap * MakeGDIPBitmapFromHICON(const HICON hIcon, Gdiplus::Graphics * pGraph, const Gdiplus::Color & BgColor = Gdiplus::Color(0, 255, 255, 255));
