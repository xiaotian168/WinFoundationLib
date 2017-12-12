
#pragma once

#if defined UNICODE || defined _UNICODE
#	define IsURLCharSpecialChar IsURLCharSpecialCharW
#	define ConvertURLSpecialChar ConvertURLSpecialCharW
#	define CalcURLStringSizeAfterConvert CalcURLStringSizeAfterConvertW
#	define ConvertURL ConvertURLW
#else
#	define IsURLCharSpecialChar IsURLCharSpecialCharA
#	define ConvertURLSpecialChar ConvertURLSpecialCharA
#	define CalcURLStringSizeAfterConvert CalcURLStringSizeAfterConvertA
#	define ConvertURL ConvertURLA
#endif

/**
** @brief �ж�ָ���ַ��Ƿ�ת���ַ�
** @param[in] c
** @return true ��ʾ�ɹ���false ��ʾʧ��
**/
extern bool IsURLCharSpecialCharA(const char c);
extern bool IsURLCharSpecialCharW(const wchar_t c);

/**
** @brief �������ַ���ʽ��Ϊ 16 �����ַ���
** @param[in] c
** @param[out] szC
** @param[in] dwSize
** @return true ��ʾ�ɹ���false ��ʾʧ��
**/
extern bool ConvertURLSpecialCharA(const char c, char * szC, const unsigned int uSize);
extern bool ConvertURLSpecialCharW(const wchar_t c, wchar_t * szC, const unsigned int uSize);

/**
** @brief ����ָ���ַ�������ת�����Ҫ��󻺳���
** @param[in] pszURL Ҫ���д�����ַ���
** @return �ַ�������ת���Ļ�������С
**/
extern unsigned int CalcURLStringSizeAfterConvertA(const char * pszURL);
extern unsigned int CalcURLStringSizeAfterConvertW(const wchar_t * pszURL);

/**
** @brief ��ָ�� URL �е�ת���ַ�����ת��
** @param[in] pszURL Ҫ����ת����ַ���
** @param[out] pszURLAfterConvert ����ת�����ַ���������
** @param[in] uSize pszURLAfterConvert ��������С����λ���ַ���
** @return true ��ʾ�ɹ���false ��ʾʧ��
**/
extern bool ConvertURLA(const char * pszURL, char * pszURLAfterConvert, const unsigned int uSize);
extern bool ConvertURLW(const wchar_t * pszURL, wchar_t * pszURLAfterConvert, const unsigned int uSize);
