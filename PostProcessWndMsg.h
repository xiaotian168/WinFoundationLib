
#pragma once

#include "WFLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define PostProcessWndMsg PostProcessWndMsgW
#	define PostMsgWithWndClassTitle PostMsgWithWndClassTitleW
#else
#	define PostProcessWndMsg PostProcessWndMsgA
#	define PostMsgWithWndClassTitle PostMsgWithWndClassTitleA
#endif

/**
** @brief ��ָ�����̵�ָ������Ͷ��ָ����Ϣ
** @param[in] szProcessName ������
** @param[in] szWndClassName ��������
** @param[in] szWndTitle ���ڱ���
** @param[in] uWndMsg��wParam��lParam ҪͶ�͵���Ϣ���Լ���Ϣ�ĸ�������
** @param[in] bAllowMsgPostToSelf Ϊ TRUE ʱ������ϢͶ�͵������߽�������
** @return ���� TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
** @remark �ú������ں�̨ö�����ж��㴰���Բ�����Ҫ������ϢͶ�͵Ĵ��ھ������ˣ��޷��ڵ����ڼ�ȷ������
**         �Ƿ�ɹ��������̲߳���ȫ����Ҫ�ڶ��̻߳�����ͬʱ���øú���
**         ���ڶ�ʵ�������������п��ܻ�����ö�ٵ������߽��̣���ʱ���ݲ��� bAllowMsgPostToSelf �������Ƿ�
**         ����ϢͶ�͵������߽��̣�������ܷǳ����ã���������߽���Ͷ�͵���һ��������̹رյ���Ϣ
**         ���Ҳ��� bAllowMsgPostToSelf Ϊ TRUE��������߽����п��ܻ����ϢͶ�͸��Լ��Ĵ��ڣ�����
**         �����߽�������ر�������������£������� bAllowMsgPostToSelf ��Ϊ FALSE������Ϣ���ǻ�
**         Ͷ�͵������߽���֮��Ľ���
*/
extern bool PostProcessWndMsgW(
	const wchar_t * szProcessName,
	const wchar_t * szWndClassName,
	const wchar_t * szWndTitle,
	const unsigned int uWndMsg,
	const WPARAM wParam,
	const LPARAM lParam,
	const bool bAllowMsgPostToSelf = false);

extern bool PostProcessWndMsgA(
	const char * szProcessName,
	const char * szWndClassName,
	const char * szWndTitle,
	const unsigned int uWndMsg,
	const WPARAM wParam,
	const LPARAM lParam,
	const bool bAllowMsgPostToSelf = false);

/**
** @brief ��ӵ��ָ��������ָ�����ڱ���Ĵ���Ͷ��ָ����Ϣ
** @param[in] szWndClassName ��������
** @param[in] szWndTitle ���ڱ���
** @param[in] uWndMsg��wParam��lParam ҪͶ�͵���Ϣ���Լ���Ϣ�ĸ�������
** @return ���� TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
*/
extern bool PostMsgWithWndClassTitleA(
	const char * szWndClassName,
	const char * szWndTitle,
	const unsigned int uWndMsg,
	const WPARAM wParam,
	const LPARAM lParam);

extern bool PostMsgWithWndClassTitleW(
	const wchar_t * szWndClassName,
	const wchar_t * szWndTitle,
	const unsigned int uWndMsg,
	const WPARAM wParam,
	const LPARAM lParam);
