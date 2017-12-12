
#include "TaskBar.h"

bool RegistgerAppBarMessage(const HWND hWnd, const unsigned int uMsg)
{
	bool bRet = false;

	APPBARDATA AppBarData = { 0 };
	if (IsWindow(hWnd) && uMsg)
	{
		AppBarData.cbSize = sizeof(AppBarData);
		AppBarData.hWnd = hWnd;
		AppBarData.uCallbackMessage = uMsg;

		SHAppBarMessage(ABM_NEW, &AppBarData);

		bRet = true;
	}

	return bRet;
}
