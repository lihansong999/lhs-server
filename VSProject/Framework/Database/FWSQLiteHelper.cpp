#include "FWSQLiteHelper.h"
#include "../Common/FWOutPut.h"


FW_NS_BEGIN


static int _Sqlite_Exec_Callback(void * para, int column_count, char** column_value, char** column_name)
{
	if (!para)
	{
		return 0;
	}
	std::vector<FWSQLiteQRRow>* results = (std::vector<FWSQLiteQRRow>*)(((FWSQLiteQR*)para)->_data);
	FWSQLiteQRRow row;
	for (int i = 0; i < column_count; i++)
	{
		(*((std::map<std::string, std::string>*)row._rowData))[column_name[i]] = column_value[i];
	}
	results->push_back(std::move(row));
	return 0;
}

FWSQLiteHelper::FWSQLiteHelper()
	:_sqlite(nullptr)
{

}

FWSQLiteHelper::~FWSQLiteHelper()
{
	this->Close();
}

bool FWSQLiteHelper::Open(const char * path, bool force /*= false*/)
{
	this->Close();
	if (!path)
	{
		//return sqlite3_open(":memory:", &_sqlite) == SQLITE_OK;
		FW_LOG_ERROR("%s", "path == nullptr");
		return false;
	}
	int flags = SQLITE_OPEN_READWRITE;
	if (force)
	{
		flags |= SQLITE_OPEN_CREATE;
	}
	return sqlite3_open_v2(path, &_sqlite, flags, 0) == SQLITE_OK;
}

void FWSQLiteHelper::Close()
{
	if (_sqlite)
	{
		sqlite3_close(_sqlite);
		_sqlite = nullptr;
	}
}

bool FWSQLiteHelper::Execute(const char * sql, FWSQLiteQR * queryResults)
{
	if (queryResults)
	{
		queryResults->Clear();
	}
	if (!_sqlite)
	{
		FW_LOG_ERROR("%s", "_sqlite == nullptr");
		return false;
	}
	if (!sql || sql[0] == 0)
	{
		FW_LOG_ERROR("%s", "sql == nullptr »ò sql[0] == 0");
		return false;
	}
	char * err = nullptr;
	int r = sqlite3_exec(_sqlite, sql, &_Sqlite_Exec_Callback, queryResults, &err);
	if (r != SQLITE_OK)
	{
		if (err)
		{
			FW_LOG_ERROR("%s", err);
			sqlite3_free(err);
		}
	}
	return r == SQLITE_OK;
}


//////////////////////////////////////////////////////////////////////////


FWSQLiteQR::FWSQLiteQR()
{
	_data = new std::vector<FWSQLiteQRRow>();
}

FWSQLiteQR::~FWSQLiteQR()
{
	delete (std::vector<FWSQLiteQRRow>*)_data;
}

size_t FWSQLiteQR::Size() const
{
	return ((std::vector<FWSQLiteQRRow>*)_data)->size();
}

const FWSQLiteQRRow * FWSQLiteQR::GetRow(unsigned int index) const
{
	if (index >= ((std::vector<FWSQLiteQRRow>*)_data)->size())
	{
		FW_LOG_ERROR("%s", "index >= _data->size()");
		return nullptr;
	}
	return &((*((std::vector<FWSQLiteQRRow>*)_data))[index]);
}

void FWSQLiteQR::Foreach(bool(*callback)(const FWSQLiteQRRow *)) const
{
	if (!callback)
	{
		return;
	}
	for (std::vector<FWSQLiteQRRow>::iterator it = ((std::vector<FWSQLiteQRRow>*)_data)->begin(); it != ((std::vector<FWSQLiteQRRow>*)_data)->end(); it++)
	{
		if (!(*callback)(&(*it)))
		{
			break;
		}
	}
}

void FWSQLiteQR::Clear()
{
	((std::vector<FWSQLiteQRRow>*)_data)->clear();
}


//////////////////////////////////////////////////////////////////////////


FWSQLiteQRRow::FWSQLiteQRRow()
{
	_rowData = new std::map<std::string, std::string>();
}

FWSQLiteQRRow::FWSQLiteQRRow(const FWSQLiteQRRow & other)
{
	_rowData = new std::map<std::string, std::string>();
	std::map<std::string, std::string> * od = (std::map<std::string, std::string>*)other._rowData;
	std::map<std::string, std::string> * td = (std::map<std::string, std::string>*)_rowData;
	td->insert(od->begin(), od->end());
}

FWSQLiteQRRow& FWSQLiteQRRow::operator=(const FWSQLiteQRRow & other)
{
	if (!_rowData)
	{
		_rowData = new std::map<std::string, std::string>();
	}
	((std::map<std::string, std::string>*)_rowData)->clear();
	std::map<std::string, std::string> * od = (std::map<std::string, std::string>*)other._rowData;
	std::map<std::string, std::string> * td = (std::map<std::string, std::string>*)_rowData;
	td->insert(od->begin(), od->end());
	return *this;
}

FWSQLiteQRRow::FWSQLiteQRRow(FWSQLiteQRRow && other)
{
	_rowData = other._rowData;
	other._rowData = nullptr;
}

FWSQLiteQRRow& FWSQLiteQRRow::operator=(FWSQLiteQRRow && other)
{
	if (_rowData)
	{
		delete (std::map<std::string, std::string>*)_rowData;
	}
	_rowData = other._rowData;
	other._rowData = nullptr;
	return *this;
}

FWSQLiteQRRow::~FWSQLiteQRRow()
{
	if (_rowData)
	{
		delete (std::map<std::string, std::string>*)_rowData;
	}
}

const char * FWSQLiteQRRow::GetColumnValue(const char * name) const
{
	if (!_rowData)
	{
		return nullptr;
	}
	if (!name)
	{
		return nullptr;
	}
	std::map<std::string, std::string>::iterator it = ((std::map<std::string, std::string>*)_rowData)->find(name);
	if (it == ((std::map<std::string, std::string>*)_rowData)->end())
	{
		return nullptr;
	}
	return it->second.c_str();
}

void FWSQLiteQRRow::Foreach(bool(*callback)(const char*, const char*)) const
{
	if (!_rowData)
	{
		return;
	}
	if (!callback)
	{
		return;
	}
	std::map<std::string, std::string> * td = (std::map<std::string, std::string>*)_rowData;
	for (std::map<std::string, std::string>::iterator it = td->begin(); it != td->end(); it++)
	{
		if (!(*callback)(it->first.c_str(), it->second.c_str()))
		{
			break;
		}
	}
}



FW_NS_END
