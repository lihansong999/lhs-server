#ifndef __FRAMEWORK_LOGICDATABASE_H__
#define __FRAMEWORK_LOGICDATABASE_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "../Common/FWOutPut.h"

FW_NS_BEGIN


/*
�߼����ݻ���
*/
class FW_DLL FWLogicDataBase
{
public:
	FWLogicDataBase();
	virtual ~FWLogicDataBase();
};


//////////////////////////////////////////////////////////////////////////


/*
�߼�����ͨ������
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

	/* ��'\0'��β���ַ���������'\0'���ڶ��ᱻ���� */
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

	/* ����һ����'\0'��β���ַ���ָ�룬�ڱ���������û�����֮ǰһֱ��Ч */
	const char * PopFrontString();

	/* ����һ��������ָ�룬�ڱ���������û�����֮ǰһֱ��Ч */
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