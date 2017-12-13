
#pragma once

#include "WFLibConfig.h"

#if defined UNICODE || defined _UNICODE
#	define GetAllUserProgramGroupDirectory GetAllUserProgramGroupDirectoryW
#	define CreateAllUserProgramGroupDirectory CreateAllUserProgramGroupDirectoryW
#	define DeleteAllUserProgramGroupDirectoryFile DeleteAllUserProgramGroupDirectoryFileW
#	define DeleteAllUserProgramGroupDirectory DeleteAllUserProgramGroupDirectoryW
#else
#	define GetAllUserProgramGroupDirectory GetAllUserProgramGroupDirectoryA
#	define CreateAllUserProgramGroupDirectory CreateAllUserProgramGroupDirectoryA
#	define DeleteAllUserProgramGroupDirectoryFile DeleteAllUserProgramGroupDirectoryFileA
#	define DeleteAllUserProgramGroupDirectory DeleteAllUserProgramGroupDirectoryA
#endif

class CStartMenuProgramGroup
{
public:

	CStartMenuProgramGroup();
	virtual ~CStartMenuProgramGroup();

public:

	//-------------------------------------------------------------------------------------------------
	// @brief ��ȡ�����û���ʼ�˵��µĳ�����Ŀ¼·��
	//-------------------------------------------------------------------------------------------------
	static bool GetAllUserProgramGroupDirectoryW(wchar_t * szDirectory, const unsigned int uSize, const bool bCreate = false);
	static bool GetAllUserProgramGroupDirectoryA(char * szDirectory, const unsigned int uSize, const bool bCreate = false);

	//-------------------------------------------------------------------------------------------------
	// @brief �������û���ʼ�˵��´���ָ�����Ƶĳ�����Ŀ¼
	//-------------------------------------------------------------------------------------------------
	static bool CreateAllUserProgramGroupDirectoryW(const wchar_t * szGroupName);
	static bool CreateAllUserProgramGroupDirectoryA(const char * szGroupName);

	//-------------------------------------------------------------------------------------------------
	// @brief ɾ�������û���ʼ�˵��µ�ָ���������ļ�
	//-------------------------------------------------------------------------------------------------
	static bool DeleteAllUserProgramGroupDirectoryFileW(const wchar_t * szGroupName, const wchar_t * szFileName);
	static bool DeleteAllUserProgramGroupDirectoryFileA(const char * szGroupName, const char * szFileName);

	//-------------------------------------------------------------------------------------------------
	// @brief ɾ�������û���ʼ�˵��µ�ָ��������Ŀ¼
	//-------------------------------------------------------------------------------------------------
	static bool DeleteAllUserProgramGroupDirectoryW(const wchar_t * szGroupName);
	static bool DeleteAllUserProgramGroupDirectoryA(const char * szGroupName);

	//-------------------------------------------------------------------------------------------------
	// @brief �ڿ�ʼ�˵����������û�������
	// @param[in] szGroupName ����������
	// @param[in] szProgramPath ��������·��
	// @param[in] szLinkIconPath ��ݷ�ʽͼ���ļ�����·��
	// @param[in] szProgramLinkFileName ��ݷ�ʽ�ļ�����
	// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
	//-------------------------------------------------------------------------------------------------
	static bool CreateStartMenuAllUserProgramGroup(
		const TCHAR * szGroupName,
		const TCHAR * szProgramPath,
		const TCHAR * szLinkIconPath,
		const TCHAR * szProgramLinkFileName);

	//-------------------------------------------------------------------------------------------------
	// @brief ������ݷ�ʽ
	// @param[in] szLinkPath ��ݷ�ʽ����·��
	// @param[in] szExePath ��ݷ�ʽĿ���������·��
	// @param[in] szIconPath ��ݷ�ʽͼ���ļ�����·��
	// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
	//-------------------------------------------------------------------------------------------------
	static bool CreateShortCut(
		const TCHAR * szLinkPath,
		const TCHAR * szExePath,
		const TCHAR * szIconPath);
};
