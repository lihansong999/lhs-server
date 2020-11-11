#include "stdafx.h"
#include "Data.h"


Data::Data()
	:_data(nullptr)
	, _size(0)
{

}

Data::Data(const Data & other)
	:_data(nullptr)
	, _size(0)
{
	if (other._data && other._size > 0)
	{
		_data = (char*)malloc(other._size);
		memcpy(_data, other._data, other._size);
		_size = other._size;
	}
}

Data& Data::operator=(const Data & other)
{
	if (other._data && other._size > 0)
	{
		if (_size < other._size)
		{
			Clear();
			_data = (char*)malloc(other._size);
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

Data::Data(Data && other)
{
	_data = other._data;
	_size = other._size;
	other._data = nullptr;
	other._size = 0;
}

Data& Data::operator=(Data && other)
{
	Clear();
	_data = other._data;
	_size = other._size;
	other._data = nullptr;
	other._size = 0;
	return *this;
}

Data::~Data()
{
	Clear();
}

const char * Data::GetPointer() const
{
	return _data;
}

char * Data::GetPointer()
{
	return _data;
}

int Data::GetSize() const
{
	return _size;
}

bool Data::IsNull() const
{
	return (_data == nullptr || _size == 0);
}

void Data::CopyIn(const char * data, const int size)
{
	if (data && size > 0)
	{
		if (_size < size)
		{
			Clear();
			_data = (char*)malloc(size);
		}
		memcpy(_data, data, size);
		_size = size;
	}
	else
	{
		Clear();
	}
}

void Data::SetIn(char * data, const int size)
{
	Clear();
	if (data && size > 0)
	{
		_data = data;
		_size = size;
	}
}

void Data::Clear()
{
	if (_data)
	{
		free(_data);
		_data = nullptr;
	}
	_size = 0;
}
