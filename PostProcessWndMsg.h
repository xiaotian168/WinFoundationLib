
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
** @brief 向指定进程的指定窗口投送指定消息
** @param[in] szProcessName 进程名
** @param[in] szWndClassName 窗口类名
** @param[in] szWndTitle 窗口标题
** @param[in] uWndMsg、wParam、lParam 要投送的消息，以及消息的附带参数
** @param[in] bAllowMsgPostToSelf 为 TRUE 时允许将消息投送到调用者进程自身
** @return 返回 TRUE 表示成功，其余值表示失败
** @remark 该函数会在后台枚举所有顶层窗口以查找需要进行消息投送的窗口句柄，因此，无法在调用期间确定操作
**         是否成功，并且线程不安全，不要在多线程环境下同时调用该函数
**         对于多实例进程来讲，有可能会首先枚举到调用者进程，此时根据参数 bAllowMsgPostToSelf 来决定是否
**         将消息投送到调用者进程，这个功能非常有用，如果调用者进程投送的是一个请求进程关闭的消息
**         并且参数 bAllowMsgPostToSelf 为 TRUE，则调用者进程有可能会把消息投送给自己的窗口，导致
**         调用者进程自身关闭自身，这种情况下，将参数 bAllowMsgPostToSelf 设为 FALSE，则消息总是会
**         投送到调用者进程之外的进程
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
** @brief 向拥有指定类名和指定窗口标题的窗口投送指定消息
** @param[in] szWndClassName 窗口类名
** @param[in] szWndTitle 窗口标题
** @param[in] uWndMsg、wParam、lParam 要投送的消息，以及消息的附带参数
** @return 返回 TRUE 表示成功，其余值表示失败
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
