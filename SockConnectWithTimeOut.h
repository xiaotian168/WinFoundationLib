
#pragma once

#include "WFLibConfig.h"

//-------------------------------------------------------------------------------------------
// @brief Ϊָ�� socket ������ָ����ʱ�ڽ������Ӳ���
// @param[in] Sock ��Ҫ�������Ӳ����� SOCKET ����
// @param[in] pSockAddr ���Ӳ���
// @param[in] nNameLen ���Ӳ���
// @param[in] uTimeOut ���ӳ�ʱ����λ���룩
// @return TRUE ��ʾ���ӳɹ�������ֵ��ʾ����ʧ��
// @remark �ú����Ὣָ���� SOCKET ��������Ϊ������ģʽ����������ɲ�����ָ�Ϊ����ģʽ
//-------------------------------------------------------------------------------------------
extern bool SockConnectWithTimeOut(
	const SOCKET Sock,
	const struct sockaddr * pSockAddr,
	const int nNameLen,
	const unsigned int uTimeOut);
