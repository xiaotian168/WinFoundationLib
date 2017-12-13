
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
// @brief ����ָ�����򣬲��ȴ�ָ��ʱ��
// @param[in] szApp ����·��
// @param[in] szCmdLine �����в���
// @param[in] uShowFlag ������ʾ���
// @param[in] uWaitTimeOut �ȴ���ʱ
// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
//-----------------------------------------------------------------------------------------------------------------------------
extern bool RunAppWaitA(const char * szApp, const char * szCmdLine, const unsigned int uShowFlag, const unsigned int uWaitTimeOut = INFINITE);
extern bool RunAppWaitW(const wchar_t * szApp, const wchar_t * szCmdLine, const unsigned int uShowFlag, const unsigned int uWaitTimeOut = INFINITE);

//-----------------------------------------------------------------------------------------------------------------------------
// @brief ǿ�ƽ���ָ���ļ�·���еĿ�ִ�г���
// @param[in] uShowFlag ������ʾ���
// @param[in] uWaitTimeOut �ȴ���ʱ
// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
//-----------------------------------------------------------------------------------------------------------------------------
extern bool KillFullPathExeA(const char * szPath, const unsigned int uShowFlag, const unsigned int uWaitTimeOut = INFINITE);
extern bool KillFullPathExeW(const wchar_t * szPath, const unsigned int uShowFlag, const unsigned int uWaitTimeOut = INFINITE);
