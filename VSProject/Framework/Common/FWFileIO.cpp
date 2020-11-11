#include "FWFileIO.h"
#include "FWTools.h"
//#include <atlbase.h>
//#include <atlconv.h>

FW_NS_BEGIN


static FWFileIO _FileIO;

FWFileIO::FWFileIO()
{
	_fileNameMutex = new std::mutex();
	_fileDirectoryMutex = new std::mutex();
	memset(_moduleFileName, 0, sizeof(_moduleFileName));
	memset(_moduleFileDirectory, 0, sizeof(_moduleFileName));
}

FWFileIO::~FWFileIO()
{
	delete ((std::mutex*)_fileNameMutex);
	delete ((std::mutex*)_fileDirectoryMutex);
}

FWFileIO * FWFileIO::GetInstance()
{
	return &_FileIO;
}

FWData FWFileIO::LoadFile(const char * filename)
{
	FWData ret;
	FILE * filePointer = nullptr;
	do
	{
		errno_t err = fopen_s(&filePointer, filename, "rb");
		if (err != 0 || !filePointer)
			break;
		fseek(filePointer, 0, SEEK_END);
		long filesize = ftell(filePointer);
		fseek(filePointer, 0, SEEK_SET);
		if (filesize <= 0L)
			break;
		char * buffer = (char*)FW_MALLOC(filesize);
		size_t c = fread(buffer, 1, filesize, filePointer);
		if (ferror(filePointer) || c != (size_t)filesize)
		{
			FW_FREE(buffer);
			break;
		}
		ret.SetIn(buffer, (int)filesize);
	} while (false);
	if (filePointer)
	{
		fclose(filePointer);
	}
	return ret;
}

FWString FWFileIO::LoadFileToString(const char * filename)
{
	FWData data = this->LoadFile(filename);
	if (data.IsNull())
	{
		return FWString();
	}
	else
	{
		return FWString(data.GetPointer(), data.GetSize());
	}
}

FWData FWFileIO::LoadFileFromModuleFileDirectory(const char * filename)
{
	std::string path = this->GetModuleFileDirectory();
	if (filename[0] != '\\' && filename[0] != '/')
	{
		path.append("\\");
	}
	path.append(filename);
	return this->LoadFile(path.c_str());
}

FWString FWFileIO::LoadFileFromModuleFileDirectoryToString(const char * filename)
{
	std::string path = this->GetModuleFileDirectory();
	if (filename[0] != '\\' && filename[0] != '/')
	{
		path.append("\\");
	}
	path.append(filename);
	return this->LoadFileToString(path.c_str());
}

bool FWFileIO::SaveFile(const char * filename, const FWData & data)
{
	return this->SaveFile(filename, data.GetPointer(), data.GetSize());
}

bool FWFileIO::SaveFile(const char * filename, const char * buf, size_t size)
{
	if (!buf || size == 0)
	{
		return false;
	}
	bool ret = false;
	FILE * filePointer = nullptr;
	do
	{
		errno_t err = fopen_s(&filePointer, filename, "wb");
		if (err != 0 || !filePointer)
			break;
		size_t c = fwrite(buf, 1, size, filePointer);
		if (ferror(filePointer) || c != size)
		{
			break;
		}
		ret = true;
	} while (false);
	if (filePointer)
	{
		fclose(filePointer);
	}
	return ret;
}

bool FWFileIO::SaveFile(const char * filename, const FWString & s)
{
	return this->SaveFile(filename, s.C_Str(), s.Size());
}

bool FWFileIO::SaveFileFromModuleFileDirectory(const char * filename, const FWData & data)
{
	return this->SaveFileFromModuleFileDirectory(filename, data.GetPointer(), data.GetSize());
}

bool FWFileIO::SaveFileFromModuleFileDirectory(const char * filename, const char * buf, size_t size)
{
	std::string path = this->GetModuleFileDirectory();
	if (filename[0] != '\\' && filename[0] != '/')
	{
		path.append("\\");
	}
	path.append(filename);
	return this->SaveFile(path.c_str(), buf, size);
}

bool FWFileIO::SaveFileFromModuleFileDirectory(const char * filename, const FWString & s)
{
	return this->SaveFileFromModuleFileDirectory(filename, s.C_Str(), s.Size());
}

bool FWFileIO::IsFileExist(const char * filename)
{
	DWORD r = GetFileAttributesA(filename);
	return (r != INVALID_FILE_ATTRIBUTES && (r & FILE_ATTRIBUTE_DIRECTORY) == 0);
}

bool FWFileIO::CreateDirectory(const char * dir)
{
	if (this->IsDirectoryExist(dir))
	{
		return true;
	}
	std::string path = dir;
	if (path.at(path.size() - 1) != '\\' || path.at(path.size() - 1) != '/')
	{
		path.append("\\");
	}
	std::string::size_type start = 0;
	std::string::size_type found = std::string::npos;
	std::vector<std::string> dirs;
	while ((found = path.find_first_of("/\\", start)) != std::string::npos)
	{
		dirs.push_back(path.substr(0, found));
		start = found + 1;
	}
	for (std::vector<std::string>::iterator it = dirs.begin(); it != dirs.end(); it++)
	{
		BOOL ret = CreateDirectoryA((*it).c_str(), NULL);
		if (!ret && ERROR_ALREADY_EXISTS != GetLastError())
		{
			break;
		}
	}
	return this->IsDirectoryExist(dir);
}

bool FWFileIO::IsDirectoryExist(const char * dir)
{
	DWORD r = GetFileAttributesA(dir);
	return (r != INVALID_FILE_ATTRIBUTES && (r & FILE_ATTRIBUTE_DIRECTORY));
}

const char * FWFileIO::GetModuleFileName()
{
	if (_moduleFileName[0] == '\0')
	{
		((std::mutex*)_fileNameMutex)->lock();
		if (_moduleFileName[0] == '\0')
		{
			char buffer[1024/*MAX_PATH*/];
			DWORD r = GetModuleFileNameA(NULL, buffer, 1024/*MAX_PATH*/);
			if (r > 0)
			{
				for (int i = (int)r; i >= 0; i--)
				{
					_moduleFileName[i] = buffer[i];
				}
			}
		}
		((std::mutex*)_fileNameMutex)->unlock();
	}
	return _moduleFileName;
}

const char * FWFileIO::GetModuleFileDirectory()
{
	if (_moduleFileDirectory[0] == '\0')
	{
		((std::mutex*)_fileDirectoryMutex)->lock();
		if (_moduleFileDirectory[0] == '\0')
		{
			char buffer[1024/*MAX_PATH*/];
			DWORD r = GetModuleFileNameA(NULL, buffer, 1024/*MAX_PATH*/);
			if (r > 0)
			{
				int si = -1;
				for (int i = (int)r; i >= 0; i--)
				{
					if (buffer[i] == '\\')
					{
						si = i - 1;
						break;
					}
				}
				for (int i = si; i >= 0; i--)
				{
					_moduleFileDirectory[i] = buffer[i];
				}
			}
		}
		((std::mutex*)_fileDirectoryMutex)->unlock();
	}
	return _moduleFileDirectory;
}


FW_NS_END
