
#pragma once

#include "WFLibConfig.h"

/**
** @brief 注册指定窗口到系统任务栏消息通知列表中
** @param[in] hWnd 通知窗口
** @param[in] uMsg 通知消息
** @return TRUE 表示成功，其余值表示失败
**/
extern bool RegistgerAppBarMessage(const HWND hWnd, const unsigned int uMsg);
