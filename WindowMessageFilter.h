
#pragma once

#include "WFLibConfig.h"

/**
** @brief 为指定窗口移除对指定消息的过滤
** @param hWnd 窗口句柄
** @param uMsg 移除过滤的消息
** @return true 表示成功，false 表示失败
** @remark
**
** 如果该函数成功，hWnd 将可以接收到 uMsg 消息
**/
extern bool AddWindowMessageFilter(const HWND hWnd, const unsigned int uMsg);

/**
** @brief 为指定窗口添加对指定消息的过滤
** @param hWnd 窗口句柄
** @param uMsg
** @return true 表示成功，false 表示失败
** @remark
**
** 如果该函数成功，hWnd 将不再可以接收到 uMsg 消息
**/
extern bool RemoveWindowMessageFilter(const HWND hWnd, const unsigned int uMsg);
