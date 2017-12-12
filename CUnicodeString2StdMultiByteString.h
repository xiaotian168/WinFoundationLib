
#pragma once

#include "WFLibConfig.h"

/**
** @brief ����׼ C Unicode �ַ���ת��Ϊ std::string
** @param pszUnicodeString ��׼ C Unicode �ַ���
** @param strMultiByteString ����ת���õĶ��ֽ��ַ���
** @param uCodePage
** @return true ��ʾ�ɹ���false ��ʾʧ��
**/
extern bool CUnicodeString2StdMultiByteString(const wchar_t * pszUnicodeString, std::string & strMultiByteString, const unsigned int uCodePage = CP_ACP);

/**
** @brief ����׼ C ���ֽ��ַ���ת��Ϊ std::wstring
** @param pszMultiByteString ��׼ C ���ֽ��ַ���
** @param strUnicodeString ����ת���õ� Unicode �ַ���
** @param uCodePage
** @return true ��ʾ�ɹ���false ��ʾʧ��
**/
extern bool CMultiByteString2StdUnicodeString(const char * pszMultiByteString, std::wstring & strUnicodeString, const unsigned int uCodePage = CP_ACP);

/**
** @brief �� Win32 SDK TCHAR �ַ���ת��Ϊ std::string
** @param pszTString Win32 SDK TCHAR �ַ���
** @param strMultiByteString ����ת���õĶ��ֽ��ַ���
** @param uCodePage
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
extern bool CTString2StdMultiByteString(const TCHAR * pszTString, std::string & strMultiByteString, const unsigned int uCodePage = CP_ACP);

/**
** @brief �� Win32 SDK TCHAR �ַ���ת��Ϊ std::wstring
** @param pszTString Win32 SDK TCHAR �ַ���
** @param strUnicodeString ����ת���õ� Unicode �ַ���
** @param uCodePage
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
extern bool CTString2StdUnicodeString(const TCHAR * pszTString, std::wstring & strUnicodeString, const unsigned int uCodePage = CP_ACP);
