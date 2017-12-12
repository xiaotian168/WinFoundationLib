
#pragma once

#if defined UNICODE || defined _UNICODE
#	define FormatDriveFreeSpaceString FormatDriveFreeSpaceStringW
#else
#	define FormatDriveFreeSpaceString FormatDriveFreeSpaceStringA
#endif

//---------------------------------------------------------------------------------------------
// @brief ��ʽ��ָ����������ʣ��ռ�Ϊ�ַ�������
// @param[in] �����������̷����ַ���
// @param[out] szSpaceString �����ʽ�����
// @param[in] uSize szSpaceString ��������������λ���ַ���
// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
//---------------------------------------------------------------------------------------------
extern bool FormatDriveFreeSpaceStringA(const char * szDrive, char * szSpaceString, const unsigned int uSize);
extern bool FormatDriveFreeSpaceStringW(const wchar_t * szDrive, wchar_t * szSpaceString, const unsigned int uSize);
