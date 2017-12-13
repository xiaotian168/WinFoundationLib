
#include "BuildDirectoryPath.h"
#include "WFLibConfig.h"

bool BuildDirectoryPathA(const char * szPath) {
	if (0 == szPath) {
		return false;
	}
	const size_t uLen = strlen(szPath);
	char * szPathBuild = 0;
	//
	szPathBuild = new char[uLen + 1];
	memset(szPathBuild, 0, uLen + 1);
	for (size_t i = 0; i < uLen; ++i) {
		szPathBuild[i] = szPath[i];
		if ('\\' == szPathBuild[i] || '/' == szPathBuild[i]) {
			szPathBuild[i + 1] = 0;
			CreateDirectoryA(szPathBuild, 0);
		}
		else if (uLen - 1 == i)
		{
			CreateDirectoryA(szPathBuild, 0);
		}
	}
	if (0 != szPathBuild) {
		delete[]szPathBuild;
		szPathBuild = NULL;
	}
	return true;
}

bool BuildDirectoryPathW(const wchar_t * szPath) {
	if (0 == szPath) {
		return false;
	}
	const size_t uLen = wcslen(szPath) * sizeof(wchar_t);
	wchar_t * szPathBuild = 0;
	//
	szPathBuild = new wchar_t[uLen + 1];
	memset(szPathBuild, 0, uLen + 1);

	for (size_t i = 0; i < uLen; ++i) {
		szPathBuild[i] = szPath[i];
		if ('\\' == szPathBuild[i] || '/' == szPathBuild[i]) {
			szPathBuild[i + 1] = 0;
			CreateDirectoryW(szPathBuild, 0);
		}
		else if (uLen - 1 == i)
		{
			CreateDirectoryW(szPathBuild, 0);
		}
	}
	if (0 != szPathBuild) {
		delete[]szPathBuild;
		szPathBuild = NULL;
	}
	return true;
}
