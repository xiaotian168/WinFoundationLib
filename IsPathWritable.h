
#pragma once

#if defined UNICODE || defined _UNICODE
#	define IsPathWriable IsPathWriableW
#else
#	define IsPathWriable IsPathWriableA
#endif

//-----------------------------------------------------------------------------------------------
// @brief �ж�ָ��·���Ƿ��д
// @param[in] szPath ·��
// @return TRUE ��ʾ��д������ֵ��ʾ����д
// @remark �ú�����ʵ��˼·Ϊ������ szPath Ŀ¼�����������һ��Ŀ¼�д���һ���ļ���Ψһ�Ŀհ��ļ�
//         ����ļ������ɹ�������Ϊ��·����д��������Ϊ��·������д
//-----------------------------------------------------------------------------------------------
extern bool IsPathWriableA(const char * szPath);
extern bool IsPathWriableW(const wchar_t * szPath);
