#ifndef __FRAMEWORK_SQLITEHELPER_H__
#define __FRAMEWORK_SQLITEHELPER_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "../ThirdParty/sqlite-amalgamation-3240000/sqlite3.h"

FW_NS_BEGIN


class FWSQLiteQR;
/*
SQLite帮助工具
非线程安全的
可继承扩更多功能
*/
class FW_DLL FWSQLiteHelper
{
public:
	FWSQLiteHelper();
	~FWSQLiteHelper();

	/*
	打开数据库
	force为true的时候，如果读取不到数据库文件将会强制创建一个新的数据库文件
	*/
	bool Open(const char * path, bool force = false);

	/*
	关闭数据库
	*/
	void Close();

	/*
	执行SQL
	不支持二进制发送
	返回值：
		true执行成功
		false执行失败，失败时queryResults无效
	*/
	bool Execute(const char * sql, FWSQLiteQR * queryResults);

protected:
	sqlite3 * _sqlite;
};


//////////////////////////////////////////////////////////////////////////


class FWSQLiteQRRow;
/*
SQLite查询结果对象（全）
*/
class FW_DLL FWSQLiteQR
{
	friend int _Sqlite_Exec_Callback(void*, int, char**, char**);
public:
	FWSQLiteQR();
	FWSQLiteQR(const FWSQLiteQR & other) = delete;
	FWSQLiteQR& operator=(const FWSQLiteQR & other) = delete;
	FWSQLiteQR(FWSQLiteQR && other) = delete;
	FWSQLiteQR& operator=(FWSQLiteQR && other) = delete;
	~FWSQLiteQR();

	/*
	共有几条数据
	*/
	size_t Size() const;
	
	/*
	通过下标查询得到一条数据
	*/
	const FWSQLiteQRRow * GetRow(unsigned int index) const;
	
	/*
	遍历
	回调函数如果返回false遍历将马上停止
	*/
	void Foreach(bool(*callback)(const FWSQLiteQRRow *)) const;

	/*
	清空（可再次复用）
	*/
	void Clear();

private:
	void * _data;
};


//////////////////////////////////////////////////////////////////////////


/*
SQLite查询结果对象（一条）
*/
class FW_DLL FWSQLiteQRRow
{
	friend int _Sqlite_Exec_Callback(void*, int, char**, char**);
public:
	FWSQLiteQRRow();
	FWSQLiteQRRow(const FWSQLiteQRRow & other);
	FWSQLiteQRRow& operator=(const FWSQLiteQRRow & other);
	FWSQLiteQRRow(FWSQLiteQRRow && other);
	FWSQLiteQRRow& operator=(FWSQLiteQRRow && other);
	~FWSQLiteQRRow();

	/*
	通过列名查询得到对应列值
	不支持二进制获取
	*/
	const char * GetColumnValue(const char * name) const;

	/*
	遍历
	回调函数如果返回false遍历将马上停止
	*/
	void Foreach(bool(*callback)(const char*, const char*)) const;

private:
	void * _rowData;
};


FW_NS_END


#endif //!__FRAMEWORK_SQLITEHELPER_H__