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
MySQL��������
���̰߳�ȫ��
�ɼ̳������๦��
*/
class FW_DLL FWMySQLHelper
{
public:
	FWMySQLHelper();
	~FWMySQLHelper();
	
	/*
	��ʼ�����ڵ��ñ�����������֮ǰ���ٵ���һ��
	��ε���Connectʱ�����ظ�Init��������Ҫ�޸ĳ�ʼ��ֵ
	Init�ڲ������Disconnect��������Ѿ��������������̶Ͽ�
	host��MySQL��������ַ
	username��MySQL�������û���
	passwd��MySQL����������
	database������MySQL�����������ݿ���
	port��MySQL�������˿�
	flag������MySQL������ʱ�Ŀͻ��˱�־��Ĭ�ϴ�0����������ʲôֵ��Init�ж����Զ����϶����ִ�й���
	charSet��MySQL�ͻ����ַ�������""���Զ�ʹ��utf8mb4��Ĭ�ϴ�""
	connectTimeOut������MySQL�������ĳ�ʱʱ�䣬��0Ϊʹ��Ĭ��ֵ
	readTimeOut��MySQL����ʱʱ�䣬��0Ϊʹ��Ĭ��ֵ
	writeTimeOut��MySQLд��ʱʱ�䣬��0Ϊʹ��Ĭ��ֵ
	*/
	void Init(const char * host, const char * username, const char * passwd, const char * database, unsigned int port, unsigned long flag, const char * charSet, unsigned int connectTimeOut, unsigned int readTimeOut, unsigned int writeTimeOut);

	/*
	����MySQL������
	����ֵ��
		true�ɹ�
		falseʧ��
	*/
	bool Connect(unsigned int * mysqlErrorCode = nullptr);
	
	/*
	�Ͽ���MySQL������������
	*/
	void Disconnect();
	
	/*
	�����MySQL������������״̬
	����ֵ��
	true����������
	false������
	*/
	bool Ping();

	/*
	ִ��SQL
	֧�ֶ����ִ��
	��֧�ֶ����Ʒ���
	�����δ����MySQL�������������ѶϿ�ʱExecute�ڲ������Զ�����һ�����ӣ���ǰ����Init��������
	���ض���
		==true��==FWMySQLExeRet::MSQL_EXE_COMPLETED���ж�������ѡһ���ɣ�
			�ɹ���ע�⣺����ִ�гɹ�Ҳ������������FWMySQLQR��û�д��󣬾��������FWMySQLQR::QRRetTypeö�ٵ�ע��
		==false��!=FWMySQLExeRet::MSQL_EXE_COMPLETED���ж�������ѡһ���ɣ�
			ʧ�ܣ�ʧ��ʱqueryResults��Ч��ע�⣺����ʧ��Ҳ������MySQL������û�гɹ�ִ����䣬��������ɲ鿴FWMySQLExeRet::ExeRetTypeö�ٵ�ע��
	*/
	FWMySQLExeRet Execute(const char * sql, FWMySQLQR * queryResults, int resultsCount);
	
	/*
	ִ��SQL
	֧�ֶ����ִ��
	֧�ֶ����Ʒ���
	�����δ����MySQL�������������ѶϿ�ʱExecute�ڲ������Զ�����һ�����ӣ���ǰ����Init��������
	���ض���
		==true��==FWMySQLExeRet::MSQL_EXE_COMPLETED���ж�������ѡһ���ɣ�
			�ɹ���ע�⣺����ִ�гɹ�Ҳ������������FWMySQLQR��û�д��󣬾��������FWMySQLQR::QRRetTypeö�ٵ�ע��
		==false��!=FWMySQLExeRet::MSQL_EXE_COMPLETED���ж�������ѡһ���ɣ�
			ʧ�ܣ�ʧ��ʱqueryResults��Ч��ע�⣺����ʧ��Ҳ������MySQL������û�гɹ�ִ����䣬��������ɲ鿴FWMySQLExeRet::ExeRetTypeö�ٵ�ע��
	*/
	FWMySQLExeRet Execute(const char * sql, int size, FWMySQLQR * queryResults, int resultsCount);


	/*
	ת��SQL�����ַ���
	�����ڷ�ֹSQLע���Լ������Ʋ���ת��
	���ض���
		.IsNull()==true
			ʧ�ܣ�����������»�ת��ʧ�ܣ�1.�������� 2.��δ����MySQL������ 3.������NO_BACKSLASH_ESCAPESģʽ
		.IsNull()==false
			�ɹ���.GetPointer()������ת�����\0��β���ַ���ָ�룬.GetSize()������ת����ַ����ĳ��ȣ����Ȳ�������β��\0��
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
FWMySQLHelper����ֵ
*/
class FW_DLL FWMySQLExeRet
{
	friend class FWMySQLHelper;
public:
	enum ExeRetType
	{
		MSQL_EXE_COMPLETED	= 0,	//���ִ�У������ɲ鿴�������FWMySQLQR��
		MSQL_EXE_NO_EXE		= -1,	//û��ִ�У�size<=0������ʧ�ܡ�����������˳�����
		MSQL_EXE_ERROR		= -2,	//ִ������������getMySQLErrno�鿴��������룩
		MSQL_EXE_UNKNOWN	= -3,	//��ȷ���Ƿ���ִ�У���MySQL������ͨ����;�������󡢽����̫���ڴ治�㣩
	};
private:
	FWMySQLExeRet(ExeRetType s, unsigned int e);
public:
	~FWMySQLExeRet();

	/*
	��bool�ж��Ƿ�ΪFWMySQLExeRet::MSQL_EXE_COMPLETED
	*/
	bool operator==(const bool & b) const;
	bool operator!=(const bool & b) const;
	bool operator!() const;
	operator bool() const;

	/*
	��ö���ж�
	*/
	bool operator==(const ExeRetType & i) const;
	bool operator!=(const ExeRetType & i) const;
	operator ExeRetType() const;

	/*
	�鿴MySQL������
	*/
	unsigned int getMySQLErrno() const;

private:
	ExeRetType		_state;
	unsigned int	_mysql_errno_value;
};


//////////////////////////////////////////////////////////////////////////


class FWMySQLQRRow;
/*
MySQL��ѯ�������ȫ��
*/
class FW_DLL FWMySQLQR
{
	friend FWMySQLExeRet FWMySQLHelper::Execute(const char * sql, int size, FWMySQLQR * queryResults, int resultsCount);
public:
	enum QRRetType
	{
		MSQL_QR_COMPLETED	= 0,		//��ȡ������
		MSQL_QR_FAILED		= -1,		//û�ܻ�ȡ���������MySQL������ͨ����;�������󡢽����̫���ڴ治�㡢����������˳�����
		MSQL_QR_ERROR		= -2,		//�����ȡ�����󣨵���getMySQLErrno�鿴��������룩
	};
public:
	FWMySQLQR();
	FWMySQLQR(const FWMySQLQR & other) = delete;
	FWMySQLQR& operator=(const FWMySQLQR & other) = delete;
	FWMySQLQR(FWMySQLQR && other) = delete;
	FWMySQLQR& operator=(FWMySQLQR && other) = delete;
	~FWMySQLQR();
	
	/*
	��bool�ж��Ƿ�ΪFWMySQLQR::MSQL_QR_COMPLETED
	*/
	bool operator==(const bool & b) const;
	bool operator!=(const bool & b) const;
	bool operator!() const;
	operator bool() const;

	/*
	��ö���ж�
	*/
	bool operator==(const QRRetType & i) const;
	bool operator!=(const QRRetType & i) const;
	operator QRRetType() const;

	/*
	�鿴MySQL������
	*/
	unsigned int getMySQLErrno() const;

	/*
	���ض���
		==true��==MSQL_EXE_COMPLETED���ж�������ѡһ���ɣ�
			�ɹ�
		==false��!=MSQL_EXE_COMPLETED���ж�������ѡһ���ɣ�
			ʧ�ܣ�ע�⣺����ʧ��Ҳ������MySQL������û�гɹ�ִ����䣬��������ɲ鿴FW_MSQL_???�������ע��
	*/

	/*
	���м�������
	*/
	size_t Size() const;

	/*
	ͨ���±��ѯ�õ�һ������
	*/
	const FWMySQLQRRow * GetRow(size_t index) const;

	/*
	����
	�ص������������false����������ֹͣ
	*/
	void Foreach(bool(*callback)(const FWMySQLQRRow *)) const;

	/*
	�õ���Ӱ������������ҵ���������
	*/
	unsigned long long GetAffectedRows() const;

	/*
	�õ�AUTO_INCREMENT
	*/
	unsigned long long GetInsertID() const;

	/*
	��գ���պ���ٴθ��ã�
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
MySQL��ѯ�������һ����
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
	ͨ��������ѯ�õ���Ӧ��ֵ
	֧�ֶ����ƻ�ȡ
	*/
	const char * GetColumnValue(const char * name, int * out_size = nullptr) const;

	/*
	����
	֧�ֶ����ƻ�ȡ
	�ص������������false����������ֹͣ
	*/
	void Foreach(bool(*callback)(const char*, const char*, int)) const;

private:
	void * _rowData;
};



FW_NS_END


#endif //!__FRAMEWORK_MYSQLHELPER_H__