
#pragma once

#if defined UNICODE || defined _UNICODE
#	define CreateShortcut CreateShortcutW
#	define ReadShortcutInfo ReadShortcutInfoW
#	define IsShortcutTarget IsShortcutTargetW
#	define IsDesktopExistFile IsDesktopExistFileW
#	define DeleteDesktopFile DeleteDesktopFileW
#else
#	define CreateShortcut CreateShortcutA
#	define ReadShortcutInfo ReadShortcutInfoA
#	define IsShortcutTarget IsShortcutTargetA
#	define IsDesktopExistFile IsDesktopExistFileA
#	define DeleteDesktopFile DeleteDesktopFileA
#endif

//-----------------------------------------------------------------------------------------------------------------------------
// @brief ������ݷ�ʽ
// @param[in] szTargetPath ��ݷ�ʽ��ָ���Ŀ���ļ�·��
// @param[in] szIconPath ��ݷ�ʽ��ʾ��ͼ���ļ�·��
// @param[in] nIconIndex ��ݷ�ʽ��ʾ��ͼ���ļ�������
// @param[in] szShortcutPath ��ݷ�ʽ�ļ�·��
// @param[in] bRemember
// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
//-----------------------------------------------------------------------------------------------------------------------------

extern bool CreateShortcutA(
	const char * szTargetPath,
	const char * szIconPath,
	const int nIconIndex,
	const char * szShortcutPath,
	const bool bRemember = false);

extern bool CreateShortcutW(
	const wchar_t * szTargetPath,
	const wchar_t * szIconPath,
	const int nIconIndex,
	const wchar_t * szShortcutPath,
	const bool bRemember = false);

//-----------------------------------------------------------------------------------------------------------------------------
// @brief ��ȡָ����ݷ�ʽ�ļ���Ϣ
// @param[in] szShortcutFile ��ݷ�ʽ�ļ�·��
// @param[out] szTargetPath ��ݷ�ʽ��ָ���Ŀ��·��
// @param[in] dwTargetPathSize szTargetPath ��С����λ���ַ���
// @param[out] szArgument ��ݷ�ʽ��ָ���Ŀ��ִ�������в���
// @param[in] dwArgumentSize szArgument ��С����λ���ַ���
// @param[out] szIconPath ��ݷ�ʽ��ʾ��ָ���Ŀ��ʱʹ�õ�ͼ���ļ�·��
// @param[in] dwIconPathSize szIconPath ��С����λ���ַ���
// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ��
//-----------------------------------------------------------------------------------------------------------------------------

extern bool ReadShortcutInfoA(
	const char * szShortcutFile,
	char * szTargetPath,
	const unsigned int dwTargetPathSize,
	char * szArgument,
	const unsigned int dwArgumentSize,
	char * szIconPath,
	const unsigned int dwIconPathSize);

extern bool ReadShortcutInfoW(
	const wchar_t * szShortcutFile,
	wchar_t * szTargetPath,
	const unsigned int dwTargetPathSize,
	wchar_t * szArgument,
	const unsigned int dwArgumentSize,
	wchar_t * szIconPath,
	const unsigned int dwIconPathSize);

//-----------------------------------------------------------------------------------------------------------------------------
// @brief �ж�ָ����ݷ�ʽ�Ƿ�ָ��ָ��Ŀ��
// @param[in] szShortcutFile ��ݷ�ʽ�ļ�·��
// @param[in] szTarget Ŀ��·��
// @return TRUE ��ʾ��
//-----------------------------------------------------------------------------------------------------------------------------

extern bool IsShortcutTargetA(const char * szShortcutFile, const char * szTarget);
extern bool IsShortcutTargetW(const wchar_t * szShortcutFile, const wchar_t * szTarget);

//-----------------------------------------------------------------------------------------------------------------------------
// @brief �ж�����Ŀ¼���Ƿ����ָ���ļ�
// @param[in] szFileName �ļ�����
// @param[in] bCurrentUser Ϊ TRUE ��ʾ�ڵ�ǰ�û�����Ŀ¼���жϣ�Ϊ FALSE ��ʾ�������û�����Ŀ¼���ж�
// @return TRUE ��ʾ���ڣ�����ֵ��ʾ������
//-----------------------------------------------------------------------------------------------------------------------------

extern bool IsDesktopExistFileA(const char * szFileName, const bool bCurrentUser);
extern bool IsDesktopExistFileW(const wchar_t * szFileName, const bool bCurrentUser);

//-----------------------------------------------------------------------------------------------------------------------------
// @brief ɾ������Ŀ¼���Ƿ����ָ���ļ�������ļ����ڵĻ�
// @param[in] szFileName �ļ�����
// @param[in] bCurrentUser Ϊ TRUE ��ʾ�ڵ�ǰ�û�����Ŀ¼��ɾ����Ϊ FALSE ��ʾ�������û�����Ŀ¼��ɾ��
// @return TRUE ��ʾɾ���ɹ�������ֵ��ʾɾ��ʧ�ܣ����ļ������ڣ�
//-----------------------------------------------------------------------------------------------------------------------------

extern bool DeleteDesktopFileA(const char * szFileName, const bool bCurrentUser);
extern bool DeleteDesktopFileW(const wchar_t * szFileName, const bool bCurrentUser);

//-----------------------------------------------------------------------------------------------------------------------------
// @brief �жϵ�����ģ���Ƿ�����������
// @param[in] bCurrentUser Ϊ TRUE ��ʾ�ڵ�ǰ�û�����Ŀ¼���жϣ�Ϊ FALSE ��ʾ�������û�����Ŀ¼���ж�
// @return TRUE ��ʾ���ڣ�FALSE ��ʾ������
//-----------------------------------------------------------------------------------------------------------------------------

extern bool IsModuleFileInDesktop(const bool bCurrentUser);
