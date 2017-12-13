
#pragma once

#if defined UNICODE || defined _UNICODE
#	define WaitFileNotExist WaitFileNotExistW
#	define DeleteFileAndWait DeleteFileAndWaitW
#	define RemoveFileReadOnlyAttrubite RemoveFileReadOnlyAttrubiteW
#else
#	define WaitFileNotExist WaitFileNotExistA
#	define DeleteFileAndWait DeleteFileAndWaitA
#	define RemoveFileReadOnlyAttrubite RemoveFileReadOnlyAttrubiteA
#endif

/**
** @brief �ȴ�ָ���ļ������ں󷵻�
** @param[in] pszFile �ļ�·��
** @param[in] uTryCount ���Դ��ļ����ٴ�
** @param[in] uTryElapse ÿ�δ��ļ�֮��ȴ����ٺ���
** @return true ��ʾ�ɹ���false ��ʾʧ��
** @remark
**
** �ú���ʹ��һ��ѭ�������Դ�ָ���ļ����û�ָ��һ��ѭ���������Լ�ÿ�δ��ļ��󣬵ȴ����ٺ�����ٽ�����һ�δ򿪲���
*/
extern bool WaitFileNotExistA(const char * pszFile, const unsigned int uTryCount = 0xFFFFFFFF, const unsigned int uTryElapse = 500);
extern bool WaitFileNotExistW(const wchar_t * pszFile, const unsigned int uTryCount = 0xFFFFFFFF, const unsigned int uTryElapse = 500);

/**
** @brief
** @param[in] pszFile �ļ�·��
** @param[in] uTryCount ���Դ��ļ����ٴ�
** @param[in] uTryElapse ÿ�δ��ļ�֮��ȴ����ٺ���
** @return true ��ʾ�ɹ���false ��ʾʧ��
** @remark
**
** �ú���ʹ��һ��ѭ�������Դ�ָ���ļ����û�ָ��һ��ѭ���������Լ�ÿ�δ��ļ��󣬵ȴ����ٺ�����ٽ�����һ�δ򿪲���
*/
extern bool DeleteFileAndWaitA(const char * pszFile, const unsigned int uTryCount = 0xFFFFFFFF, const unsigned int uTryElapse = 500);
extern bool DeleteFileAndWaitW(const wchar_t * pszFile, const unsigned int uTryCount = 0xFFFFFFFF, const unsigned int uTryElapse = 500);

/**
���� @brief �Ƴ�ָ���ļ���ֻ������
���� @param[in] pszFile �ļ�·��
���� @return true ��ʾ�ɹ���false ��ʾʧ��
*/
extern bool RemoveFileReadOnlyAttrubiteA(const char * pszFile);
extern bool RemoveFileReadOnlyAttrubiteW(const wchar_t * pszFile);
