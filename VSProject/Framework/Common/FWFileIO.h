#ifndef __FRAMEWORK_FILEIO_H__
#define __FRAMEWORK_FILEIO_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "FWData.h"
#include "FWString.h"

FW_NS_BEGIN


/*
�ļ�IO
*/
class FW_DLL FWFileIO
{
public:
	FWFileIO();
	~FWFileIO();

	static FWFileIO * GetInstance();
	
	/*
	�����ļ�
	*/
	FWData LoadFile(const char * filename);
	FWString LoadFileToString(const char * filename);
	FWData LoadFileFromModuleFileDirectory(const char * filename);
	FWString LoadFileFromModuleFileDirectoryToString(const char * filename);

	/*
	�����ļ�
	����ȷ��filename�е��ļ���·���Ǵ��ڵ�
	*/
	bool SaveFile(const char * filename, const FWData & data);
	bool SaveFile(const char * filename, const char * buf, size_t size);
	bool SaveFile(const char * filename, const FWString & s);
	bool SaveFileFromModuleFileDirectory(const char * filename, const FWData & data);
	bool SaveFileFromModuleFileDirectory(const char * filename, const char * buf, size_t size);
	bool SaveFileFromModuleFileDirectory(const char * filename, const FWString & s);

	/*
	�鿴�ļ��Ƿ����
	*/
	bool IsFileExist(const char * filename);

	/*
	�����ļ���
	*/
	bool CreateDirectory(const char * dir);

	/*
	�鿴�ļ����Ƿ����
	*/
	bool IsDirectoryExist(const char * dir);

	/*
	��ȡ��ǰexeȫ·��
	*/
	const char * GetModuleFileName();

	/*
	��ȡ��ǰexe����Ŀ¼
	������ĩβ'\\'
	*/
	const char * GetModuleFileDirectory();
	
private:
	void	* _fileNameMutex;
	char	  _moduleFileName[1024/*MAX_PATH*/];
	void	* _fileDirectoryMutex;
	char	  _moduleFileDirectory[1024/*MAX_PATH*/];
};



FW_NS_END


#endif //!__FRAMEWORK_FILEIO_H__