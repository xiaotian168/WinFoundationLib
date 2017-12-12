
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
// @brief 创建快捷方式
// @param[in] szTargetPath 快捷方式所指向的目标文件路径
// @param[in] szIconPath 快捷方式显示的图标文件路径
// @param[in] nIconIndex 快捷方式显示的图标文件索引号
// @param[in] szShortcutPath 快捷方式文件路径
// @param[in] bRemember
// @return TRUE 表示成功，其余值表示失败
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
// @brief 读取指定快捷方式文件信息
// @param[in] szShortcutFile 快捷方式文件路径
// @param[out] szTargetPath 快捷方式所指向的目标路径
// @param[in] dwTargetPathSize szTargetPath 大小（单位：字符）
// @param[out] szArgument 快捷方式所指向的目标执行命令行参数
// @param[in] dwArgumentSize szArgument 大小（单位：字符）
// @param[out] szIconPath 快捷方式显示所指向的目标时使用的图标文件路径
// @param[in] dwIconPathSize szIconPath 大小（单位：字符）
// @return TRUE 表示成功，其余值表示失败
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
// @brief 判断指定快捷方式是否指向指定目标
// @param[in] szShortcutFile 快捷方式文件路径
// @param[in] szTarget 目标路径
// @return TRUE 表示是
//-----------------------------------------------------------------------------------------------------------------------------

extern bool IsShortcutTargetA(const char * szShortcutFile, const char * szTarget);
extern bool IsShortcutTargetW(const wchar_t * szShortcutFile, const wchar_t * szTarget);

//-----------------------------------------------------------------------------------------------------------------------------
// @brief 判断桌面目录下是否存在指定文件
// @param[in] szFileName 文件名称
// @param[in] bCurrentUser 为 TRUE 表示在当前用户桌面目录下判断，为 FALSE 表示在所有用户桌面目录下判断
// @return TRUE 表示存在，其余值表示不存在
//-----------------------------------------------------------------------------------------------------------------------------

extern bool IsDesktopExistFileA(const char * szFileName, const bool bCurrentUser);
extern bool IsDesktopExistFileW(const wchar_t * szFileName, const bool bCurrentUser);

//-----------------------------------------------------------------------------------------------------------------------------
// @brief 删除桌面目录下是否存在指定文件，如果文件存在的话
// @param[in] szFileName 文件名称
// @param[in] bCurrentUser 为 TRUE 表示在当前用户桌面目录下删除，为 FALSE 表示在所有用户桌面目录下删除
// @return TRUE 表示删除成功，其余值表示删除失败（或文件不存在）
//-----------------------------------------------------------------------------------------------------------------------------

extern bool DeleteDesktopFileA(const char * szFileName, const bool bCurrentUser);
extern bool DeleteDesktopFileW(const wchar_t * szFileName, const bool bCurrentUser);

//-----------------------------------------------------------------------------------------------------------------------------
// @brief 判断调用者模块是否存放在桌面上
// @param[in] bCurrentUser 为 TRUE 表示在当前用户桌面目录下判断，为 FALSE 表示在所有用户桌面目录下判断
// @return TRUE 表示存在，FALSE 表示不存在
//-----------------------------------------------------------------------------------------------------------------------------

extern bool IsModuleFileInDesktop(const bool bCurrentUser);
