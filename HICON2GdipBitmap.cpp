
#include "HICON2GdipBitmap.h"

Gdiplus::Bitmap * MakeGDIPBitmapFromHICON(const HICON hIcon, Gdiplus::Graphics * pGraph, const Gdiplus::Color & BgColor)
{
	Gdiplus::Bitmap * pBmp = 0;
	//Gdiplus::BitmapData BmpData;
	//Gdiplus::Rect rcLock;
	Gdiplus::Color clrPixel;
	ICONINFO IconInfo = { 0 };
	//BITMAPINFO BmpInfo = { 0 };
	BITMAP Bmp = { 0 };

	// if (hIcon && pGraph)
	if (hIcon)
	{
		if (GetIconInfo(hIcon, &IconInfo))
		{
			if (GetObject(IconInfo.hbmColor, sizeof(Bmp), &Bmp))
			{
				if (32 == Bmp.bmBitsPixel)
				{
					auto pBmpTemp = Gdiplus::Bitmap::FromHBITMAP(IconInfo.hbmColor, 0);
					if (pBmpTemp)
					{
						for (int i = 0; i < Bmp.bmHeight; ++i)
						{
							for (int j = 0; j < Bmp.bmWidth; ++j)
							{
								pBmpTemp->GetPixel(j, i, &clrPixel);
								if (255 == clrPixel.GetA() && 0 == clrPixel.GetR() && 0 == clrPixel.GetG() && 0 == clrPixel.GetB())
								{
									pBmpTemp->SetPixel(j, i, BgColor);
								}
							}
						}

						pBmp = pBmpTemp;

						//rcLock.X = 0;
						//rcLock.Y = 0;
						//rcLock.Width = Bmp.bmWidth;
						//rcLock.Height = Bmp.bmHeight;

						//if (Gdiplus::Ok == pBmpTemp->LockBits(&rcLock, Gdiplus::ImageLockModeRead, pBmpTemp->GetPixelFormat(), &BmpData))
						//{
						//	pBmp = new Gdiplus::Bitmap(BmpData.Width, BmpData.Height, BmpData.Stride, PixelFormat32bppARGB, (BYTE*)BmpData.Scan0);

						//	pBmpTemp->UnlockBits(&BmpData);
						//}

						//delete pBmpTemp;
						//pBmpTemp = 0;
					}
				}
				else
				{
					pBmp = Gdiplus::Bitmap::FromHICON(hIcon);
				}
			}
		}
	}

	return pBmp;
}
