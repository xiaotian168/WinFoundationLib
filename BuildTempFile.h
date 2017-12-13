
#pragma once

#if defined UNICODE || defined _UNICODE
#	define BuildTempFilePath BuildTempFilePathW
#else
#	define BuildTempFilePath BuildTempFilePathA
#endif

//-------------------------------------------------------------------------------------------------
// @brief ��ϵͳ��ʱĿ¼������һ������ļ����������ļ�·��
// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
// @remark
//
// �ú�����ʹ��ϵͳ��ʱĿ¼·���� GetTickCount() ����������������ʱ�ļ�·�������ļ��� .dat Ϊ��׺��
// �ú������������κ��ļ���ֻ������һ��·���ַ���
//-------------------------------------------------------------------------------------------------

extern bool BuildTempFilePathA(char * pszPath, const unsigned int uSize);
extern bool BuildTempFilePathW(wchar_t * pszPath, const unsigned int uSize);
