
#include "SockConnectWithTimeOut.h"

bool SockConnectWithTimeOut(
	const SOCKET Sock,
	const struct sockaddr * pSockAddr,
	const int nNameLen,
	const unsigned int uTimeOut)
{
	bool bRet = false;
	int nRet = 0;
	u_long uSockMode = 1; // ����ģʽ
	struct fd_set fdSetWrite = { 0 };
	struct timeval TimeOut = { 0 };

	if (0 != Sock && 0 != pSockAddr && 0 != nNameLen)
	{
		// ���� Sock Ϊ������ģʽ

		if (SOCKET_ERROR != ioctlsocket(Sock, FIONBIO, &uSockMode))
		{
			// ���Խ������Ӳ���

			nRet = connect(Sock, pSockAddr, nNameLen);

			if(SOCKET_ERROR == nRet && WSAEWOULDBLOCK == WSAGetLastError())
			{
				// ���г�ʱ��� 

				TimeOut.tv_sec = uTimeOut;
				FD_ZERO(&fdSetWrite);
				FD_SET(Sock, &fdSetWrite);

				nRet = select(0, 0, &fdSetWrite, 0, &TimeOut);

				if (nRet > 0)
				{
					if (0 != FD_ISSET(Sock, &fdSetWrite))
					{
						// ��ָ��ʱ��������ӳɹ�

						bRet = true;
					}
				}
			}
			else if(0 == nRet)
			{
				// ���ӳɹ�
				
				bRet = true;
			}

			// �ָ� Sock Ϊ����ģʽ

			uSockMode = 0;
			ioctlsocket(Sock, FIONBIO, &uSockMode);
		}
	}

	return bRet;
}
