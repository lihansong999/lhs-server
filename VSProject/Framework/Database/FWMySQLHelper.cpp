#include "FWMySQLHelper.h"
#include "../Common/FWOutPut.h"
#include "../Common/FWTools.h"

FW_NS_BEGIN


#define SETMYSQLQRTYPE(qr, i, v1, v2)	do { if ((qr) && (i) < resultsCount) { ((qr)+(i))->_qrrt = v1; ((qr)+(i))->_mysql_errno_value = v2; } } while(false)


static std::mutex _MySQLInitMutex;
static FWLifeCycleExecute<std::function<void(void)>, std::function<void(void)>> _LifeCycleExecute([](void)->void {
	_MySQLInitMutex.lock();
	mysql_library_init(0, NULL, NULL);
	_MySQLInitMutex.unlock();
}, [](void)->void {
	_MySQLInitMutex.lock();
	mysql_library_end();
	_MySQLInitMutex.unlock();
});


FWMySQLHelper::FWMySQLHelper()
	:_mysql(NULL)
	, _connectTimeOut(0)
	, _readTimeOut(0)
	, _writeTimeOut(0)
	, _port(0)
	, _flag(0L)
{
	memset(_host, 0, sizeof(_host));
	memset(_username, 0, sizeof(_username));
	memset(_passwd, 0, sizeof(_passwd));
	memset(_database, 0, sizeof(_database));
	memset(_charSet, 0, sizeof(_charSet));
}

FWMySQLHelper::~FWMySQLHelper()
{
	this->Disconnect();
}

void FWMySQLHelper::Init(const char * host, const char * username, const char * passwd, const char * database, unsigned int port, unsigned long flag, const char * charSet, unsigned int connectTimeOut, unsigned int readTimeOut, unsigned int writeTimeOut)
{
	this->Disconnect();

	strcpy_s(_host, sizeof(_host), host);
	strcpy_s(_username, sizeof(_username), username);
	strcpy_s(_passwd, sizeof(_passwd), passwd);
	strcpy_s(_database, sizeof(_database), database);
	strcpy_s(_charSet, sizeof(_charSet), charSet);
	_connectTimeOut = connectTimeOut;
	_readTimeOut = readTimeOut;
	_writeTimeOut = writeTimeOut;
	strcpy_s(_host, sizeof(_host), host);
	_port = port;
	_flag = flag;

	if (_charSet[0] == '\0')
	{
		strcpy_s(_charSet, sizeof(_charSet), "utf8mb4");
	}
	if ((_flag & CLIENT_MULTI_STATEMENTS) == 0)
	{
		_flag |= CLIENT_MULTI_STATEMENTS;
	}
}

bool FWMySQLHelper::Connect(unsigned int * mysqlErrorCode /*= nullptr*/)
{
	this->Disconnect();
	_MySQLInitMutex.lock();
	_mysql = mysql_init(NULL);
	_MySQLInitMutex.unlock();
	if (!_mysql)
	{
		FW_LOG_ERROR("%s", "mysql_init  ß∞‹");
		return false;
	}
	int r = 0;
	if (_charSet[0] != '\0')
	{
		r = mysql_options(_mysql, MYSQL_SET_CHARSET_NAME, _charSet);
		if (r != 0)
		{
			FW_LOG_ERROR("%s", "mysql_options MYSQL_SET_CHARSET_NAME  ß∞‹");
			this->Disconnect();
			return false;
		}
	}
	if (_connectTimeOut > 0)
	{
		r = mysql_options(_mysql, MYSQL_OPT_CONNECT_TIMEOUT, &_connectTimeOut);
		if (r != 0)
		{
			FW_LOG_ERROR("%s", "mysql_options MYSQL_OPT_CONNECT_TIMEOUT  ß∞‹");
			this->Disconnect();
			return false;
		}
	}
	if (_readTimeOut > 0)
	{
		r = mysql_options(_mysql, MYSQL_OPT_READ_TIMEOUT, &_readTimeOut);
		if (r != 0)
		{
			FW_LOG_ERROR("%s", "mysql_options MYSQL_OPT_READ_TIMEOUT  ß∞‹");
			this->Disconnect();
			return false;
		}
	}
	if (_writeTimeOut > 0)
	{
		r = mysql_options(_mysql, MYSQL_OPT_WRITE_TIMEOUT, &_writeTimeOut);
		if (r != 0)
		{
			FW_LOG_ERROR("%s", "mysql_options MYSQL_OPT_WRITE_TIMEOUT  ß∞‹");
			this->Disconnect();
			return false;
		}
	}
	if (!mysql_real_connect(_mysql, _host, _username, _passwd, _database, _port, NULL, _flag))
	{
		unsigned int erru = mysql_errno(_mysql);
		const char * errs = mysql_error(_mysql);
		FW_LOG_ERROR("%s%s%u%s%s", "mysql_real_connect", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
		if (mysqlErrorCode)
		{
			*mysqlErrorCode = erru;
		}
		this->Disconnect();
		return false;
	}
	return true;
}

void FWMySQLHelper::Disconnect()
{
	if (_mysql)
	{
		mysql_close(_mysql);
		_mysql = NULL;
	}
}

bool FWMySQLHelper::Ping()
{
	if (!_mysql)
	{
		return false;
	}
	if (mysql_ping(_mysql) != 0)
	{
		this->Disconnect();
		return false;
	}
	return true;
}

FWMySQLExeRet FWMySQLHelper::Execute(const char * sql, FWMySQLQR * queryResults, int resultsCount)
{
	return this->Execute(sql, (int)strlen(sql), queryResults, resultsCount);
}

FWMySQLExeRet FWMySQLHelper::Execute(const char * sql, int size, FWMySQLQR * queryResults, int resultsCount)
{
	if (queryResults)
	{
		queryResults->Clear();
	}
	if (size <= 0)
	{
		FW_LOG_WRNING("%s", "size <= 0");
		return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_NO_EXE, 0);
	}
	if (!_mysql)
	{
		unsigned int con_erru = 0;
		if (!this->Connect(&con_erru))
		{
			return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_NO_EXE, con_erru);
		}
	}
	int r = mysql_real_query(_mysql, sql, (unsigned long)size);
	if (r != 0)
	{
		unsigned int erru = mysql_errno(_mysql);
		const char * errs = mysql_error(_mysql);
		if (erru == CR_SERVER_GONE_ERROR)
		{
			unsigned int con_erru = 0;
			if (!this->Connect(&con_erru))
			{
				return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_NO_EXE, con_erru);
			}
			r = mysql_real_query(_mysql, sql, (unsigned long)size);
		}
		else if (erru == CR_COMMANDS_OUT_OF_SYNC)
		{
			FW_LOG_ERROR("%s%s%u%s%s", "mysql_real_query", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
			return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_NO_EXE, erru);
		}
		else if (erru == CR_SERVER_LOST)
		{
			FW_LOG_ERROR("%s%s%u%s%s", "mysql_real_query", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
			this->Disconnect();
			return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_UNKNOWN, erru);
		}
		else if (erru == CR_NET_PACKET_TOO_LARGE || erru == CR_OUT_OF_MEMORY || erru == CR_MALFORMED_PACKET)
		{
			FW_LOG_ERROR("%s%s%u%s%s", "mysql_real_query", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
			return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_UNKNOWN, erru);
		}
		else
		{
			FW_LOG_ERROR("%s%s%u%s%s", "mysql_real_query", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
			return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_ERROR, erru);
		}
	}
	if (r != 0)
	{
		unsigned int erru = mysql_errno(_mysql);
		const char * errs = mysql_error(_mysql);
		FW_LOG_ERROR("%s%s%u%s%s", "mysql_real_query try again", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
		if (erru == CR_SERVER_GONE_ERROR)
		{
			this->Disconnect();
			return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_NO_EXE, erru);
		}
		else if (erru == CR_COMMANDS_OUT_OF_SYNC)
		{
			return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_NO_EXE, erru);
		}
		else if (erru == CR_SERVER_LOST)
		{
			this->Disconnect();
			return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_UNKNOWN, erru);
		}
		else if (erru == CR_NET_PACKET_TOO_LARGE || erru == CR_OUT_OF_MEMORY || erru == CR_MALFORMED_PACKET)
		{
			return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_UNKNOWN, erru);
		}
		else
		{
			return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_ERROR, erru);
		}
	}
	MYSQL_RES * result = nullptr;
	bool disconnected = false;
	for (int index = 0; index < INT_MAX; index++)
	{
		result = mysql_store_result(_mysql);
		if (result)
		{
			if (queryResults && index < resultsCount)
			{
				(queryResults + index)->_affected_rows = mysql_affected_rows(_mysql);
				(queryResults + index)->_insert_id = mysql_insert_id(_mysql);
				std::vector<FWMySQLQRRow>* results = (std::vector<FWMySQLQRRow>*)((queryResults + index)->_data);
				unsigned int num_rows = (unsigned int)mysql_num_rows(result);
				for (unsigned int i = 0; i < num_rows; i++)
				{
					MYSQL_ROW row = mysql_fetch_row(result);
					if (row)
					{
						FWMySQLQRRow rowObj;
						unsigned int num_fields = mysql_num_fields(result);
						unsigned long * lengths = mysql_fetch_lengths(result);
						for (unsigned int j = 0; j < num_fields; j++)
						{
							MYSQL_FIELD * field = mysql_fetch_field_direct(result, j);
							(*((std::map<std::string, std::string>*)rowObj._rowData))[std::string(field->name, field->name_length)] = std::string(row[j], lengths[j]);
						}
						results->push_back(std::move(rowObj));
					}
					else
					{
						unsigned int erru = mysql_errno(_mysql);
						const char * errs = mysql_error(_mysql);
						FW_LOG_ERROR("%s%s%u%s%s", "mysql_fetch_row", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
						if (erru == CR_SERVER_LOST)
						{
							disconnected = true;
							SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_FAILED, erru);
						}
						else if (erru == CR_COMMANDS_OUT_OF_SYNC || erru == CR_NET_PACKET_TOO_LARGE || erru == CR_OUT_OF_MEMORY || erru == CR_FETCH_CANCELED)
						{
							SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_FAILED, erru);
						}
						else
						{
							SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_ERROR, erru);
						}
						break;
					}
				}
			}
			mysql_free_result(result);
		}
		else
		{
			if (mysql_field_count(_mysql) == 0)
			{
				my_ulonglong num_rows = mysql_affected_rows(_mysql);
				if (queryResults && index < resultsCount)
				{
					(queryResults + index)->_affected_rows = num_rows;
					(queryResults + index)->_insert_id = mysql_insert_id(_mysql);
				}
				if (num_rows == (my_ulonglong)~0)
				{
					unsigned int erru = mysql_errno(_mysql);
					const char * errs = mysql_error(_mysql);
					FW_LOG_ERROR("%s%s%u%s%s", "mysql_store_result", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
					if (erru == CR_SERVER_GONE_ERROR || erru == CR_SERVER_LOST)
					{
						disconnected = true;
						SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_FAILED, erru);
					}
					else if (erru == CR_COMMANDS_OUT_OF_SYNC || erru == CR_NET_PACKET_TOO_LARGE || erru == CR_OUT_OF_MEMORY || erru == CR_MALFORMED_PACKET)
					{
						SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_FAILED, erru);
					}
					else
					{
						SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_ERROR, erru);
					}
				}
			}
			else
			{
				unsigned int erru = mysql_errno(_mysql);
				const char * errs = mysql_error(_mysql);
				FW_LOG_ERROR("%s%s%u%s%s", "mysql_store_result", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
				if (erru == CR_SERVER_GONE_ERROR || erru == CR_SERVER_LOST)
				{
					disconnected = true;
					SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_FAILED, erru);
				}
				else if (erru == CR_COMMANDS_OUT_OF_SYNC || erru == CR_NET_PACKET_TOO_LARGE || erru == CR_OUT_OF_MEMORY || erru == CR_MALFORMED_PACKET)
				{
					SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_FAILED, erru);
				}
				else
				{
					SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_ERROR, erru);
				}
			}
		}
TRY_AGAIN_NEXT:
		int r = mysql_next_result(_mysql);
		if (r == -1)
		{
			break;
		}
		else if (r > 0)
		{
			index++;
			unsigned int erru = mysql_errno(_mysql);
			const char * errs = mysql_error(_mysql);
			FW_LOG_ERROR("%s%s%u%s%s", "mysql_next_result", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
			if (erru == CR_SERVER_GONE_ERROR || erru == CR_SERVER_LOST)
			{
				disconnected = true;
				SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_FAILED, erru);
			}
			else if (erru == CR_COMMANDS_OUT_OF_SYNC || erru == CR_NET_PACKET_TOO_LARGE || erru == CR_OUT_OF_MEMORY || erru == CR_MALFORMED_PACKET)
			{
				SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_FAILED, erru);
			}
			else
			{
				SETMYSQLQRTYPE(queryResults, index, FWMySQLQR::MSQL_QR_ERROR, erru);
			}
			goto TRY_AGAIN_NEXT;
		}
	}
	if (disconnected)
	{
		this->Disconnect();
	}
	return FWMySQLExeRet(FWMySQLExeRet::MSQL_EXE_COMPLETED, 0);
}

FWData FWMySQLHelper::EscapeString(const char * from, unsigned long length)
{
	FWData ret;
	if (!_mysql)
	{
		return ret;
	}
	if (length == 0)
	{
		return ret;
	}
	char * to = (char*)FW_MALLOC(length * 2 + 1);
	unsigned long r = mysql_real_escape_string(_mysql, to, from, length);
	if (r == 0 || r == (my_ulonglong)~0)
	{
		unsigned int erru = mysql_errno(_mysql);
		const char * errs = mysql_error(_mysql);
		FW_LOG_ERROR("%s%s%u%s%s", "mysql_real_escape_string", "  ß∞‹£¨¥ÌŒÛ¬Î£∫", erru, "£¨¥ÌŒÛ–≈œ¢£∫", (errs ? errs : ""));
		FW_FREE(to);
	}
	else
	{
		ret.SetIn(to, (int)r);
	}
	return ret;
}


//////////////////////////////////////////////////////////////////////////


FWMySQLExeRet::FWMySQLExeRet(ExeRetType s, unsigned int e)
	:_state(s)
	, _mysql_errno_value(e)
{

}

FWMySQLExeRet::~FWMySQLExeRet()
{

}

bool FWMySQLExeRet::operator==(const bool & b) const
{
	return (_state == MSQL_EXE_COMPLETED) == b;
}

bool FWMySQLExeRet::operator!=(const bool & b) const
{
	return (_state == MSQL_EXE_COMPLETED) != b;
}

bool FWMySQLExeRet::operator!() const
{
	return !(_state == MSQL_EXE_COMPLETED);
}

FWMySQLExeRet::operator bool() const
{
	return _state == MSQL_EXE_COMPLETED;
}

bool FWMySQLExeRet::operator==(const ExeRetType & i) const
{
	return _state == i;
}

bool FWMySQLExeRet::operator!=(const ExeRetType & i) const
{
	return _state != i;
}

FWMySQLExeRet::operator ExeRetType() const
{
	return _state;
}

unsigned int FWMySQLExeRet::getMySQLErrno() const
{
	return _mysql_errno_value;
}


//////////////////////////////////////////////////////////////////////////


FWMySQLQR::FWMySQLQR()
	:_qrrt(MSQL_QR_COMPLETED)
	, _mysql_errno_value(0)
	, _affected_rows(0)
	, _insert_id(0)
{
	_data = new std::vector<FWMySQLQRRow>();
}

FWMySQLQR::~FWMySQLQR()
{
	delete (std::vector<FWMySQLQRRow>*)_data;
}

bool FWMySQLQR::operator==(const bool & b) const
{
	return (_qrrt == MSQL_QR_COMPLETED) == b;
}

bool FWMySQLQR::operator!=(const bool & b) const
{
	return (_qrrt == MSQL_QR_COMPLETED) != b;
}

bool FWMySQLQR::operator!() const
{
	return !(_qrrt == MSQL_QR_COMPLETED);
}

FWMySQLQR::operator bool() const
{
	return _qrrt == MSQL_QR_COMPLETED;
}

bool FWMySQLQR::operator==(const QRRetType & i) const
{
	return _qrrt == i;
}

bool FWMySQLQR::operator!=(const QRRetType & i) const
{
	return _qrrt != i;
}

FWMySQLQR::operator QRRetType() const
{
	return _qrrt;
}

unsigned int FWMySQLQR::getMySQLErrno() const
{
	return _mysql_errno_value;
}

size_t FWMySQLQR::Size() const
{
	return ((std::vector<FWMySQLQRRow>*)_data)->size();
}

const FWMySQLQRRow * FWMySQLQR::GetRow(size_t index) const
{
	if (index >= ((std::vector<FWMySQLQRRow>*)_data)->size())
	{
		FW_LOG_ERROR("%s", "index >= _data->size()");
		return nullptr;
	}
	return &((*((std::vector<FWMySQLQRRow>*)_data))[index]);
}

void FWMySQLQR::Foreach(bool(*callback)(const FWMySQLQRRow *)) const
{
	if (!callback)
	{
		return;
	}
	for (std::vector<FWMySQLQRRow>::iterator it = ((std::vector<FWMySQLQRRow>*)_data)->begin(); it != ((std::vector<FWMySQLQRRow>*)_data)->end(); it++)
	{
		if (!(*callback)(&(*it)))
		{
			break;
		}
	}
}

unsigned long long FWMySQLQR::GetAffectedRows() const
{
	return _affected_rows;
}

unsigned long long FWMySQLQR::GetInsertID() const
{
	return _insert_id;
}

void FWMySQLQR::Clear()
{
	_qrrt = MSQL_QR_COMPLETED;
	_mysql_errno_value = 0;
	_affected_rows = 0;
	_insert_id = 0;
	((std::vector<FWMySQLQRRow>*)_data)->clear();
}


//////////////////////////////////////////////////////////////////////////


FWMySQLQRRow::FWMySQLQRRow()
{
	_rowData = new std::map<std::string, std::string>();
}

FWMySQLQRRow::FWMySQLQRRow(const FWMySQLQRRow & other)
{
	_rowData = new std::map<std::string, std::string>();
	std::map<std::string, std::string> * od = (std::map<std::string, std::string>*)other._rowData;
	std::map<std::string, std::string> * td = (std::map<std::string, std::string>*)_rowData;
	td->insert(od->begin(), od->end());
}

FWMySQLQRRow& FWMySQLQRRow::operator=(const FWMySQLQRRow & other)
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

FWMySQLQRRow::FWMySQLQRRow(FWMySQLQRRow && other)
{
	_rowData = other._rowData;
	other._rowData = nullptr;
}

FWMySQLQRRow& FWMySQLQRRow::operator=(FWMySQLQRRow && other)
{
	if (_rowData)
	{
		delete (std::map<std::string, std::string>*)_rowData;
	}
	_rowData = other._rowData;
	other._rowData = nullptr;
	return *this;
}

FWMySQLQRRow::~FWMySQLQRRow()
{
	if (_rowData)
	{
		delete (std::map<std::string, std::string>*)_rowData;
	}
}

const char * FWMySQLQRRow::GetColumnValue(const char * name, int * out_size /*= nullptr*/) const
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
	if (out_size)
	{
		*out_size = (int)it->second.size();
	}
	return it->second.c_str();
}

void FWMySQLQRRow::Foreach(bool(*callback)(const char*, const char*, int)) const
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
		if (!(*callback)(it->first.c_str(), it->second.c_str(), (int)it->second.size()))
		{
			break;
		}
	}
}



FW_NS_END


////MySQL≤‚ ‘
//const int MYSQLQRSIZE = 1;
//FWMySQLQR mySQLQR[MYSQLQRSIZE];
//for (int i = 0; i < MYSQLQRSIZE; i++)
//{
//	mySQLQR[i].Clear();
//}
//FWMySQLExeRet mySQLExeRet = mysqlHelper->Execute("SELECT * FROM `account_info` LIMIT 1", mySQLQR, MYSQLQRSIZE);
//switch ((FWMySQLExeRet::ExeRetType)mySQLExeRet)
//{
//case FWMySQLExeRet::MSQL_EXE_COMPLETED:
//{
//	for (int i = 0; i < MYSQLQRSIZE; i++)
//	{
//		FW_PRINT("%d--{", i);
//		switch ((FWMySQLQR::QRRetType)mySQLQR[i])
//		{
//		case FWMySQLQR::MSQL_QR_COMPLETED:
//		{
//			FW_PRINT("affected_rows = %llu", mySQLQR[i].GetAffectedRows());
//			FW_PRINT("insert_id = %llu", mySQLQR[i].GetInsertID());
//			for (size_t j = 0; j < mySQLQR[i].Size(); j++)
//			{
//				const FWMySQLQRRow * qrr = mySQLQR[i].GetRow(j);
//				qrr->Foreach([](const char * name, const char * value, int valueSize)->bool {
//					FW_PRINT_NOT_AUTO_NEWLINES("%s = %s ,", name, value);
//					return true;
//				});
//				FW_PRINT(" ");
//			}
//		}
//			break;
//		case FWMySQLQR::MSQL_QR_FAILED:
//		{
//			FW_PRINT("%s%u", "ªÒ»°Ω·π˚ ± ß∞‹£¨¥ÌŒÛ¬Î£∫", mySQLQR[i].getMySQLErrno());
//		}
//			break;
//		case FWMySQLQR::MSQL_QR_ERROR:
//		{
//			FW_PRINT("%s%u", "ªÒ»°Ω·π˚ ±≥ˆ¥Ì£¨¥ÌŒÛ¬Î£∫", mySQLQR[i].getMySQLErrno());
//		}
//			break;
//		default:
//			break;
//		}
//		FW_PRINT("%d--}", i);
//	}
//}
//	break;
//case FWMySQLExeRet::MSQL_EXE_NO_EXE:
//{
//	FW_PRINT("%s", "SQL√ª”–÷¥––");
//}
//	break;
//case FWMySQLExeRet::MSQL_EXE_ERROR:
//{
//	FW_PRINT("%s", "SQL÷¥––¥ÌŒÛ");
//}
//	break;
//case FWMySQLExeRet::MSQL_EXE_UNKNOWN:
//{
//	FW_PRINT("%s", "Œﬁ∑®»∑∂®SQL «∑Ò÷¥––");
//}
//	break;
//default:
//	break;
//}