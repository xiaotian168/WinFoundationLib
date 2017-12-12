
#pragma once

//-------------------------------------------------------------------------------------------
// @brief Windows 系统打开文件安全警告相关接口
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
// @brief 备份系统打开文件安全注册表信息
// @return TRUE 表示成功，其余值表示失败 
//-------------------------------------------------------------------------------------------
extern BOOL BackupExecuteWarningRegInfo(void);

//-------------------------------------------------------------------------------------------
// @brief 恢复系统打开文件安全注册表信息
// @return TRUE 表示成功，其余值表示失败 
// @remark 必须最少调用一次 BackupExecuteWarningRegInfo() 函数进行备份后，该函数才能正常工作
//-------------------------------------------------------------------------------------------
extern BOOL RestoreExecuteWarningRegInfo(void);

//-------------------------------------------------------------------------------------------
// @brief 设置系统打开文件安全注册表信息
// @param[in] szLowRiskFileTypes 文件扩展名列表，系统打开该类型的文件时，认为是低风险的
// @param[in] szLowRiskFileTypes 文件扩展名列表，系统打开该类型的文件时，认为是中等风险的
// @param[in] szLowRiskFileTypes 文件扩展名列表，系统打开该类型的文件时，认为是高风险的
//-------------------------------------------------------------------------------------------
extern BOOL WriteExecuteWarningRegInfo(
	const TCHAR * szLowRiskFileTypes,
	const TCHAR * szModRiskFileTypes,
	const TCHAR * szHighRiskFileTypes);
