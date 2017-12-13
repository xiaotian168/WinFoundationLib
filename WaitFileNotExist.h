
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
** @brief 等待指定文件不存在后返回
** @param[in] pszFile 文件路径
** @param[in] uTryCount 尝试打开文件多少次
** @param[in] uTryElapse 每次打开文件之间等待多少毫秒
** @return true 表示成功，false 表示失败
** @remark
**
** 该函数使用一个循环来尝试打开指定文件，用户指定一个循环次数，以及每次打开文件后，等待多少毫秒后，再进行下一次打开操作
*/
extern bool WaitFileNotExistA(const char * pszFile, const unsigned int uTryCount = 0xFFFFFFFF, const unsigned int uTryElapse = 500);
extern bool WaitFileNotExistW(const wchar_t * pszFile, const unsigned int uTryCount = 0xFFFFFFFF, const unsigned int uTryElapse = 500);

/**
** @brief
** @param[in] pszFile 文件路径
** @param[in] uTryCount 尝试打开文件多少次
** @param[in] uTryElapse 每次打开文件之间等待多少毫秒
** @return true 表示成功，false 表示失败
** @remark
**
** 该函数使用一个循环来尝试打开指定文件，用户指定一个循环次数，以及每次打开文件后，等待多少毫秒后，再进行下一次打开操作
*/
extern bool DeleteFileAndWaitA(const char * pszFile, const unsigned int uTryCount = 0xFFFFFFFF, const unsigned int uTryElapse = 500);
extern bool DeleteFileAndWaitW(const wchar_t * pszFile, const unsigned int uTryCount = 0xFFFFFFFF, const unsigned int uTryElapse = 500);

/**
×× @brief 移除指定文件的只读属性
×× @param[in] pszFile 文件路径
×× @return true 表示成功，false 表示失败
*/
extern bool RemoveFileReadOnlyAttrubiteA(const char * pszFile);
extern bool RemoveFileReadOnlyAttrubiteW(const wchar_t * pszFile);
