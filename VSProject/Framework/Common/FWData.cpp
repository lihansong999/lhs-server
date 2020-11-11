#include "FWData.h"
#include "FWTools.h"

FW_NS_BEGIN


FWData::FWData()
	:_data(nullptr)
	, _size(0)
{

}

FWData::FWData(const FWData & other)
	:_data(nullptr)
	, _size(0)
{
	if (other._data && other._size > 0)
	{
		_data = (char*)FW_MALLOC(other._size);
		memcpy(_data, other._data, other._size);
		_size = other._size;
	}
}

FWData& FWData::operator=(const FWData & other)
{
	if (other._data && other._size > 0)
	{
		if (_size < other._size)
		{
			Clear();
			_data = (char*)FW_MALLOC(other._size);
		}
		memcpy(_data, other._data, other._size);
		_size = other._size;
	}
	else
	{
		Clear();
	}
	return *this;
}

FWData::FWData(FWData && other)
{
	_data = other._data;
	_size = other._size;
	other._data = nullptr;
	other._size = 0;
}

FWData& FWData::operator=(FWData && other)
{
	Clear();
	_data = other._data;
	_size = other._size;
	other._data = nullptr;
	other._size = 0;
	return *this;
}

FWData::~FWData()
{
	Clear();
}

const char * FWData::GetPointer() const
{
	return _data;
}

char * FWData::GetPointer()
{
	return _data;
}

int FWData::GetSize() const
{
	return _size;
}

bool FWData::IsNull() const
{
	return (_data == nullptr || _size == 0);
}

void FWData::CopyIn(const char * data, const int size)
{
	if (data && size > 0)
	{
		if (_size < size)
		{
			Clear();
			_data = (char*)FW_MALLOC(size);
		}
		memcpy(_data, data, size);
		_size = size;
	}
	else
	{
		Clear();
	}
}

void FWData::SetIn(char * data, const int size)
{
	Clear();
	if (data && size > 0)
	{
		_data = data;
		_size = size;
	}
}

void FWData::Clear()
{
	if (_data)
	{
		FW_FREE(_data);
		_data = nullptr;
	}
	_size = 0;
}


FW_NS_END
