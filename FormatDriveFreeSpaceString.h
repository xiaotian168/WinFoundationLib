
#pragma once

#if defined UNICODE || defined _UNICODE
#	define FormatDriveFreeSpaceString FormatDriveFreeSpaceStringW
#else
#	define FormatDriveFreeSpaceString FormatDriveFreeSpaceStringA
#endif

//---------------------------------------------------------------------------------------------
// @brief 格式化指定驱动器的剩余空间为字符串描述
// @param[in] 包含驱动器盘符的字符串
// @param[out] szSpaceString 保存格式化结果
// @param[in] uSize szSpaceString 参数的容量（单位：字符）
// @return TRUE 表示成功，其余值表示失败
//---------------------------------------------------------------------------------------------
extern bool FormatDriveFreeSpaceStringA(const char * szDrive, char * szSpaceString, const unsigned int uSize);
extern bool FormatDriveFreeSpaceStringW(const wchar_t * szDrive, wchar_t * szSpaceString, const unsigned int uSize);
