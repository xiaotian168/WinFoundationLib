
#include "SockConnectWithTimeOut.h"

bool SockConnectWithTimeOut(
	const SOCKET Sock,
	const struct sockaddr * pSockAddr,
	const int nNameLen,
	const unsigned int uTimeOut)
{
	bool bRet = false;
	int nRet = 0;
	u_long uSockMode = 1; // 阻塞模式
	struct fd_set fdSetWrite = { 0 };
	struct timeval TimeOut = { 0 };

	if (0 != Sock && 0 != pSockAddr && 0 != nNameLen)
	{
		// 设置 Sock 为非阻塞模式

		if (SOCKET_ERROR != ioctlsocket(Sock, FIONBIO, &uSockMode))
		{
			// 尝试进行连接操作

			nRet = connect(Sock, pSockAddr, nNameLen);

			if(SOCKET_ERROR == nRet && WSAEWOULDBLOCK == WSAGetLastError())
			{
				// 进行超时检测 

				TimeOut.tv_sec = uTimeOut;
				FD_ZERO(&fdSetWrite);
				FD_SET(Sock, &fdSetWrite);

				nRet = select(0, 0, &fdSetWrite, 0, &TimeOut);

				if (nRet > 0)
				{
					if (0 != FD_ISSET(Sock, &fdSetWrite))
					{
						// 在指定时间段内连接成功

						bRet = true;
					}
				}
			}
			else if(0 == nRet)
			{
				// 连接成功
				
				bRet = true;
			}

			// 恢复 Sock 为阻塞模式

			uSockMode = 0;
			ioctlsocket(Sock, FIONBIO, &uSockMode);
		}
	}

	return bRet;
}
