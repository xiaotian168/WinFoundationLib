
#pragma once

#include "WFLibConfig.h"

#define USE_STD_STRING_BASE64

/**
** @brief ����ָ�����ȵ����ݻ�����೤�� Base64 �ַ���
** @param uBufferSize Ҫ��������ݵĳ��ȣ���λ���ֽڣ�
** @return ������ Base64 �ַ������ȣ���λ���ַ���
**/
extern unsigned int CalcBase64EncodeSize(const unsigned int uBufferSize);

/**
** @brief ��ָ�����ݽ��� Base64 ����
** @param pBuffer
** @param uBufferSize
** @param pBufferOut
** @param uBufferOutSize
** @return true ��ʾ�ɹ���false ��ʾʧ��
*/
extern bool Base64Encode(const unsigned char * pBuffer, const unsigned int uBufferSize, unsigned char * pBufferOut, const unsigned int uBufferOutSize);

#if defined USE_STD_STRING_BASE64

/**
** @brief ��ָ�����ݽ��� Base64 ���룬��������������Ϊ std::string
** @param pBuffer Ҫ���б��������
** @param uBufferSize Ҫ���б�������ݴ�С����λ���ֽڣ�
** @param strBase64 ���ڱ�������� Base64 �ַ���
** @return true ��ʾ�ɹ���false ��ʾʧ��
**/
extern bool StdBase64Encode(const unsigned char * pBuffer, const unsigned int uBufferSize, std::string & strBase64);

#endif
