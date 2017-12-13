
#pragma once

#if defined UNICODE || defined _UNICODE
#	define BuildTempFilePath BuildTempFilePathW
#else
#	define BuildTempFilePath BuildTempFilePathA
#endif

//-------------------------------------------------------------------------------------------------
// @brief 在系统临时目录中生成一个随机文件名的完整文件路径
// @return TRUE 表示成功，其余值表示失败
// @remark
//
// 该函数会使用系统临时目录路径与 GetTickCount() 函数生成完整的临时文件路径，该文件以 .dat 为后缀名
// 该函数不会生成任何文件，只会生成一个路径字符串
//-------------------------------------------------------------------------------------------------

extern bool BuildTempFilePathA(char * pszPath, const unsigned int uSize);
extern bool BuildTempFilePathW(wchar_t * pszPath, const unsigned int uSize);
