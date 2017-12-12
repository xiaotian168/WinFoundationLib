
#pragma once

//-------------------------------------------------------------------------------------------
// @brief Windows ϵͳ���ļ���ȫ������ؽӿ�
//-------------------------------------------------------------------------------------------

#include "WFLibConfig.h"

class CExecuteWarningRegInfo
{
public:

	inline CExecuteWarningRegInfo()
	{
		memset(szOldLowRiskFileTypes, 0, sizeof(szOldLowRiskFileTypes));
		memset(szOldModRiskFileTypes, 0, sizeof(szOldModRiskFileTypes));
		memset(szOldHighRiskFileTypes, 0, sizeof(szOldHighRiskFileTypes));
	}

public:

	TCHAR szOldLowRiskFileTypes[MAX_PATH];
	TCHAR szOldModRiskFileTypes[MAX_PATH];
	TCHAR szOldHighRiskFileTypes[MAX_PATH];
};

//-------------------------------------------------------------------------------------------
// @brief ����ϵͳ���ļ���ȫע�����Ϣ
// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ�� 
//-------------------------------------------------------------------------------------------
extern BOOL BackupExecuteWarningRegInfo(void);

//-------------------------------------------------------------------------------------------
// @brief �ָ�ϵͳ���ļ���ȫע�����Ϣ
// @return TRUE ��ʾ�ɹ�������ֵ��ʾʧ�� 
// @remark �������ٵ���һ�� BackupExecuteWarningRegInfo() �������б��ݺ󣬸ú���������������
//-------------------------------------------------------------------------------------------
extern BOOL RestoreExecuteWarningRegInfo(void);

//-------------------------------------------------------------------------------------------
// @brief ����ϵͳ���ļ���ȫע�����Ϣ
// @param[in] szLowRiskFileTypes �ļ���չ���б�ϵͳ�򿪸����͵��ļ�ʱ����Ϊ�ǵͷ��յ�
// @param[in] szLowRiskFileTypes �ļ���չ���б�ϵͳ�򿪸����͵��ļ�ʱ����Ϊ���еȷ��յ�
// @param[in] szLowRiskFileTypes �ļ���չ���б�ϵͳ�򿪸����͵��ļ�ʱ����Ϊ�Ǹ߷��յ�
//-------------------------------------------------------------------------------------------
extern BOOL WriteExecuteWarningRegInfo(
	const TCHAR * szLowRiskFileTypes,
	const TCHAR * szModRiskFileTypes,
	const TCHAR * szHighRiskFileTypes);
