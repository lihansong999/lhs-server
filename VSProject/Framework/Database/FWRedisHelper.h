#ifndef __FRAMEWORK_REDISHELPER_H__
#define __FRAMEWORK_REDISHELPER_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#if defined(__cplusplus)
extern "C" {
#endif
#pragma warning(push)
#pragma warning(disable:4200)
#pragma warning(disable:4244)
#include "../ThirdParty/hiredis/hiredis-1.0.0/hiredis.h"
#pragma warning(pop)
#include "../ThirdParty/hiredis/hiredis-1.0.0/win32.h"
#if defined(__cplusplus)
}
#endif
#include "../Common/FWString.h"

FW_NS_BEGIN


class FWRedisCR;
class FWRedisCmdRet;
/*
Redis��������
ʹ������ģʽ
���̰߳�ȫ��
�ɼ̳������๦��
*/
class FW_DLL FWRedisHelper
{
public:
	FWRedisHelper();
	~FWRedisHelper();

	/*
	��ʼ�����ڵ��ñ�����������֮ǰ���ٵ���һ��
	��ε���Connectʱ�����ظ�Init��������Ҫ�޸ĳ�ʼ��ֵ
	Init�ڲ������Disconnect��������Ѿ��������������̶Ͽ�
	host��Redis��������ַ
	port��Redis�������˿�
	passwd��Redis���������룬nullptr��""����ʾ��������
	selectIndex��Redis�������ֵ��±꣬Ĭ��0
	connectTimeOut������Redis�������ĳ�ʱʱ�䣬��0Ϊʹ��Ĭ��ֵ
	rwTimeOut������Redis���������׽��ֶ�д��ʱʱ�䣬��0Ϊʹ��Ĭ��ֵ
	*/
	void Init(const char * host, int port, const char * password, int selectIndex, long connectTimeOut, long rwTimeOut);

	/*
	����Redis������
	�����ʼ��ʱpassword������Ч�����Ӻ󽫻��Զ�����AUTH����
	�����ʼ��ʱselectIndex!=0�����Ӻ󽫻��Զ�����SELECT����
	����ֵ��
		true�ɹ�
		falseʧ��
	*/
	bool Connect();

	/*
	�Ͽ���Redis������������
	*/
	void Disconnect();

	/*
	�����Redis������������״̬
	����ֵ��
		true����������
		false����Ӧ
	*/
	bool Ping();

	/*
	�л�RESPЭ�飬2��3����ģ����ʱֻ֧��2������ģ����ʹ�õ�hiredis��֧��3�������жԱ�ģ�������չ��
	����ֵ��
		true�ɹ�
		falseʧ��
	*/
	bool Hello(int version);

	/*
	ִ��Redis����
	�����δ����Redis������Command�ڲ������Զ�����һ�����ӣ���ǰ����Init��������
	���ض���
		==true��==FWRedisCmdRet::REDIS_CMD_COMPLETED���ж�������ѡһ���ɣ�
			�ɹ���ע�⣺����ִ�гɹ�Ҳ������������FWRedisCR��û�д��󣬾��������FWRedisCR::QRReplyTypeö��
		==false��!=FWRedisCmdRet::REDIS_CMD_COMPLETED���ж�������ѡһ���ɣ�
			ʧ�ܣ�ʧ��ʱFWRedisCR��Ч��ע�⣺����ʧ��Ҳ������Redis������û�гɹ�ִ����䣬��������ɲ鿴FWRedisCmdRet::CmdRetTypeö�ٵ�ע��
	*/
	FWRedisCmdRet __cdecl Command(FWRedisCR * cr, const char * format, ...);

protected:
	void _foreachReply(FWRedisCR * qr, redisReply * reply);

protected:
	redisContext *	_context;
	char			_host[256];
	int				_port;
	char			_password[128];
	int				_selectIndex;
	long			_connectTimeOut;
	long			_rwTimeOut;
};


//////////////////////////////////////////////////////////////////////////


/*
FWRedisHelper����ֵ
*/
class FW_DLL FWRedisCmdRet
{
	friend class FWRedisHelper;
public:
	enum CmdRetType
	{
		REDIS_CMD_COMPLETED = 0,	//���ִ�У������ɲ鿴�������FWRedisCR��
		REDIS_CMD_NO_EXE = -1,		//û��ִ�У�������Ϊnullptr�������ʽ��ʧ�ܡ�����������Redis������ʧ�ܣ�
		REDIS_CMD_UNKNOWN = -2,		//��ȷ���Ƿ���ִ�У���Redis������ͨ����;�������󡢽����̫���ڴ治�㣩
	};
private:
	FWRedisCmdRet(CmdRetType s, int e);
public:
	~FWRedisCmdRet();

	/*
	��bool�ж��Ƿ�ΪFWRedisCmdRet::REDIS_CMD_COMPLETED
	*/
	bool operator==(const bool & b) const;
	bool operator!=(const bool & b) const;
	bool operator!() const;
	operator bool() const;

	/*
	��ö���ж�
	*/
	bool operator==(const CmdRetType & i) const;
	bool operator!=(const CmdRetType & i) const;
	operator CmdRetType() const;

	/*
	�鿴�����Ĵ�����
	*/
	int getContextError() const;

private:
	CmdRetType		_state;
	int				_contextError;
};


//////////////////////////////////////////////////////////////////////////


/*
FWRedisHelper������
*/
class FW_DLL FWRedisCR
{
	friend class FWRedisHelper;
public:
	enum CRReplyType
	{
		//RESP2
		REDIS_CR_TYPE_STRING = REDIS_REPLY_STRING,
		REDIS_CR_TYPE_ARRAY = REDIS_REPLY_ARRAY,
		REDIS_CR_TYPE_INTEGER = REDIS_REPLY_INTEGER,
		REDIS_CR_TYPE_NIL = REDIS_REPLY_NIL,
		REDIS_CR_TYPE_STATUS = REDIS_REPLY_STATUS,
		REDIS_CR_TYPE_ERROR = REDIS_REPLY_ERROR,

		//RESP3
		REDIS_CR_TYPE_DOUBLE = REDIS_REPLY_DOUBLE,
		REDIS_CR_TYPE_BOOL = REDIS_REPLY_BOOL,
		REDIS_CR_TYPE_MAP = REDIS_REPLY_MAP,
		REDIS_CR_TYPE_SET = REDIS_REPLY_SET,
		REDIS_CR_TYPE_ATTR = REDIS_REPLY_ATTR,
		REDIS_CR_TYPE_PUSH = REDIS_REPLY_PUSH,
		REDIS_CR_TYPE_BIGNUM = REDIS_REPLY_BIGNUM,
		REDIS_CR_TYPE_VERB = REDIS_REPLY_VERB,
	};

public:
	FWRedisCR();
	FWRedisCR(const FWRedisCR & other) = delete;
	FWRedisCR& operator=(const FWRedisCR & other) = delete;
	FWRedisCR(FWRedisCR && other) = delete;
	FWRedisCR& operator=(FWRedisCR && other) = delete;
	~FWRedisCR();

	/*
	�õ�������
	*/
	CRReplyType GetReplyType() const;

	/*
	ȡ���ַ������ʹ𸴽��
	*/
	const char * GetString() const;

	/*
	ȡ���ַ������ʹ𸴽�����ַ�������
	*/
	int GetStringLength() const;

	/*
	ȡ���������ʹ𸴽��
	*/
	const FWRedisCR * GetArray() const;

	/*
	ȡ���������ʹ𸴽��������Ԫ�ظ���
	*/
	int GetArrayCount() const;

	/*
	�����±�ȡ���������ʹ𸴽���Ķ�ӦԪ��
	*/
	const FWRedisCR * GetArrayElement(int index) const;

	/*
	ȡ���������ʹ𸴽��
	*/
	long long GetInteger() const;

	/*
	ȡ��״̬���ʹ𸴽��
	*/
	const char * GetStatus() const;

	/*
	ȡ�ô������ʹ𸴽��
	*/
	const char * GetError() const;

	/*
	��״̬���ʹ𸴽���Ƚ�
	*/
	bool CompareStatus(const char * status) const;

	/*
	��ӡ
	*/
	void Dump(int depth = 0);

	/*
	��գ����ٴθ��ã�
	*/
	void Clear();

private:
	CRReplyType		_qrrt;
	long long		_integer;
	char		*	_string;
	int				_sLen;
	FWRedisCR   *	_crArray;
	int				_crArrayCount;
};


//////////////////////////////////////////////////////////////////////////


/*
Redis��
ע�⣺
	����ԭ��Ϊ����һ����Ϊ���캯������lockName��Key��Ϊ��ʶ��Key��ʱΪmsTTL��
	��ͬ��Redis��̭�����п����ڵ���UnLock֮ǰ��ɾ��������
	���Ա���������������������԰�ȫ��������ʹ�á�
*/
class FW_DLL FWRedisLock
{
public:
	FWRedisLock(FWRedisHelper * redisHelper, const char * lockName, int msTTL = 10000, int msRetriesInvl = 100, long long msWaitTimeOut = LLONG_MAX);
	FWRedisLock(const FWRedisLock & other) = delete;
	FWRedisLock& operator=(const FWRedisLock & other) = delete;
	FWRedisLock(FWRedisLock && other) = delete;
	FWRedisLock& operator=(FWRedisLock && other) = delete;
	~FWRedisLock();

	/*
	����
	����ֵ��0Ϊ�ɹ���-1Ϊ�ȴ���ʱ��-2��Redis�Ͽ����ӻ�Redisִ�д���
	*/
	int Lock();

	/*
	����
	����ֵ��0Ϊ�ɹ���-2��Redis�Ͽ����ӻ�Redisִ�д���
	*/
	int UnLock();

private:
	FWRedisHelper * _redisHelper;
	FWString		_lockName;
	const char *	_unLockScript;
	const int		_randValue;
	const int		_msTTL;
	const int		_msRetriesInvl;
	const long long _msWaitTimeOut;
};


FW_NS_END


#endif //!__FRAMEWORK_REDISHELPER_H__