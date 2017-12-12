
#include "CalcTextSize.h"

bool CalcTextSizeWithDesktopDCA(const HFONT hFont, const char * pszText, const int nCalcTextLength, unsigned int & uWidth, unsigned int & uHeight)
{
	bool bRet = false;
	HWND hWndDesktop = 0;
	HDC hDCDesktop = 0;
	HGDIOBJ hFontOld = 0;
	SIZE TextSize = { 0 };

	if (hFont && pszText)
	{
		hWndDesktop = GetDesktopWindow();

		if (hWndDesktop)
		{
			hDCDesktop = GetDC(hWndDesktop);

			if (hDCDesktop)
			{
				hFontOld = SelectObject(hDCDesktop, hFont);

				if (GetTextExtentPoint32A(hDCDesktop, pszText, nCalcTextLength, &TextSize))
				{
					uWidth = TextSize.cx;
					uHeight = TextSize.cy;

					bRet = true;
				}

				SelectObject(hDCDesktop, hFontOld);

				ReleaseDC(hWndDesktop, hDCDesktop);
				hDCDesktop = 0;
			}

			hWndDesktop = 0;
		}
	}

	return bRet;
}

bool CalcTextSizeWithDesktopDCW(const HFONT hFont, const wchar_t * pszText, const int nCalcTextLength, unsigned int & uWidth, unsigned int & uHeight)
{
	bool bRet = false;
	HWND hWndDesktop = 0;
	HDC hDCDesktop = 0;
	HGDIOBJ hFontOld = 0;
	SIZE TextSize = { 0 };

	if (hFont && pszText)
	{
		hWndDesktop = GetDesktopWindow();

		if (hWndDesktop)
		{
			hDCDesktop = GetDC(hWndDesktop);

			if (hDCDesktop)
			{
				hFontOld = SelectObject(hDCDesktop, hFont);

				if (GetTextExtentPoint32W(hDCDesktop, pszText, nCalcTextLength, &TextSize))
				{
					uWidth = TextSize.cx;
					uHeight = TextSize.cy;

					bRet = true;
				}

				SelectObject(hDCDesktop, hFontOld);

				ReleaseDC(hWndDesktop, hDCDesktop);
				hDCDesktop = 0;
			}

			hWndDesktop = 0;
		}
	}

	return bRet;
}
