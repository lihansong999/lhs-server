#include "FWRedisHelper.h"
#include "../Common/FWOutPut.h"
#include "../Common/FWTools.h"

FW_NS_BEGIN


class StackAutoFreeReply
{
public:
	StackAutoFreeReply(redisReply * reply) :_reply(reply) {};
	~StackAutoFreeReply() { if (_reply) { freeReplyObject(_reply); } }
private:
	redisReply * _reply;
};


//////////////////////////////////////////////////////////////////////////


FWRedisHelper::FWRedisHelper()
	:_context(nullptr)
{
	_host[0] = '\0';
	_port = 0;
	_password[0] = '\0';
	_selectIndex = 0;
	_connectTimeOut = 0L;
	_rwTimeOut = 0L;
}

FWRedisHelper::~FWRedisHelper()
{
	this->Disconnect();
}

void FWRedisHelper::Init(const char * host, int port, const char * password, int selectIndex, long connectTimeOut, long rwTimeOut)
{
	this->Disconnect();
	strcpy_s(_host, sizeof(_host), host);
	_port = port;
	strcpy_s(_password, sizeof(_password), (password ? password : ""));
	_selectIndex = selectIndex;
	_connectTimeOut = connectTimeOut;
	_rwTimeOut = rwTimeOut;
}

bool FWRedisHelper::Connect()
{
	this->Disconnect();
	if (_connectTimeOut != 0L)
	{
		struct timeval timeout = { _connectTimeOut, 0 };
		_context = redisConnectWithTimeout(_host, _port, timeout);
	}
	else
	{
		_context = redisConnect(_host, _port);
	}
	if (_context->err) {
		FW_LOG_ERROR("%s%s%d%s%s", "redisConnectWithTimeout", " 失败，错误码：", _context->err, "，错误信息：", (_context->errstr ? _context->errstr : ""));
		this->Disconnect();
		return false;
	}
	if (_rwTimeOut != 0L)
	{
		struct timeval timeout = { _rwTimeOut, 0 };
		if (redisSetTimeout(_context, timeout) != REDIS_OK)
		{
			FW_LOG_WRNING("%s", "redisSetTimeout 失败");
		}
	}
	if (_password[0] != '\0')
	{
		FWRedisCR authCR;
		FWRedisCmdRet authRet = this->Command(&authCR, "AUTH %s", _password);
		if (!authRet || authCR.CompareStatus("OK") == false)
		{
			if (authRet)
			{
				FW_LOG_ERROR("%s%d%s%s", "AUTH 失败，FWRedisCR类型：", (int)authCR.GetReplyType(), " String Value：", (authCR._string ? authCR._string : ""));
			}
			else
			{
				FW_LOG_ERROR("%s", "AUTH 失败");
			}
			this->Disconnect();
			return false;
		}
	}
	if (_selectIndex != 0)
	{
		FWRedisCR selectCR;
		FWRedisCmdRet selectRet = this->Command(&selectCR, "SELECT %d", _selectIndex);
		if (!selectRet || selectCR.CompareStatus("OK") == false)
		{
			if (selectRet)
			{
				FW_LOG_ERROR("%s%d%s%s", "SELECT 失败，FWRedisCR类型：", (int)selectCR.GetReplyType(), " String Value：", (selectCR._string ? selectCR._string : ""));
			}
			else
			{
				FW_LOG_ERROR("%s", "SELECT 失败");
			}
			this->Disconnect();
			return false;
		}
	}
	return true;
}

void FWRedisHelper::Disconnect()
{
	if (_context)
	{
		redisFree(_context);
		_context = nullptr;
	}
}

bool FWRedisHelper::Ping()
{
	if (!_context)
	{
		return false;
	}
	FWRedisCR redisCR;
	FWRedisCmdRet r = this->Command(&redisCR, "PING");
	if (r && redisCR.CompareStatus("PONG"))
	{
		return true;
	}
	return false;
}

bool FWRedisHelper::Hello(int version)
{
	if (!_context)
	{
		return false;
	}
	int expected = version == 3 ? REDIS_REPLY_MAP : REDIS_REPLY_ARRAY;
	FWRedisCR redisCR;
	FWRedisCmdRet r = this->Command(&redisCR, "HELLO %d", version);
	if (r && redisCR.GetReplyType() == expected)
	{
		return true;
	}
	return false;
}

static int _RedisHandledPushReply(redisContext *c, void *reply) {
	if (reply && c->push_cb && redisIsPushReply(reply)) {
		c->push_cb(c->privdata, reply);
		return 1;
	}
	return 0;
}

FWRedisCmdRet FWRedisHelper::Command(FWRedisCR * cr, const char * format, ...)
{
	if (cr)
	{
		cr->Clear();
	}
	if (!_context)
	{
		if (!this->Connect())
		{
			return FWRedisCmdRet(FWRedisCmdRet::REDIS_CMD_NO_EXE, REDIS_ERR_OTHER);
		}
	}
	va_list args;
	va_start(args, format);
	int r = redisvAppendCommand(_context, format, args);
	va_end(args);
	if (r != REDIS_OK)
	{
		int e = _context->err;
		FW_LOG_ERROR("%s%d", "命令格式化出错，上下文错误码：", e);
		this->Disconnect();
		return FWRedisCmdRet(FWRedisCmdRet::REDIS_CMD_NO_EXE, e);
	}
	redisReply * reply = nullptr;
	if (redisGetReplyFromReader(_context, (void**)&reply) != REDIS_OK)
	{
		int e = _context->err;
		FW_LOG_ERROR("%s%d", "读取上一次数据出错，FWRedisHelper类设计上有严重错误，上下文错误码：", e);
		this->Disconnect();
		return FWRedisCmdRet(FWRedisCmdRet::REDIS_CMD_UNKNOWN, e);
	}
	if (reply)
	{
		FW_LOG_ERROR("%s", "reply != nullptr，FWRedisHelper类设计上有严重错误。");
	}
	if (reply == NULL && _context->flags & REDIS_BLOCK)
	{
		int wdone = 0;
		do {
			if (redisBufferWrite(_context, &wdone) != REDIS_OK)
			{	
				int e = _context->err;
				this->Disconnect();
				/*
				由于没有使用管道技术发送多条命令
				所以redisBufferWrite返回失败之后Redis服务器肯定不会执行任何命令
				*/
				return FWRedisCmdRet(FWRedisCmdRet::REDIS_CMD_NO_EXE, e);
			}
		} while (!wdone);
		do {
			if (redisBufferRead(_context) != REDIS_OK)
			{
				int e = _context->err;
				this->Disconnect();
				return FWRedisCmdRet(FWRedisCmdRet::REDIS_CMD_UNKNOWN, e);
			}
			do
			{
				if (redisGetReplyFromReader(_context, (void**)&reply) != REDIS_OK)
				{
					int e = _context->err;
					this->Disconnect();
					return FWRedisCmdRet(FWRedisCmdRet::REDIS_CMD_UNKNOWN, e);
				}
			} while (_RedisHandledPushReply(_context, reply));
		} while (reply == NULL);
	}
	StackAutoFreeReply safr(reply);
	if (cr)
	{
		_foreachReply(cr, reply);
	}
	return FWRedisCmdRet(FWRedisCmdRet::REDIS_CMD_COMPLETED, REDIS_OK);
}

void FWRedisHelper::_foreachReply(FWRedisCR * qr, redisReply * reply)
{
	switch (reply->type)
	{
	case REDIS_REPLY_STRING:
	{
		qr->_qrrt = FWRedisCR::REDIS_CR_TYPE_STRING;
		qr->_sLen = (int)reply->len;
		qr->_string = new char[reply->len + 1];
		qr->_string[reply->len] = '\0';
		for (size_t i = 0; i < reply->len; i++)
		{
			qr->_string[i] = reply->str[i];
		}
	}
		break;
	case REDIS_REPLY_ARRAY:
	{
		qr->_qrrt = FWRedisCR::REDIS_CR_TYPE_ARRAY;
		if (reply->elements > 0)
		{
			qr->_crArrayCount = (int)reply->elements;
			qr->_crArray = new FWRedisCR[reply->elements];
			for (int i = 0; i < (int)reply->elements; i++)
			{
				_foreachReply(&(qr->_crArray[i]), reply->element[i]);
			}
		}
	}
		break;
	case REDIS_REPLY_INTEGER:
	{
		qr->_qrrt = FWRedisCR::REDIS_CR_TYPE_INTEGER;
		qr->_integer = reply->integer;
	}
		break;
	case REDIS_REPLY_NIL:
	{
		qr->_qrrt = FWRedisCR::REDIS_CR_TYPE_NIL;
	}
		break;
	case REDIS_REPLY_STATUS:
	{
		qr->_qrrt = FWRedisCR::REDIS_CR_TYPE_STATUS;
		qr->_sLen = (int)reply->len;
		qr->_string = new char[reply->len + 1];
		qr->_string[reply->len] = '\0';
		for (size_t i = 0; i < reply->len; i++)
		{
			qr->_string[i] = reply->str[i];
		}
	}
		break;
	case REDIS_REPLY_ERROR:
	{
		qr->_qrrt = FWRedisCR::REDIS_CR_TYPE_ERROR;
		qr->_sLen = (int)reply->len;
		qr->_string = new char[reply->len + 1];
		qr->_string[reply->len] = '\0';
		for (size_t i = 0; i < reply->len; i++)
		{
			qr->_string[i] = reply->str[i];
		}
	}
		break;
	default:
	{
		qr->_qrrt = (FWRedisCR::CRReplyType)reply->type;
		FW_LOG_ERROR("不支持的协议类型 = %d", (int)qr->_qrrt);
	}
		break;
	}
}


//////////////////////////////////////////////////////////////////////////


FWRedisCmdRet::FWRedisCmdRet(CmdRetType s, int e)
	:_state(s)
	, _contextError(e)
{

}

FWRedisCmdRet::~FWRedisCmdRet()
{

}

bool FWRedisCmdRet::operator==(const bool & b) const
{
	return (_state == REDIS_CMD_COMPLETED) == b;
}

bool FWRedisCmdRet::operator!=(const bool & b) const
{
	return (_state == REDIS_CMD_COMPLETED) != b;
}

bool FWRedisCmdRet::operator!() const
{
	return !(_state == REDIS_CMD_COMPLETED);
}

FWRedisCmdRet::operator bool() const
{
	return _state == REDIS_CMD_COMPLETED;
}

bool FWRedisCmdRet::operator==(const CmdRetType & i) const
{
	return _state == i;
}

bool FWRedisCmdRet::operator!=(const CmdRetType & i) const
{
	return _state != i;
}

FWRedisCmdRet::operator CmdRetType() const
{
	return _state;
}

int FWRedisCmdRet::getContextError() const
{
	return _contextError;
}


//////////////////////////////////////////////////////////////////////////


FWRedisCR::FWRedisCR()
	:_qrrt(REDIS_CR_TYPE_ERROR)
	, _integer(0LL)
	, _string(nullptr)
	, _sLen(0)
	, _crArray(nullptr)
	, _crArrayCount(0)
{

}

FWRedisCR::~FWRedisCR()
{
	this->Clear();
}

FWRedisCR::CRReplyType FWRedisCR::GetReplyType() const
{
	return _qrrt;
}

const char * FWRedisCR::GetString() const
{
	if (_qrrt != REDIS_CR_TYPE_STRING)
	{
		return nullptr;
	}
	return _string;
}

int FWRedisCR::GetStringLength() const
{
	if (_qrrt != REDIS_CR_TYPE_STRING)
	{
		return 0;
	}
	return _sLen;
}

const FWRedisCR * FWRedisCR::GetArray() const
{
	if (_qrrt != REDIS_CR_TYPE_ARRAY)
	{
		return nullptr;
	}
	return _crArray;
}

int FWRedisCR::GetArrayCount() const
{
	if (_qrrt != REDIS_CR_TYPE_ARRAY)
	{
		return 0;
	}
	return _crArrayCount;
}

const FWRedisCR * FWRedisCR::GetArrayElement(int index) const
{
	if (_qrrt != REDIS_CR_TYPE_ARRAY)
	{
		return nullptr;
	}
	if (index >= _crArrayCount)
	{
		FW_LOG_WRNING("%s", "index >= _elements");
		return nullptr;
	}
	return &(_crArray[index]);
}

long long FWRedisCR::GetInteger() const
{
	if (_qrrt != REDIS_CR_TYPE_INTEGER)
	{
		return 0LL;
	}
	return _integer;
}

const char * FWRedisCR::GetStatus() const
{
	if (_qrrt != REDIS_CR_TYPE_STATUS)
	{
		return nullptr;
	}
	return _string;
}

const char * FWRedisCR::GetError() const
{
	if (_qrrt != REDIS_CR_TYPE_ERROR)
	{
		return nullptr;
	}
	return _string;
}

bool FWRedisCR::CompareStatus(const char * status) const
{
	if (_qrrt != REDIS_CR_TYPE_STATUS)
	{
		return false;
	}
	return strcmp(_string, status) == 0;
}

void FWRedisCR::Dump(int depth /*= 0*/)
{
	std::string ds;
	for (int i = 0; i < depth; i++)
	{
		ds.append("  ");
	}
	switch (_qrrt)
	{
	case REDIS_CR_TYPE_STRING:
	{
		FW_PRINT("%sString = %s", ds.c_str(), _string);
	}
		break;
	case REDIS_CR_TYPE_ARRAY:
	{
		FW_PRINT("%sARRAY = {", ds.c_str());
		for (int i = 0; i < _crArrayCount; i++)
		{
			_crArray[i].Dump(depth + 1);
		}
		FW_PRINT("%s}", ds.c_str());
	}
		break;
	case REDIS_CR_TYPE_INTEGER:
	{
		FW_PRINT("%sInteger = %lld", ds.c_str(), _integer);
	}
		break;
	case REDIS_CR_TYPE_NIL:
	{
		FW_PRINT("%sNil", ds.c_str());
	}
		break;
	case REDIS_CR_TYPE_STATUS:
	{
		FW_PRINT("%sStatus = %s", ds.c_str(), _string);
	}
		break;
	case REDIS_CR_TYPE_ERROR:
	{
		FW_PRINT("%sError = %s", ds.c_str(), _string);
	}
		break;
	default:
	{
		FW_PRINT("不支持的协议类型 = %d", (int)_qrrt);
	}
		break;
	}
}

void FWRedisCR::Clear()
{
	_qrrt = REDIS_CR_TYPE_ERROR;
	_integer = 0LL;
	if (_string)
	{
		delete[] _string;
		_string = nullptr;
	}
	_sLen = 0;
	if (_crArray)
	{
		for (int i = 0; i < _crArrayCount; i++)
		{
			_crArray[i].Clear();
		}
		delete[] _crArray;
		_crArray = nullptr;
	}
	_crArrayCount = 0;
}


//////////////////////////////////////////////////////////////////////////


FWRedisLock::FWRedisLock(FWRedisHelper * redisHelper, const char * lockName, int msTTL /*= 10000*/, int msRetriesInvl /*= 100*/, long long msWaitTimeOut /*= LLONG_MAX*/)
	:_redisHelper(redisHelper)
	, _randValue(rand())
	, _msTTL(msTTL)
	, _msRetriesInvl(msRetriesInvl)
	, _msWaitTimeOut(msWaitTimeOut)
	, _unLockScript("if redis.call(\"GET\", KEYS[1]) == ARGV[1] then return redis.call(\"DEL\", KEYS[1]) else return 0 end")
{
	_lockName = lockName;
	_lockName.Append(".lhs.lock");
}

FWRedisLock::~FWRedisLock()
{

}

int FWRedisLock::Lock()
{
	long long lastTime = 0;
	if (_msWaitTimeOut != LLONG_MAX)
	{
		lastTime = FW_TIME();
	}
	FWRedisCR redisCR;
	while (true)
	{
		FWRedisCmdRet redisCmdRet = _redisHelper->Command(&redisCR, "SET %s %d PX %d NX", _lockName.C_Str(), _randValue, _msTTL);
		if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED)
		{
			return -2;
		}
		if (redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
		{
			return -2;
		}
		if (redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_STATUS && strcmp(redisCR.GetStatus(), "OK") == 0)
		{
			return 0;
		}
		if (_msWaitTimeOut != LLONG_MAX)
		{
			if (FW_TIME() - lastTime >= _msWaitTimeOut - (long long)_msRetriesInvl)
			{
				return -1;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(_msRetriesInvl));
	}
}

int FWRedisLock::UnLock()
{
	FWRedisCR redisCR;
	FWRedisCmdRet redisCmdRet = _redisHelper->Command(&redisCR, "EVAL %s %d %s %d", _unLockScript, 1, _lockName.C_Str(), _randValue);
	if (((FWRedisCmdRet::CmdRetType)redisCmdRet) != FWRedisCmdRet::REDIS_CMD_COMPLETED || redisCR.GetReplyType() == FWRedisCR::REDIS_CR_TYPE_ERROR)
	{
		return -2;
	}
	return 0;
}


FW_NS_END


////Redis测试
//FWRedisCR redisQR;
//FWRedisCmdRet redisCmdRet = redisHelper->Command(&redisQR, "EVAL %s %d", "return {{ \"123\", { 55, 66}, \"456\" },{ \"888\", 999}}", 0);
//switch ((FWRedisCmdRet::CmdRetType)redisCmdRet)
//{
//case FWRedisCmdRet::REDIS_CMD_COMPLETED:
//{
//	redisQR.Dump();
//}
//	break;
//case FWRedisCmdRet::REDIS_CMD_NO_EXE:
//{
//	FW_PRINT("%s", "Redis命令没有执行");
//}
//	break;
//case FWRedisCmdRet::REDIS_CMD_UNKNOWN:
//{
//	FW_PRINT("%s", "无法确定Redis命令是否执行");
//}
//	break;
//default:
//	break;
//}