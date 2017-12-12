
#pragma once

#include "WFLibConfig.h"

/**
** @brief Ϊָ�������Ƴ���ָ����Ϣ�Ĺ���
** @param hWnd ���ھ��
** @param uMsg �Ƴ����˵���Ϣ
** @return true ��ʾ�ɹ���false ��ʾʧ��
** @remark
**
** ����ú����ɹ���hWnd �����Խ��յ� uMsg ��Ϣ
**/
extern bool AddWindowMessageFilter(const HWND hWnd, const unsigned int uMsg);

/**
** @brief Ϊָ��������Ӷ�ָ����Ϣ�Ĺ���
** @param hWnd ���ھ��
** @param uMsg
** @return true ��ʾ�ɹ���false ��ʾʧ��
** @remark
**
** ����ú����ɹ���hWnd �����ٿ��Խ��յ� uMsg ��Ϣ
**/
extern bool RemoveWindowMessageFilter(const HWND hWnd, const unsigned int uMsg);
