
#pragma once

#if defined UNICODE || defined _UNICODE
#	define BuildRandomString BuildRandomStringW
#else
#	define BuildRandomString BuildRandomStringA
#endif

/**
** @brief ������������ַ����ַ���
** @param pszRandomString ��������ַ����ַ���������
** @param uBufferSize ��������ַ����ַ�����������С����λ���ַ���
** @param uRandomStringLength �������ٸ�����ַ�
** @return �� 0 ��ʾ�ɹ���0 ��ʾʧ��
** @note
**
** ���������ɵ�����ַ���ȫ�����ǿɴ�ӡ�ַ�
**/
extern int BuildRandomStringA(char * pszRandomString, const unsigned int uBufferSize, const unsigned int uRandomStringLength);
extern int BuildRandomStringW(wchar_t * pszRandomString, const unsigned int uBufferSize, const unsigned int uRandomStringLength);
