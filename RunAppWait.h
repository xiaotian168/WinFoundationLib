
#pragma once

#include "WFLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define RunAppWait RunAppWaitW
#	define KillFullPathExe KillFullPathExeW
#else
#	define RunAppWait RunAppWaitA
#	define KillFullPathExe KillFullPathExeA
#endif

//-----------------------------------------------------------------------------------------------------------------------------
// @brief 运行指定程序，并等待指定时长
// @param[in] szApp 程序路径
// @param[in] szCmdLine 命令行参数
// @param[in] uShowFlag 窗口显示标记
// @param[in] uWaitTimeOut 等待超时
// @return TRUE 表示成功，其余值表示失败
//-----------------------------------------------------------------------------------------------------------------------------
extern bool RunAppWaitA(const char * szApp, const char * szCmdLine, const unsigned int uShowFlag, const unsigned int uWaitTimeOut = INFINITE);
extern bool RunAppWaitW(const wchar_t * szApp, const wchar_t * szCmdLine, const unsigned int uShowFlag, const unsigned int uWaitTimeOut = INFINITE);

//-----------------------------------------------------------------------------------------------------------------------------
// @brief 强制结束指定文件路径中的可执行程序
// @param[in] uShowFlag 窗口显示标记
// @param[in] uWaitTimeOut 等待超时
// @return TRUE 表示成功，其余值表示失败
//-----------------------------------------------------------------------------------------------------------------------------
extern bool KillFullPathExeA(const char * szPath, const unsigned int uShowFlag, const unsigned int uWaitTimeOut = INFINITE);
extern bool KillFullPathExeW(const wchar_t * szPath, const unsigned int uShowFlag, const unsigned int uWaitTimeOut = INFINITE);
