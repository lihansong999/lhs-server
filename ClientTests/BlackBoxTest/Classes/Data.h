#ifndef __DATA_H__
#define __DATA_H__

#include "Local.h"


class Data
{
public:
	Data();
	Data(const Data & other);
	Data& operator=(const Data & other);
	Data(Data && other);
	Data& operator=(Data && other);
	~Data();
	
	const char * GetPointer() const;

	char * GetPointer();

	int GetSize() const;

	bool IsNull() const;

	void CopyIn(const char * data, const int size);

	/* data内存必须由malloc分配 */
	void SetIn(char * data, const int size);
	
	void Clear();

private:
	char *  _data;
	int		_size;
};



#endif //!__DATA_H__