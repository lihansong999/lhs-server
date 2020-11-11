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
Redis帮助工具
使用阻塞模式
非线程安全的
可继承扩更多功能
*/
class FW_DLL FWRedisHelper
{
public:
	FWRedisHelper();
	~FWRedisHelper();

	/*
	初始化，在调用本类其他函数之前至少调用一次
	多次调用Connect时无需重复Init，除非需要修改初始化值
	Init内部会调用Disconnect，这会让已经建立的连接立刻断开
	host：Redis服务器地址
	port：Redis服务器端口
	passwd：Redis服务器密码，nullptr或""都表示忽略密码
	selectIndex：Redis服务器字典下标，默认0
	connectTimeOut：连接Redis服务器的超时时间，传0为使用默认值
	rwTimeOut：连接Redis服务器的套接字读写超时时间，传0为使用默认值
	*/
	void Init(const char * host, int port, const char * password, int selectIndex, long connectTimeOut, long rwTimeOut);

	/*
	连接Redis服务器
	如果初始化时password参数有效，连接后将会自动发送AUTH命令
	如果初始化时selectIndex!=0，连接后将会自动发送SELECT命令
	返回值：
		true成功
		false失败
	*/
	bool Connect();

	/*
	断开与Redis服务器的连接
	*/
	void Disconnect();

	/*
	检测与Redis服务器的连接状态
	返回值：
		true保持连接中
		false无响应
	*/
	bool Ping();

	/*
	切换RESP协议，2或3（本模块暂时只支持2，但本模块所使用的hiredis已支持3，可自行对本模块进行扩展）
	返回值：
		true成功
		false失败
	*/
	bool Hello(int version);

	/*
	执行Redis命令
	如果尚未连接Redis服务器Command内部将会自动尝试一次连接，但前提是Init设置无误
	返回对象：
		==true或==FWRedisCmdRet::REDIS_CMD_COMPLETED（判断条件二选一即可）
			成功，注意：就算执行成功也不代表结果对象FWRedisCR中没有错误，具体情况看FWRedisCR::QRReplyType枚举
		==false或!=FWRedisCmdRet::REDIS_CMD_COMPLETED（判断条件二选一即可）
			失败，失败时FWRedisCR无效，注意：就算失败也不代表Redis服务器没有成功执行语句，具体情况可查看FWRedisCmdRet::CmdRetType枚举的注释
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
FWRedisHelper返回值
*/
class FW_DLL FWRedisCmdRet
{
	friend class FWRedisHelper;
public:
	enum CmdRetType
	{
		REDIS_CMD_COMPLETED = 0,	//完成执行（后续可查看结果对象FWRedisCR）
		REDIS_CMD_NO_EXE = -1,		//没有执行（上下文为nullptr、命令格式化失败、发送命令至Redis服务器失败）
		REDIS_CMD_UNKNOWN = -2,		//不确定是否已执行（与Redis服务器通信中途发生错误、结果集太大内存不足）
	};
private:
	FWRedisCmdRet(CmdRetType s, int e);
public:
	~FWRedisCmdRet();

	/*
	与bool判定是否为FWRedisCmdRet::REDIS_CMD_COMPLETED
	*/
	bool operator==(const bool & b) const;
	bool operator!=(const bool & b) const;
	bool operator!() const;
	operator bool() const;

	/*
	与枚举判定
	*/
	bool operator==(const CmdRetType & i) const;
	bool operator!=(const CmdRetType & i) const;
	operator CmdRetType() const;

	/*
	查看上下文错误码
	*/
	int getContextError() const;

private:
	CmdRetType		_state;
	int				_contextError;
};


//////////////////////////////////////////////////////////////////////////


/*
FWRedisHelper命令结果
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
	得到答复类型
	*/
	CRReplyType GetReplyType() const;

	/*
	取得字符串类型答复结果
	*/
	const char * GetString() const;

	/*
	取得字符串类型答复结果的字符串长度
	*/
	int GetStringLength() const;

	/*
	取得数组类型答复结果
	*/
	const FWRedisCR * GetArray() const;

	/*
	取得数组类型答复结果的数组元素个数
	*/
	int GetArrayCount() const;

	/*
	根据下标取得数组类型答复结果的对应元素
	*/
	const FWRedisCR * GetArrayElement(int index) const;

	/*
	取得整数类型答复结果
	*/
	long long GetInteger() const;

	/*
	取得状态类型答复结果
	*/
	const char * GetStatus() const;

	/*
	取得错误类型答复结果
	*/
	const char * GetError() const;

	/*
	与状态类型答复结果比较
	*/
	bool CompareStatus(const char * status) const;

	/*
	打印
	*/
	void Dump(int depth = 0);

	/*
	清空（可再次复用）
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
Redis锁
注意：
	本锁原理为设置一个名为构造函数参数lockName的Key作为标识，Key超时为msTTL。
	不同的Redis淘汰策略有可能在调用UnLock之前就删除了锁。
	所以本锁并不是所有情况都绝对安全，不建议使用。
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
	上锁
	返回值：0为成功、-1为等待超时、-2与Redis断开连接或Redis执行错误
	*/
	int Lock();

	/*
	解锁
	返回值：0为成功、-2与Redis断开连接或Redis执行错误
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