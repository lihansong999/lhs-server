#ifndef __FRAMEWORK_MYSQLHELPER_H__
#define __FRAMEWORK_MYSQLHELPER_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "../Common/FWData.h"
#if defined(_WIN64)
#include "../ThirdParty/MySQL_5_7_30/Win64/include/mysql.h"
#include "../ThirdParty/MySQL_5_7_30/Win64/include/errmsg.h"
#else
#include "../ThirdParty/MySQL_5_7_30/Win32/include/mysql.h"
#include "../ThirdParty/MySQL_5_7_30/Win32/include/errmsg.h"
#endif

FW_NS_BEGIN


class FWMySQLQR;
class FWMySQLExeRet;
/*
MySQL帮助工具
非线程安全的
可继承扩更多功能
*/
class FW_DLL FWMySQLHelper
{
public:
	FWMySQLHelper();
	~FWMySQLHelper();
	
	/*
	初始化，在调用本类其他函数之前至少调用一次
	多次调用Connect时无需重复Init，除非需要修改初始化值
	Init内部会调用Disconnect，这会让已经建立的连接立刻断开
	host：MySQL服务器地址
	username：MySQL服务器用户名
	passwd：MySQL服务器密码
	database：连接MySQL服务器的数据库名
	port：MySQL服务器端口
	flag：连接MySQL服务器时的客户端标志，默认传0，不管设置什么值，Init中都会自动加上多语句执行功能
	charSet：MySQL客户端字符集，传""将自动使用utf8mb4，默认传""
	connectTimeOut：连接MySQL服务器的超时时间，传0为使用默认值
	readTimeOut：MySQL读超时时间，传0为使用默认值
	writeTimeOut：MySQL写超时时间，传0为使用默认值
	*/
	void Init(const char * host, const char * username, const char * passwd, const char * database, unsigned int port, unsigned long flag, const char * charSet, unsigned int connectTimeOut, unsigned int readTimeOut, unsigned int writeTimeOut);

	/*
	连接MySQL服务器
	返回值：
		true成功
		false失败
	*/
	bool Connect(unsigned int * mysqlErrorCode = nullptr);
	
	/*
	断开与MySQL服务器的连接
	*/
	void Disconnect();
	
	/*
	检测与MySQL服务器的连接状态
	返回值：
	true保持连接中
	false无连接
	*/
	bool Ping();

	/*
	执行SQL
	支持多语句执行
	不支持二进制发送
	如果尚未连接MySQL服务器或连接已断开时Execute内部将会自动尝试一次连接，但前提是Init设置无误
	返回对象：
		==true或==FWMySQLExeRet::MSQL_EXE_COMPLETED（判断条件二选一即可）
			成功，注意：就算执行成功也不代表结果对象FWMySQLQR中没有错误，具体情况看FWMySQLQR::QRRetType枚举的注释
		==false或!=FWMySQLExeRet::MSQL_EXE_COMPLETED（判断条件二选一即可）
			失败，失败时queryResults无效，注意：就算失败也不代表MySQL服务器没有成功执行语句，具体情况可查看FWMySQLExeRet::ExeRetType枚举的注释
	*/
	FWMySQLExeRet Execute(const char * sql, FWMySQLQR * queryResults, int resultsCount);
	
	/*
	执行SQL
	支持多语句执行
	支持二进制发送
	如果尚未连接MySQL服务器或连接已断开时Execute内部将会自动尝试一次连接，但前提是Init设置无误
	返回对象：
		==true或==FWMySQLExeRet::MSQL_EXE_COMPLETED（判断条件二选一即可）
			成功，注意：就算执行成功也不代表结果对象FWMySQLQR中没有错误，具体情况看FWMySQLQR::QRRetType枚举的注释
		==false或!=FWMySQLExeRet::MSQL_EXE_COMPLETED（判断条件二选一即可）
			失败，失败时queryResults无效，注意：就算失败也不代表MySQL服务器没有成功执行语句，具体情况可查看FWMySQLExeRet::ExeRetType枚举的注释
	*/
	FWMySQLExeRet Execute(const char * sql, int size, FWMySQLQR * queryResults, int resultsCount);


	/*
	转义SQL参数字符串
	可用于防止SQL注入以及二进制参数转义
	返回对象：
		.IsNull()==true
			失败，在三种情况下会转义失败：1.参数错误 2.尚未连接MySQL服务器 3.开启了NO_BACKSLASH_ESCAPES模式
		.IsNull()==false
			成功，.GetPointer()将返回转义后以\0结尾的字符串指针，.GetSize()将返回转义后字符串的长度（长度不包括结尾的\0）
	*/
	FWData EscapeString(const char * from, unsigned long length);

protected:
	MYSQL		*	_mysql;
	char			_host[256];
	char			_username[64];
	char			_passwd[64];
	char			_database[128];
	char			_charSet[64];
	unsigned int	_connectTimeOut;
	unsigned int	_readTimeOut;
	unsigned int	_writeTimeOut;
	unsigned int	_port;
	unsigned long	_flag;
};


//////////////////////////////////////////////////////////////////////////


/*
FWMySQLHelper返回值
*/
class FW_DLL FWMySQLExeRet
{
	friend class FWMySQLHelper;
public:
	enum ExeRetType
	{
		MSQL_EXE_COMPLETED	= 0,	//完成执行（后续可查看结果对象FWMySQLQR）
		MSQL_EXE_NO_EXE		= -1,	//没有执行（size<=0、连接失败、连接器调用顺序错误）
		MSQL_EXE_ERROR		= -2,	//执行语句出错（调用getMySQLErrno查看具体错误码）
		MSQL_EXE_UNKNOWN	= -3,	//不确定是否已执行（与MySQL服务器通信中途发生错误、结果集太大内存不足）
	};
private:
	FWMySQLExeRet(ExeRetType s, unsigned int e);
public:
	~FWMySQLExeRet();

	/*
	与bool判定是否为FWMySQLExeRet::MSQL_EXE_COMPLETED
	*/
	bool operator==(const bool & b) const;
	bool operator!=(const bool & b) const;
	bool operator!() const;
	operator bool() const;

	/*
	与枚举判定
	*/
	bool operator==(const ExeRetType & i) const;
	bool operator!=(const ExeRetType & i) const;
	operator ExeRetType() const;

	/*
	查看MySQL错误码
	*/
	unsigned int getMySQLErrno() const;

private:
	ExeRetType		_state;
	unsigned int	_mysql_errno_value;
};


//////////////////////////////////////////////////////////////////////////


class FWMySQLQRRow;
/*
MySQL查询结果对象（全）
*/
class FW_DLL FWMySQLQR
{
	friend FWMySQLExeRet FWMySQLHelper::Execute(const char * sql, int size, FWMySQLQR * queryResults, int resultsCount);
public:
	enum QRRetType
	{
		MSQL_QR_COMPLETED	= 0,		//获取结果完成
		MSQL_QR_FAILED		= -1,		//没能获取到结果（与MySQL服务器通信中途发生错误、结果集太大内存不足、连接器调用顺序错误）
		MSQL_QR_ERROR		= -2,		//结果获取到错误（调用getMySQLErrno查看具体错误码）
	};
public:
	FWMySQLQR();
	FWMySQLQR(const FWMySQLQR & other) = delete;
	FWMySQLQR& operator=(const FWMySQLQR & other) = delete;
	FWMySQLQR(FWMySQLQR && other) = delete;
	FWMySQLQR& operator=(FWMySQLQR && other) = delete;
	~FWMySQLQR();
	
	/*
	与bool判定是否为FWMySQLQR::MSQL_QR_COMPLETED
	*/
	bool operator==(const bool & b) const;
	bool operator!=(const bool & b) const;
	bool operator!() const;
	operator bool() const;

	/*
	与枚举判定
	*/
	bool operator==(const QRRetType & i) const;
	bool operator!=(const QRRetType & i) const;
	operator QRRetType() const;

	/*
	查看MySQL错误码
	*/
	unsigned int getMySQLErrno() const;

	/*
	返回对象：
		==true或==MSQL_EXE_COMPLETED（判断条件二选一即可）
			成功
		==false或!=MSQL_EXE_COMPLETED（判断条件二选一即可）
			失败，注意：就算失败也不代表MySQL服务器没有成功执行语句，具体情况可查看FW_MSQL_???返回码的注释
	*/

	/*
	共有几条数据
	*/
	size_t Size() const;

	/*
	通过下标查询得到一条数据
	*/
	const FWMySQLQRRow * GetRow(size_t index) const;

	/*
	遍历
	回调函数如果返回false遍历将马上停止
	*/
	void Foreach(bool(*callback)(const FWMySQLQRRow *)) const;

	/*
	得到受影响的行数量或找到的行数量
	*/
	unsigned long long GetAffectedRows() const;

	/*
	得到AUTO_INCREMENT
	*/
	unsigned long long GetInsertID() const;

	/*
	清空（清空后可再次复用）
	*/
	void Clear();

private:
	QRRetType			_qrrt;
	unsigned int		_mysql_errno_value;
	void			*	_data;
	unsigned long long	_affected_rows;
	unsigned long long	_insert_id;
};


//////////////////////////////////////////////////////////////////////////


/*
MySQL查询结果对象（一条）
*/
class FW_DLL FWMySQLQRRow
{
	friend FWMySQLExeRet FWMySQLHelper::Execute(const char * sql, int size, FWMySQLQR * queryResults, int resultsCount);
public:
	FWMySQLQRRow();
	FWMySQLQRRow(const FWMySQLQRRow & other);
	FWMySQLQRRow& operator=(const FWMySQLQRRow & other);
	FWMySQLQRRow(FWMySQLQRRow && other);
	FWMySQLQRRow& operator=(FWMySQLQRRow && other);
	~FWMySQLQRRow();

	/*
	通过列名查询得到对应列值
	支持二进制获取
	*/
	const char * GetColumnValue(const char * name, int * out_size = nullptr) const;

	/*
	遍历
	支持二进制获取
	回调函数如果返回false遍历将马上停止
	*/
	void Foreach(bool(*callback)(const char*, const char*, int)) const;

private:
	void * _rowData;
};



FW_NS_END


#endif //!__FRAMEWORK_MYSQLHELPER_H__