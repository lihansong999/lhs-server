#ifndef __FRAMEWORK_SQLITEHELPER_H__
#define __FRAMEWORK_SQLITEHELPER_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "../ThirdParty/sqlite-amalgamation-3240000/sqlite3.h"

FW_NS_BEGIN


class FWSQLiteQR;
/*
SQLite��������
���̰߳�ȫ��
�ɼ̳������๦��
*/
class FW_DLL FWSQLiteHelper
{
public:
	FWSQLiteHelper();
	~FWSQLiteHelper();

	/*
	�����ݿ�
	forceΪtrue��ʱ�������ȡ�������ݿ��ļ�����ǿ�ƴ���һ���µ����ݿ��ļ�
	*/
	bool Open(const char * path, bool force = false);

	/*
	�ر����ݿ�
	*/
	void Close();

	/*
	ִ��SQL
	��֧�ֶ����Ʒ���
	����ֵ��
		trueִ�гɹ�
		falseִ��ʧ�ܣ�ʧ��ʱqueryResults��Ч
	*/
	bool Execute(const char * sql, FWSQLiteQR * queryResults);

protected:
	sqlite3 * _sqlite;
};


//////////////////////////////////////////////////////////////////////////


class FWSQLiteQRRow;
/*
SQLite��ѯ�������ȫ��
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
	���м�������
	*/
	size_t Size() const;
	
	/*
	ͨ���±��ѯ�õ�һ������
	*/
	const FWSQLiteQRRow * GetRow(unsigned int index) const;
	
	/*
	����
	�ص������������false����������ֹͣ
	*/
	void Foreach(bool(*callback)(const FWSQLiteQRRow *)) const;

	/*
	��գ����ٴθ��ã�
	*/
	void Clear();

private:
	void * _data;
};


//////////////////////////////////////////////////////////////////////////


/*
SQLite��ѯ�������һ����
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
	ͨ��������ѯ�õ���Ӧ��ֵ
	��֧�ֶ����ƻ�ȡ
	*/
	const char * GetColumnValue(const char * name) const;

	/*
	����
	�ص������������false����������ֹͣ
	*/
	void Foreach(bool(*callback)(const char*, const char*)) const;

private:
	void * _rowData;
};


FW_NS_END


#endif //!__FRAMEWORK_SQLITEHELPER_H__