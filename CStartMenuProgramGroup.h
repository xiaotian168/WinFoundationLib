
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
	// @brief 获取所有用户开始菜单下的程序组目录路径
	//-------------------------------------------------------------------------------------------------
	static bool GetAllUserProgramGroupDirectoryW(wchar_t * szDirectory, const unsigned int uSize, const bool bCreate = false);
	static bool GetAllUserProgramGroupDirectoryA(char * szDirectory, const unsigned int uSize, const bool bCreate = false);

	//-------------------------------------------------------------------------------------------------
	// @brief 在所有用户开始菜单下创建指定名称的程序组目录
	//-------------------------------------------------------------------------------------------------
	static bool CreateAllUserProgramGroupDirectoryW(const wchar_t * szGroupName);
	static bool CreateAllUserProgramGroupDirectoryA(const char * szGroupName);

	//-------------------------------------------------------------------------------------------------
	// @brief 删除所有用户开始菜单下的指定程序组文件
	//-------------------------------------------------------------------------------------------------
	static bool DeleteAllUserProgramGroupDirectoryFileW(const wchar_t * szGroupName, const wchar_t * szFileName);
	static bool DeleteAllUserProgramGroupDirectoryFileA(const char * szGroupName, const char * szFileName);

	//-------------------------------------------------------------------------------------------------
	// @brief 删除所有用户开始菜单下的指定程序组目录
	//-------------------------------------------------------------------------------------------------
	static bool DeleteAllUserProgramGroupDirectoryW(const wchar_t * szGroupName);
	static bool DeleteAllUserProgramGroupDirectoryA(const char * szGroupName);

	//-------------------------------------------------------------------------------------------------
	// @brief 在开始菜单创建所有用户程序组
	// @param[in] szGroupName 程序组名称
	// @param[in] szProgramPath 程序完整路径
	// @param[in] szLinkIconPath 快捷方式图标文件完整路径
	// @param[in] szProgramLinkFileName 快捷方式文件名称
	// @return TRUE 表示成功，其余值表示失败
	//-------------------------------------------------------------------------------------------------
	static bool CreateStartMenuAllUserProgramGroup(
		const TCHAR * szGroupName,
		const TCHAR * szProgramPath,
		const TCHAR * szLinkIconPath,
		const TCHAR * szProgramLinkFileName);

	//-------------------------------------------------------------------------------------------------
	// @brief 创建快捷方式
	// @param[in] szLinkPath 快捷方式完整路径
	// @param[in] szExePath 快捷方式目标程序完整路径
	// @param[in] szIconPath 快捷方式图标文件完整路径
	// @return TRUE 表示成功，其余值表示失败
	//-------------------------------------------------------------------------------------------------
	static bool CreateShortCut(
		const TCHAR * szLinkPath,
		const TCHAR * szExePath,
		const TCHAR * szIconPath);
};
