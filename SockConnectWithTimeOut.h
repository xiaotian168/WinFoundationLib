
#pragma once

#include "WFLibConfig.h"

//-------------------------------------------------------------------------------------------
// @brief 为指定 socket 对象在指定超时内进行连接操作
// @param[in] Sock 需要进行连接操作的 SOCKET 对象
// @param[in] pSockAddr 连接参数
// @param[in] nNameLen 连接参数
// @param[in] uTimeOut 连接超时（单位：秒）
// @return TRUE 表示连接成功，其余值表示连接失败
// @remark 该函数会将指定的 SOCKET 对象设置为非阻塞模式，并且在完成操作后恢复为阻塞模式
//-------------------------------------------------------------------------------------------
extern bool SockConnectWithTimeOut(
	const SOCKET Sock,
	const struct sockaddr * pSockAddr,
	const int nNameLen,
	const unsigned int uTimeOut);
