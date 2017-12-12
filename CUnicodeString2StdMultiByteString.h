
#pragma once

#include "WFLibConfig.h"

/**
** @brief 将标准 C Unicode 字符串转换为 std::string
** @param pszUnicodeString 标准 C Unicode 字符串
** @param strMultiByteString 保存转换好的多字节字符串
** @param uCodePage
** @return true 表示成功，false 表示失败
**/
extern bool CUnicodeString2StdMultiByteString(const wchar_t * pszUnicodeString, std::string & strMultiByteString, const unsigned int uCodePage = CP_ACP);

/**
** @brief 将标准 C 多字节字符串转换为 std::wstring
** @param pszMultiByteString 标准 C 多字节字符串
** @param strUnicodeString 保存转换好的 Unicode 字符串
** @param uCodePage
** @return true 表示成功，false 表示失败
**/
extern bool CMultiByteString2StdUnicodeString(const char * pszMultiByteString, std::wstring & strUnicodeString, const unsigned int uCodePage = CP_ACP);

/**
** @brief 将 Win32 SDK TCHAR 字符串转换为 std::string
** @param pszTString Win32 SDK TCHAR 字符串
** @param strMultiByteString 保存转换好的多字节字符串
** @param uCodePage
** @return true 表示成功，false 表示失败
*/
extern bool CTString2StdMultiByteString(const TCHAR * pszTString, std::string & strMultiByteString, const unsigned int uCodePage = CP_ACP);

/**
** @brief 将 Win32 SDK TCHAR 字符串转换为 std::wstring
** @param pszTString Win32 SDK TCHAR 字符串
** @param strUnicodeString 保存转换好的 Unicode 字符串
** @param uCodePage
** @return true 表示成功，false 表示失败
*/
extern bool CTString2StdUnicodeString(const TCHAR * pszTString, std::wstring & strUnicodeString, const unsigned int uCodePage = CP_ACP);
