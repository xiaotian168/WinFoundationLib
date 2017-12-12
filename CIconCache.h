
#pragma once

#include "WFLibConfig.h"

/**
** @brief 图标缓存类
** @note
**
** 该类根据文件文件扩展名、图标 ID 与文件图标的对应关系，保存不同文件扩展性的图标资源
** 用户通过文件扩展名或图标 ID 从缓存类中获取图标资源，用户通过下述方式添加图标资源到缓冲类中：
**
** 1. 给定一个完整的文件路径，由图标缓存类从中提取图标，并记录文件扩展名，这些图标会由图标缓存类销毁
** 2. 给定一个图标资源以及对应的文件扩展名，由图标缓存保存，图标缓存类不会销毁这些图标
** 3. 给定一个图标资源以及对应的图标 ID，由图标缓存保存，图标缓存类不会销毁这些图标
**
** 图标缓存类只会独立维护【文件扩展名 - 图标】以及【图标 ID - 图标】两个关系，不会交互维护两者之间的关系
** 图标缓存可以保证同一个文件扩展名只有一个图标资源，以及同一个 ID 只有一个图标资源
** 但是图标缓存不会保证文件扩展名与图标 ID 之间不会存在重复图标资源
** 比如用户将文件 C:\MyProgram.exe 的图标缓存起来，随后自行提取 C:\MyProgram.exe 的图标，再通过
** 某个 ID 将图标添加到图标缓存，图标缓存没有能力判断两次添加的图标是同一个图标资源
**/
class CIconCache
{
public:

	/* 最大文件扩展名长度（单位：字符） */
	static const unsigned int MAX_FILE_EXT_SIZE = 64;

private:

	/**
	** @brief 图标来源
	**/
	enum emIconSource
	{
		/* 未知来源，该类型的图标，缓存类不会做任何销毁操作 */
		eIconSource_Unknown,

		/* 图标由缓存类从文件提取，该类型的图标，由缓存类使用 DestroyIcon 进行销毁 */
		eIconSource_ExtractFromFile,

		/* 引用用户设置的图标，该类型的图标，缓存类不会做任何销毁操作 */
		eIconSource_UserRef,
	};

	struct CCacheIcon
	{
	public:

		CCacheIcon();

	public:

		HICON m_hIcon;
		wchar_t m_szFileExt[MAX_FILE_EXT_SIZE];
		emIconSource m_IconSource;
		unsigned int m_uIconID;
	};

public:

	static CIconCache * GetInstance(void);

protected:

	CIconCache();

public:

	~CIconCache();

public:

	/**
	** @brief 从指定文件中提取图标资源，并将图标资源添加到缓存中
	** @param pszFullFilePath
	** @return 成功返回非 0 图标资源，失败返回 0
	** @note
	**
	** 缓存类会自动判断指定的文件扩展名是否已经添加过，如果没有添加过，再进行添加操作
	** 文件扩展名的长度不能超过常量 MAX_FILE_EXT_SIZE 的值，否则图标缓存失败
	**
	** 对了，pszFullFilePath 参数必须是文件，对于目录图标，你们自己手动用 ID 来添加吧
	*/
	HICON AddIconByFullFilePathW(const wchar_t * pszFullFilePath);

	/**
	** @brief 将指定的文件扩展名的图标资源添加到缓存中
	** @param hIcon
	** @param pszFullFilePath
	** @return true 表示成功，false 表示失败
	** @note
	**
	** 缓存类会自动判断指定的文件扩展名是否已经添加过，如果没有添加过，再进行添加操作
	*/
	bool AddIconByFileExt(const HICON hIcon, const wchar_t * pszFileExt);

	/**
	** @brief 将指定的图标 ID 的图标资源添加到缓存中
	** @param hIcon
	** @param pszFullFilePath
	** @return true 表示成功，false 表示失败
	** @note
	**
	** 缓存类会自动判断指定的图标 ID 是否已经添加过，如果没有添加过，再进行添加操作
	*/
	bool AddIconByID(const HICON hIcon, const unsigned int uIconID);

	/**
	** @brief 移除指定文件扩展名对应的图标资源
	** @param pszFileExt 文件扩张名
	** @return true 表示成功，false 表示失败
 	*/
	bool RemoveIconByFileExtW(const wchar_t * pszFileExt);

	/**
	** @brief 移除指定 ID 对应的图标资源
	** @param uIconID 图标 ID
	** @return true 表示成功，false 表示失败
	*/
	bool RemoveIconByID(const unsigned int uIconID);

	/**
	** @brief 移除所有图标资源
	*/
	void RemoveAllIcon(void);

	/**
	** @brief 通过文件扩展名，获取对应的图标资源
	** @param pszFileExt
	** @return 图标资源
	**/
	HICON GetIconByFileExtW(const wchar_t * pszFileExt) const;

	/**
	** @brief 通过图标 ID，获取对应的图标资源
	** @param uIconID
	** @return 图标资源
	**/
	HICON GetIconByID(const unsigned int uIconID) const;

	/**
	** @brief 获取已经缓存了多少个图标资源
	** @return 已经缓存了多少个图标资源
	*/
	unsigned int GetCachedIconNum(void) const;

private:

	std::list<CCacheIcon *> m_IconInfoList;
};
