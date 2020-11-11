#ifndef __FRAMEWORK_FILEIO_H__
#define __FRAMEWORK_FILEIO_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "FWData.h"
#include "FWString.h"

FW_NS_BEGIN


/*
文件IO
*/
class FW_DLL FWFileIO
{
public:
	FWFileIO();
	~FWFileIO();

	static FWFileIO * GetInstance();
	
	/*
	加载文件
	*/
	FWData LoadFile(const char * filename);
	FWString LoadFileToString(const char * filename);
	FWData LoadFileFromModuleFileDirectory(const char * filename);
	FWString LoadFileFromModuleFileDirectoryToString(const char * filename);

	/*
	保存文件
	必须确保filename中的文件夹路径是存在的
	*/
	bool SaveFile(const char * filename, const FWData & data);
	bool SaveFile(const char * filename, const char * buf, size_t size);
	bool SaveFile(const char * filename, const FWString & s);
	bool SaveFileFromModuleFileDirectory(const char * filename, const FWData & data);
	bool SaveFileFromModuleFileDirectory(const char * filename, const char * buf, size_t size);
	bool SaveFileFromModuleFileDirectory(const char * filename, const FWString & s);

	/*
	查看文件是否存在
	*/
	bool IsFileExist(const char * filename);

	/*
	创建文件夹
	*/
	bool CreateDirectory(const char * dir);

	/*
	查看文件夹是否存在
	*/
	bool IsDirectoryExist(const char * dir);

	/*
	获取当前exe全路径
	*/
	const char * GetModuleFileName();

	/*
	获取当前exe所在目录
	不包含末尾'\\'
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