
#pragma once

#include "WFLibConfig.h"

struct OSVERSION
{
	unsigned int uMajor{ 0 };
	unsigned int uMinor{ 0 };
	unsigned int uBuildNum{ 0 };
};

/**
** @brief ��ȡϵͳ�汾����Ϣ
*/
extern bool GetOSVersion(OSVERSION & OSVer);
