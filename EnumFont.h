
#pragma once

#if defined UNICODE || defined _UNICODE
#	define IsFontFamilyExist IsFontFamilyExistW
#else
#	define IsFontFamilyExist IsFontFamilyExistA
#endif

/**
** @brief ����ϵͳ�а�װ�˶���������
** @return ϵͳ���Ѿ���װ����������
**/
extern bool EnumFontCount(unsigned int & uFontCount);

/**
** @brief �ж�ϵͳ���Ƿ�װ��ָ�������������
** @param[in] szFontFamilyName �����������
** @return TRUE ��ʾ�Ѿ���װ������ֵ��ʾû�а�װ
**/
extern bool IsFontFamilyExistA(const char * szFontFamilyName);
extern bool IsFontFamilyExistW(const wchar_t * szFontFamilyName);
