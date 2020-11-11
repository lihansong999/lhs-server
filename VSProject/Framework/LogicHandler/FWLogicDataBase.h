#ifndef __FRAMEWORK_LOGICDATABASE_H__
#define __FRAMEWORK_LOGICDATABASE_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "../Common/FWOutPut.h"

FW_NS_BEGIN


/*
逻辑数据基类
*/
class FW_DLL FWLogicDataBase
{
public:
	FWLogicDataBase();
	virtual ~FWLogicDataBase();
};


//////////////////////////////////////////////////////////////////////////


/*
逻辑数据通用类型
*/
class FW_DLL FWLogicDataGeneral : public FWLogicDataBase
{
public:
	FWLogicDataGeneral();
	FWLogicDataGeneral(const FWLogicDataGeneral & other) = delete;
	FWLogicDataGeneral& operator=(const FWLogicDataGeneral & other) = delete;
	FWLogicDataGeneral(FWLogicDataGeneral && other) = delete;
	FWLogicDataGeneral& operator=(FWLogicDataGeneral && other) = delete;
	~FWLogicDataGeneral();
	
	void Reset();

	template <typename ValueType>
	bool PushBackValue(ValueType v)
	{
		if (_offset != 0)
		{
			FW_LOG_ERROR("%s", "_offset != 0");
			return false;
		}
		reserveCache(sizeof(ValueType));
		memcpy(&(_buffer[_size]), &v, sizeof(ValueType));
		_size += sizeof(ValueType);
		return true;
	}

	/* 以'\0'结尾的字符串，包括'\0'在内都会被保存 */
	bool PushBackString(const char * s);

	bool PushBackBuffer(const char * f, unsigned int size);
	
#pragma warning(push)
#pragma warning(disable:4700)
	template <typename ValueType>
	ValueType PopFrontValue()
	{
		ValueType r;
		if (_offset + (int)sizeof(ValueType) > _size)
		{
			FW_LOG_ERROR("%s", "_offset + sizeof(ValueType) > _size");
			return r;
		}
		memcpy(&r, &(_buffer[_offset]), sizeof(ValueType));
		_offset += sizeof(ValueType);
		return r;
	}
#pragma warning(pop)

	/* 返回一个以'\0'结尾的字符串指针，在本类对象被重置或销毁之前一直有效 */
	const char * PopFrontString();

	/* 返回一个缓冲区指针，在本类对象被重置或销毁之前一直有效 */
	const char * PopFrontBuffer(unsigned int size);

private:
	void reserveCache(int cur_need);

private:
	char  *	_buffer;
	int		_cacheSize;
	int		_size;
	int		_offset;
};



FW_NS_END


#endif //!__FRAMEWORK_LOGICDATABASE_H__