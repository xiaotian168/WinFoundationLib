
#include "CIconCache.h"

CIconCache::CCacheIcon::CCacheIcon()
{
	m_hIcon = 0;
	memset(m_szFileExt, 0, sizeof(m_szFileExt));
	m_IconSource = eIconSource_Unknown;
	m_uIconID = 0;
}

CIconCache * CIconCache::GetInstance(void)
{
	static CIconCache IconCache;
	return &IconCache;
}

CIconCache::CIconCache()
{

}

CIconCache::~CIconCache()
{
	RemoveAllIcon();
}

HICON CIconCache::AddIconByFullFilePathW(const wchar_t * pszFullFilePath)
{
	HICON hIcon = 0;
	CCacheIcon * pCacheIcon = 0;
	SHFILEINFOW ShFileInfoW = { 0 };
	wchar_t szFileExt[MAX_FILE_EXT_SIZE] = { 0 };
	FILE * pFileHandle = 0;

	if (pszFullFilePath)
	{
		if (0 == _wfopen_s(&pFileHandle, pszFullFilePath, L"rb"))
		{
			fclose(pFileHandle);
			pFileHandle = 0;

			_wsplitpath_s(
				pszFullFilePath,
				0, 0,
				0, 0,
				0, 0,
				szFileExt, MAX_FILE_EXT_SIZE);

			hIcon = GetIconByFileExtW(szFileExt);

			if (!hIcon)
			{
				if (SHGetFileInfoW(pszFullFilePath, 0, &ShFileInfoW, sizeof(ShFileInfoW), SHGFI_ICON))
				{
					pCacheIcon = new CCacheIcon();

					if (pCacheIcon)
					{
						wcscpy_s(pCacheIcon->m_szFileExt, MAX_FILE_EXT_SIZE, szFileExt);
						pCacheIcon->m_IconSource = eIconSource_ExtractFromFile;
						pCacheIcon->m_hIcon = ShFileInfoW.hIcon;

						m_IconInfoList.push_back(pCacheIcon);

						hIcon = ShFileInfoW.hIcon;
					}
				}
			}
		}
	}

	return hIcon;
}

bool CIconCache::AddIconByFileExt(const HICON hIcon, const wchar_t * pszFileExt)
{
	bool bRet = false;
	CCacheIcon * pCacheIcon = 0;

	if (hIcon && pszFileExt)
	{
		if (!GetIconByFileExtW(pszFileExt))
		{
			pCacheIcon = new CCacheIcon();

			if (pCacheIcon)
			{
				wcscpy_s(pCacheIcon->m_szFileExt, MAX_FILE_EXT_SIZE, pszFileExt);
				pCacheIcon->m_IconSource = eIconSource_UserRef;
				pCacheIcon->m_hIcon = hIcon;

				m_IconInfoList.push_back(pCacheIcon);

				bRet = true;
			}
		}
		else
		{
			bRet = true;
		}
	}

	return bRet;
}

bool CIconCache::AddIconByID(const HICON hIcon, const unsigned int uIconID)
{
	bool bRet = false;
	CCacheIcon * pCacheIcon = 0;

	if (hIcon)
	{
		if (!GetIconByID(uIconID))
		{
			pCacheIcon = new CCacheIcon();

			if (pCacheIcon)
			{
				pCacheIcon->m_IconSource = eIconSource_UserRef;
				pCacheIcon->m_hIcon = hIcon;
				pCacheIcon->m_uIconID = uIconID;

				m_IconInfoList.push_back(pCacheIcon);

				bRet = true;
			}
		}
		else
		{
			bRet = true;
		}
	}

	return bRet;
}

bool CIconCache::RemoveIconByFileExtW(const wchar_t * pszFileExt)
{
	bool bRet = false;

	if (pszFileExt)
	{
		for (auto pCacheIcon : m_IconInfoList)
		{
			if (pCacheIcon)
			{
				if (0 == _wcsicmp(pCacheIcon->m_szFileExt, pszFileExt))
				{
					if (eIconSource_ExtractFromFile == pCacheIcon->m_IconSource)
					{
						DestroyIcon(pCacheIcon->m_hIcon);
					}

					delete pCacheIcon;
					m_IconInfoList.remove(pCacheIcon);

					bRet = true;

					break;
				}
			}
		}
	}

	return bRet;
}

bool CIconCache::RemoveIconByID(const unsigned int uIconID)
{
	bool bRet = false;

	for (auto pCacheIcon : m_IconInfoList)
	{
		if (pCacheIcon)
		{
			if (uIconID == pCacheIcon->m_uIconID)
			{
				if (eIconSource_ExtractFromFile == pCacheIcon->m_IconSource)
				{
					DestroyIcon(pCacheIcon->m_hIcon);
				}

				delete pCacheIcon;
				m_IconInfoList.remove(pCacheIcon);

				bRet = true;

				break;
			}
		}
	}

	return bRet;
}

void CIconCache::RemoveAllIcon(void)
{
	for (auto pCacheIcon : m_IconInfoList)
	{
		if (pCacheIcon)
		{
			if (eIconSource_ExtractFromFile == pCacheIcon->m_IconSource)
			{
				DestroyIcon(pCacheIcon->m_hIcon);
			}

			delete pCacheIcon;
		}
	}

	m_IconInfoList.clear();
}

HICON CIconCache::GetIconByFileExtW(const wchar_t * pszFileExt) const
{
	HICON hIcon = 0;

	if (pszFileExt)
	{
		for (const auto & pCacheIcon : m_IconInfoList)
		{
			if (pCacheIcon)
			{
				if (0 == _wcsicmp(pszFileExt, pCacheIcon->m_szFileExt))
				{
					hIcon = pCacheIcon->m_hIcon;

					break;
				}
			}
		}
	}

	return hIcon;
}

HICON CIconCache::GetIconByID(const unsigned int uIconID) const
{
	HICON hIcon = 0;

	for (const auto & pCacheIcon : m_IconInfoList)
	{
		if (pCacheIcon)
		{
			if (uIconID == pCacheIcon->m_uIconID)
			{
				hIcon = pCacheIcon->m_hIcon;

				break;
			}
		}
	}

	return hIcon;
}

unsigned int CIconCache::GetCachedIconNum(void) const
{
	return m_IconInfoList.size();
}
