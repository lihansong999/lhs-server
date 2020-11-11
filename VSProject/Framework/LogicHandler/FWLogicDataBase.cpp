#include "FWLogicDataBase.h"
#include "../Common/FWTools.h"

FW_NS_BEGIN


FWLogicDataBase::FWLogicDataBase()
{

}

FWLogicDataBase::~FWLogicDataBase()
{

}


//////////////////////////////////////////////////////////////////////////


FWLogicDataGeneral::FWLogicDataGeneral()
	:_buffer(NULL)
	, _cacheSize(0)
	, _size(0)
	, _offset(0)
{

}

void FWLogicDataGeneral::Reset()
{
	_size = 0;
	_offset = 0;
}

FWLogicDataGeneral::~FWLogicDataGeneral()
{
	if (_buffer)
	{
		FW_FREE(_buffer);
	}
}

bool FWLogicDataGeneral::PushBackString(const char * s)
{
	if (_offset != 0)
	{
		FW_LOG_ERROR("%s", "_offset != 0");
		return false;
	}
	size_t size = strlen(s) + 1;
	reserveCache((int)size);
	memcpy(&(_buffer[_size]), s, size);
	_size += (int)size;
	return true;
}

bool FWLogicDataGeneral::PushBackBuffer(const char * f, unsigned int size)
{
	if (_offset != 0)
	{
		FW_LOG_ERROR("%s", "_offset != 0");
		return false;
	}
	if (size > 0)
	{
		reserveCache(size);
		memcpy(&(_buffer[_size]), f, size);
		_size += size;
		return true;
	}
	return false;
}

const char * FWLogicDataGeneral::PopFrontString()
{
	int len = 1;
	bool strEnd = false;
	for (int i = _offset; i < _size; i++, len++)
	{
		if (_buffer[i] == '\0')
		{
			strEnd = true;
			break;
		}
	}
	if (!strEnd)
	{
		FW_LOG_ERROR("%s", "strEnd == false");
		return nullptr;
	}
	const char * r = &(_buffer[_offset]);
	_offset += len;
	return r;
}

const char * FWLogicDataGeneral::PopFrontBuffer(unsigned int size)
{
	if (_offset + (int)size > _size)
	{
		FW_LOG_ERROR("%s", "_offset + size > _size");
		return nullptr;
	}
	const char * r = &(_buffer[_offset]);
	_offset += size;
	return r;
}

void FWLogicDataGeneral::reserveCache(int cur_need)
{
#define DEFAULT_CACHE_SIZE	128

	if (cur_need > 0)
	{
		int temp = _cacheSize;
		while (temp < _size + cur_need)
		{
			if (temp == 0)
				temp = DEFAULT_CACHE_SIZE;
			else
				temp *= 2;
		}
		if (temp != _cacheSize)
		{
			_buffer = (char*)FW_REALLOC(_buffer, temp);
			if (!_buffer)
			{
				FW_LOG_ERROR("%s", "FW_REALLOC return NULL");
			}
			_cacheSize = temp;
		}
	}
}



FW_NS_END