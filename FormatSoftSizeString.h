
#pragma once

#if defined UNICODE || defined _UNICODE
#	define FormatSoftSizeString FormatSoftSizeStringW
#else
#	define FormatSoftSizeString FormatSoftSizeStringA
#endif

/**
** @brief ��ָ�������С����ʽ��Ϊ�ַ�������
** @param[in] uSoftSizeInBytes �����С����λ��Byte��
** @param[out] szString �����ʽ������ַ���
** @param[in] dwSize szString ��������������λ���ַ���
** @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
**/
extern bool FormatSoftSizeStringA(const unsigned long long uSoftSizeInByte, char * szString, const unsigned int uSize);
extern bool FormatSoftSizeStringW(const unsigned long long uSoftSizeInByte, wchar_t * szString, const unsigned int uSize);
