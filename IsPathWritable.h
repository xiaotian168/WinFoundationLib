
#pragma once

#if defined UNICODE || defined _UNICODE
#	define IsPathWriable IsPathWriableW
#else
#	define IsPathWriable IsPathWriableA
#endif

//-----------------------------------------------------------------------------------------------
// @brief 判断指定路径是否可写
// @param[in] szPath 路径
// @return TRUE 表示可写，其余值表示不可写
// @remark 该函数的实现思路为，创建 szPath 目录链，并在最后一级目录中创建一个文件名唯一的空白文件
//         如果文件创建成功，则认为该路径可写，否则，认为该路径不可写
//-----------------------------------------------------------------------------------------------
extern bool IsPathWriableA(const char * szPath);
extern bool IsPathWriableW(const wchar_t * szPath);
