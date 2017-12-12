
#include "PostProcessWndMsg.h"

#define ENABLE_LOG
#undef ENABLE_LOG

static wchar_t g_szProcessNameW[MAX_PATH] = { 0 };
static wchar_t g_szWndClassNameW[MAX_PATH] = { 0 };
static wchar_t g_szWndTitleW[MAX_PATH] = { 0 };

static char g_szProcessNameA[MAX_PATH] = { 0 };
static char g_szWndClassNameA[MAX_PATH] = { 0 };
static char g_szWndTitleA[MAX_PATH] = { 0 };

static unsigned int g_uWndMsg = 0;
static WPARAM g_wParam = 0;
static LPARAM g_lParam = 0;

static bool g_bAllowMsgPostToSelf = false;
static bool g_bPostMessageSucceeded = false;

// PCT �� ProcessName ��ClassName �� Title ����д
// ˵����ö�ٻص�����ͨ������ģ���������������봰�ڱ������ƥ��

static BOOL CALLBACK EnumWndProcPCTW(HWND hWnd, LPARAM lParam)
{
	BOOL bRet = TRUE;
	DWORD dwProcessID = 0;
	HANDLE hProcess = INVALID_HANDLE_VALUE;
	wchar_t szFullProcessImageNameW[MAX_PATH] = { 0 };
	wchar_t szWndClassNameW[MAX_PATH] = { 0 };
	wchar_t szWndTitleW[MAX_PATH] = { 0 };
	DWORD dwSize = 0;
	DWORD_PTR dwResult = 0;

	if (GetWindowThreadProcessId(hWnd, &dwProcessID) && dwProcessID)
	{
#if defined ENABLE_LOG
		DebugUtil::OutputFormatDebugStringW(L"�ҵ����� ID [0x%.8X] \n", dwProcessID);
#endif

		hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, false, dwProcessID);
		if (hProcess)
		{
#if defined ENABLE_LOG
			DebugUtil::OutputFormatDebugStringW(L"�ҵ����̾�� [0x%.8X] \n", hProcess);
#endif

			// �����������Ͷ����Ϣ��
			//
			// 1 - ��������ϢͶ�͵������߽��̣����ҵ�ǰ��ö�ٵ��Ľ��̲��ǵ����߽���
			// 2 - ������ϢͶ�͵������߽���

			if ((true != g_bAllowMsgPostToSelf && GetCurrentProcess() != hProcess) || g_bAllowMsgPostToSelf)
			{
				dwSize = MAX_PATH;

				if(GetProcessImageFileNameW(hProcess, szFullProcessImageNameW, dwSize))
				{
#if defined ENABLE_LOG
					DebugUtil::OutputFormatDebugStringW(L"����ģ���ļ��� [%s] \n", szFullProcessImageNameW);
#endif

					PathStripPathW(szFullProcessImageNameW);

					if (0 == wcscmp(szFullProcessImageNameW, g_szProcessNameW))
					{
#if defined ENABLE_LOG
						DebugUtil::OutputFormatDebugStringW(L"�ҵ�ģ�� [%s] \n", g_szProcessNameW);
#endif

						if (GetClassNameW(hWnd, szWndClassNameW, MAX_PATH))
						{
							if (0 == wcscmp(szWndClassNameW, g_szWndClassNameW))
							{
#if defined ENABLE_LOG
								DebugUtil::OutputFormatDebugStringW(L"�ҵ������� [%s] \n", g_szWndClassNameW);
#endif

								// GetWindowText() ������������Ӧ�Ĵ���ʱ��������ʹ�� SendMessageTimeout() �Խ���
								// ���г�ʱ�Ļ�ȡ���ڱ���������ⳤʱ������

								if (SendMessageTimeoutW(hWnd, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)szWndTitleW, SMTO_BLOCK, 100, &dwResult))
								{
									if (0 == wcscmp(szWndTitleW, g_szWndTitleW))
									{
#if defined ENABLE_LOG
										DebugUtil::OutputFormatDebugStringW(L"�ҵ����ڱ��� [%s] \n", g_szWndTitleW);
#endif

										if (PostMessageW(hWnd, g_uWndMsg, g_wParam, g_lParam))
										{
#if defined ENABLE_LOG
											DebugUtil::OutputFormatDebugStringA("PostMessageW() �ɹ��� \n");
#endif

											g_bPostMessageSucceeded = true;
										}
										else
										{
#if defined ENABLE_LOG
											DebugUtil::OutputFormatDebugStringA("PostMessageW() ʧ���ˣ������� [%d] \n", GetLastError());
#endif
										}

										bRet = FALSE;
									}
								}
								else
								{
#if defined ENABLE_LOG
									DebugUtil::OutputFormatDebugStringA("SendMessageTimeoutW() ʧ���ˣ������� [%d] \n", GetLastError());
#endif
								}
							}
						}
						else
						{
#if defined ENABLE_LOG
							DebugUtil::OutputFormatDebugStringA("GetClassNameW() ʧ���ˣ������� [%d] \n", GetLastError());
#endif
						}
					}
				}
				else
				{
#if defined ENABLE_LOG
					DebugUtil::OutputFormatDebugStringA("GetModuleFileNameExW() ʧ���ˣ������� [%d] \n", GetLastError());
#endif
				}
			}

			CloseHandle(hProcess);
		}
		else
		{
#if defined ENABLE_LOG
			DebugUtil::OutputFormatDebugStringA("OpenProcess() ʧ���ˣ������� [%d] \n", GetLastError());
#endif
		}
	}
	else
	{
#if defined ENABLE_LOG
		DebugUtil::OutputFormatDebugStringA("GetWindowThreadProcessId() ʧ���ˣ������� [%d] \n", GetLastError());
#endif
	}

	return bRet;
}

static BOOL CALLBACK EnumWndProcPCTA(HWND hWnd, LPARAM lParam)
{
	BOOL bRet = TRUE;
	DWORD dwProcessID = 0;
	HANDLE hProcess = INVALID_HANDLE_VALUE;
	char szFullProcessImageNameA[MAX_PATH] = { 0 };
	char szWndClassNameA[MAX_PATH] = { 0 };
	char szWndTitleA[MAX_PATH] = { 0 };
	DWORD dwSize = 0;
	DWORD_PTR dwResult = 0;

	if (GetWindowThreadProcessId(hWnd, &dwProcessID) && dwProcessID)
	{
		hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, false, dwProcessID);
		if (hProcess)
		{
			if ((true != g_bAllowMsgPostToSelf && GetCurrentProcess() != hProcess) || g_bAllowMsgPostToSelf)
			{
				dwSize = MAX_PATH;

				if (GetProcessImageFileNameA(hProcess, szFullProcessImageNameA, dwSize))
				{
					PathStripPathA(szFullProcessImageNameA);

					if (0 == strcmp(szFullProcessImageNameA, g_szProcessNameA))
					{
						if (GetClassNameA(hWnd, szWndClassNameA, MAX_PATH))
						{
							if (0 == strcmp(szWndClassNameA, g_szWndClassNameA))
							{
								if (SendMessageTimeoutA(hWnd, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)szWndTitleA, SMTO_BLOCK, 100, &dwResult))
								{
									if (0 == strcmp(szWndTitleA, g_szWndTitleA))
									{
										if (PostMessageA(hWnd, g_uWndMsg, g_wParam, g_lParam))
										{
											g_bPostMessageSucceeded = true;
										}
										else
										{
#if defined ENABLE_LOG
											DebugUtil::OutputFormatDebugStringA("PostMessageA() ʧ���ˣ������� [%d] \n", GetLastError());
#endif
										}

										bRet = FALSE;
									}
								}
								else
								{
#if defined ENABLE_LOG
									DebugUtil::OutputFormatDebugStringA("SendMessageTimeoutA() ʧ���ˣ������� [%d] \n", GetLastError());
#endif
								}
							}
						}
						else
						{
#if defined ENABLE_LOG
							DebugUtil::OutputFormatDebugStringA("GetClassNameA() ʧ���ˣ������� [%d] \n", GetLastError());
#endif
						}
					}
				}
				else
				{
#if defined ENABLE_LOG
					DebugUtil::OutputFormatDebugStringA("GetModuleFileNameExA() ʧ���ˣ������� [%d] \n", GetLastError());
#endif
				}
			}

			CloseHandle(hProcess);
		}
	}

	return bRet;
}

// CT �� ClassName �� Title ����д
// ˵����ö�ٻص�����ͨ�����������봰�ڱ������ƥ��

static BOOL CALLBACK EnumWndProcCTA(HWND hWnd, LPARAM lParam)
{
	BOOL bRet = TRUE;
	char szWndClassName[MAX_PATH] = { 0 };
	char szTitle[MAX_PATH] = { 0 };
	DWORD dwResult = 0;

	if (GetClassNameA(hWnd, szWndClassName, MAX_PATH))
	{
		if (SendMessageTimeoutA(hWnd, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)szTitle, SMTO_BLOCK, 100, &dwResult))
		{
			if (0 == _stricmp(g_szWndClassNameA, szWndClassName) && 0 == _stricmp(g_szWndTitleA, szTitle))
			{
				if (PostMessageA(hWnd, g_uWndMsg, g_wParam, g_lParam))
				{
					g_bPostMessageSucceeded = true;
				}

				bRet = FALSE;
			}
		}
	}

	return bRet;
}

static BOOL CALLBACK EnumWndProcCTW(HWND hWnd, LPARAM lParam)
{
	BOOL bRet = TRUE;
	wchar_t szWndClassName[MAX_PATH] = { 0 };
	wchar_t szTitle[MAX_PATH] = { 0 };
	DWORD dwResult = 0;

	if (GetClassNameW(hWnd, szWndClassName, MAX_PATH))
	{
		if (SendMessageTimeoutW(hWnd, WM_GETTEXT, (WPARAM)MAX_PATH, (LPARAM)szTitle, SMTO_BLOCK, 100, &dwResult))
		{
			if (0 == _wcsicmp(g_szWndClassNameW, szWndClassName) && 0 == _wcsicmp(g_szWndTitleW, szTitle))
			{
				if (PostMessageW(hWnd, g_uWndMsg, g_wParam, g_lParam))
				{
					g_bPostMessageSucceeded = true;
				}

				bRet = FALSE;
			}
		}
	}

	return bRet;
}

bool PostProcessWndMsgW(
	const wchar_t * szProcessName,
	const wchar_t * szWndClassName,
	const wchar_t * szWndTitle,
	const unsigned int uWndMsg,
	const WPARAM wParam,
	const LPARAM lParam,
	const bool bAllowMsgPostToSelf)
{
	bool bRet = false;

#if defined ENABLE_LOG
	DebugUtil::OutputFormatDebugStringA("PostProcessWndMsgW() \n");
#endif

	if (szProcessName && szWndClassName && szWndTitle)
	{
		wcscpy_s(g_szProcessNameW, MAX_PATH, szProcessName);
		wcscpy_s(g_szWndClassNameW, MAX_PATH, szWndClassName);
		wcscpy_s(g_szWndTitleW, MAX_PATH, szWndTitle);

		g_uWndMsg = uWndMsg;
		g_wParam = wParam;
		g_lParam = lParam;

		g_bAllowMsgPostToSelf = bAllowMsgPostToSelf;
		g_bPostMessageSucceeded = false;

		if (0 == EnumWindows(EnumWndProcPCTW, 0))
		{
			bRet = g_bPostMessageSucceeded;
		}
	}

	return bRet;
}

bool PostProcessWndMsgA(
	const char * szProcessName,
	const char * szWndClassName,
	const char * szWndTitle,
	const unsigned int uWndMsg,
	const WPARAM wParam,
	const LPARAM lParam,
	const bool bAllowMsgPostToSelf)
{
	bool bRet = false;

	if (szProcessName && szWndClassName && szWndTitle)
	{
		strcpy_s(g_szProcessNameA, MAX_PATH, szProcessName);
		strcpy_s(g_szWndClassNameA, MAX_PATH, szWndClassName);
		strcpy_s(g_szWndTitleA, MAX_PATH, szWndTitle);

		g_uWndMsg = uWndMsg;
		g_wParam = wParam;
		g_lParam = lParam;

		g_bAllowMsgPostToSelf = bAllowMsgPostToSelf;
		g_bPostMessageSucceeded = false;

		if (0 == EnumWindows(EnumWndProcPCTA, 0))
		{
			bRet = g_bPostMessageSucceeded;
		}
	}

	return bRet;
}

bool PostMsgWithWndClassTitleA(const char * szWndClassName, const char * szWndTitle, const unsigned int uWndMsg, const WPARAM wParam, const LPARAM lParam)
{
	bool bRet = false;

	if (szWndClassName && szWndTitle)
	{
		strcpy_s(g_szWndClassNameA, MAX_PATH, szWndClassName);
		strcpy_s(g_szWndTitleA, MAX_PATH, szWndTitle);

		g_uWndMsg = uWndMsg;
		g_wParam = wParam;
		g_lParam = lParam;

		if (0 == EnumWindows(EnumWndProcCTA, 0))
		{
			bRet = g_bPostMessageSucceeded;
		}
	}

	return bRet;
}

bool PostMsgWithWndClassTitleW(const wchar_t * szWndClassName, const wchar_t * szWndTitle, const unsigned int uWndMsg, const WPARAM wParam, const LPARAM lParam)
{
	bool bRet = false;

	if (szWndClassName && szWndTitle)
	{
		wcscpy_s(g_szWndClassNameW, MAX_PATH, szWndClassName);
		wcscpy_s(g_szWndTitleW, MAX_PATH, szWndTitle);

		g_uWndMsg = uWndMsg;
		g_wParam = wParam;
		g_lParam = lParam;

		if (0 == EnumWindows(EnumWndProcCTW, 0))
		{
			bRet = g_bPostMessageSucceeded;
		}
	}

	return bRet;
}
