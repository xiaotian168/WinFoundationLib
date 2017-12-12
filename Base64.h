
#pragma once

#include "WFLibConfig.h"

#define USE_STD_STRING_BASE64

/**
** @brief 计算指定长度的内容会产生多长的 Base64 字符串
** @param uBufferSize 要计算的内容的长度（单位：字节）
** @return 产生的 Base64 字符串长度（单位：字符）
**/
extern unsigned int CalcBase64EncodeSize(const unsigned int uBufferSize);

/**
** @brief 对指定内容进行 Base64 编码
** @param pBuffer
** @param uBufferSize
** @param pBufferOut
** @param uBufferOutSize
** @return true 表示成功，false 表示失败
*/
extern bool Base64Encode(const unsigned char * pBuffer, const unsigned int uBufferSize, unsigned char * pBufferOut, const unsigned int uBufferOutSize);

#if defined USE_STD_STRING_BASE64

/**
** @brief 对指定内容进行 Base64 编码，并将编码结果保存为 std::string
** @param pBuffer 要进行编码的内容
** @param uBufferSize 要进行编码的内容大小（单位：字节）
** @param strBase64 用于保存编码后的 Base64 字符串
** @return true 表示成功，false 表示失败
**/
extern bool StdBase64Encode(const unsigned char * pBuffer, const unsigned int uBufferSize, std::string & strBase64);

#endif
