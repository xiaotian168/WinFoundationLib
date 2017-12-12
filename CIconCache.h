
#pragma once

#include "WFLibConfig.h"

/**
** @brief ͼ�껺����
** @note
**
** ��������ļ��ļ���չ����ͼ�� ID ���ļ�ͼ��Ķ�Ӧ��ϵ�����治ͬ�ļ���չ�Ե�ͼ����Դ
** �û�ͨ���ļ���չ����ͼ�� ID �ӻ������л�ȡͼ����Դ���û�ͨ��������ʽ���ͼ����Դ���������У�
**
** 1. ����һ���������ļ�·������ͼ�껺���������ȡͼ�꣬����¼�ļ���չ������Щͼ�����ͼ�껺��������
** 2. ����һ��ͼ����Դ�Լ���Ӧ���ļ���չ������ͼ�껺�汣�棬ͼ�껺���಻��������Щͼ��
** 3. ����һ��ͼ����Դ�Լ���Ӧ��ͼ�� ID����ͼ�껺�汣�棬ͼ�껺���಻��������Щͼ��
**
** ͼ�껺����ֻ�����ά�����ļ���չ�� - ͼ�꡿�Լ���ͼ�� ID - ͼ�꡿������ϵ�����ύ��ά������֮��Ĺ�ϵ
** ͼ�껺����Ա�֤ͬһ���ļ���չ��ֻ��һ��ͼ����Դ���Լ�ͬһ�� ID ֻ��һ��ͼ����Դ
** ����ͼ�껺�治�ᱣ֤�ļ���չ����ͼ�� ID ֮�䲻������ظ�ͼ����Դ
** �����û����ļ� C:\MyProgram.exe ��ͼ�껺�����������������ȡ C:\MyProgram.exe ��ͼ�꣬��ͨ��
** ĳ�� ID ��ͼ����ӵ�ͼ�껺�棬ͼ�껺��û�������ж�������ӵ�ͼ����ͬһ��ͼ����Դ
**/
class CIconCache
{
public:

	/* ����ļ���չ�����ȣ���λ���ַ��� */
	static const unsigned int MAX_FILE_EXT_SIZE = 64;

private:

	/**
	** @brief ͼ����Դ
	**/
	enum emIconSource
	{
		/* δ֪��Դ�������͵�ͼ�꣬�����಻�����κ����ٲ��� */
		eIconSource_Unknown,

		/* ͼ���ɻ�������ļ���ȡ�������͵�ͼ�꣬�ɻ�����ʹ�� DestroyIcon �������� */
		eIconSource_ExtractFromFile,

		/* �����û����õ�ͼ�꣬�����͵�ͼ�꣬�����಻�����κ����ٲ��� */
		eIconSource_UserRef,
	};

	struct CCacheIcon
	{
	public:

		CCacheIcon();

	public:

		HICON m_hIcon;
		wchar_t m_szFileExt[MAX_FILE_EXT_SIZE];
		emIconSource m_IconSource;
		unsigned int m_uIconID;
	};

public:

	static CIconCache * GetInstance(void);

protected:

	CIconCache();

public:

	~CIconCache();

public:

	/**
	** @brief ��ָ���ļ�����ȡͼ����Դ������ͼ����Դ��ӵ�������
	** @param pszFullFilePath
	** @return �ɹ����ط� 0 ͼ����Դ��ʧ�ܷ��� 0
	** @note
	**
	** ��������Զ��ж�ָ�����ļ���չ���Ƿ��Ѿ���ӹ������û����ӹ����ٽ�����Ӳ���
	** �ļ���չ���ĳ��Ȳ��ܳ������� MAX_FILE_EXT_SIZE ��ֵ������ͼ�껺��ʧ��
	**
	** ���ˣ�pszFullFilePath �����������ļ�������Ŀ¼ͼ�꣬�����Լ��ֶ��� ID ����Ӱ�
	*/
	HICON AddIconByFullFilePathW(const wchar_t * pszFullFilePath);

	/**
	** @brief ��ָ�����ļ���չ����ͼ����Դ��ӵ�������
	** @param hIcon
	** @param pszFullFilePath
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	** @note
	**
	** ��������Զ��ж�ָ�����ļ���չ���Ƿ��Ѿ���ӹ������û����ӹ����ٽ�����Ӳ���
	*/
	bool AddIconByFileExt(const HICON hIcon, const wchar_t * pszFileExt);

	/**
	** @brief ��ָ����ͼ�� ID ��ͼ����Դ��ӵ�������
	** @param hIcon
	** @param pszFullFilePath
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	** @note
	**
	** ��������Զ��ж�ָ����ͼ�� ID �Ƿ��Ѿ���ӹ������û����ӹ����ٽ�����Ӳ���
	*/
	bool AddIconByID(const HICON hIcon, const unsigned int uIconID);

	/**
	** @brief �Ƴ�ָ���ļ���չ����Ӧ��ͼ����Դ
	** @param pszFileExt �ļ�������
	** @return true ��ʾ�ɹ���false ��ʾʧ��
 	*/
	bool RemoveIconByFileExtW(const wchar_t * pszFileExt);

	/**
	** @brief �Ƴ�ָ�� ID ��Ӧ��ͼ����Դ
	** @param uIconID ͼ�� ID
	** @return true ��ʾ�ɹ���false ��ʾʧ��
	*/
	bool RemoveIconByID(const unsigned int uIconID);

	/**
	** @brief �Ƴ�����ͼ����Դ
	*/
	void RemoveAllIcon(void);

	/**
	** @brief ͨ���ļ���չ������ȡ��Ӧ��ͼ����Դ
	** @param pszFileExt
	** @return ͼ����Դ
	**/
	HICON GetIconByFileExtW(const wchar_t * pszFileExt) const;

	/**
	** @brief ͨ��ͼ�� ID����ȡ��Ӧ��ͼ����Դ
	** @param uIconID
	** @return ͼ����Դ
	**/
	HICON GetIconByID(const unsigned int uIconID) const;

	/**
	** @brief ��ȡ�Ѿ������˶��ٸ�ͼ����Դ
	** @return �Ѿ������˶��ٸ�ͼ����Դ
	*/
	unsigned int GetCachedIconNum(void) const;

private:

	std::list<CCacheIcon *> m_IconInfoList;
};
