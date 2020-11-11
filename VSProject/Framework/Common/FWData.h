#ifndef __FRAMEWORK_DATA_H__
#define __FRAMEWORK_DATA_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"

FW_NS_BEGIN


/*
数据
*/
class FW_DLL FWData
{
public:
	FWData();
	FWData(const FWData & other);
	FWData& operator=(const FWData & other);
	FWData(FWData && other);
	FWData& operator=(FWData && other);
	~FWData();
	
	const char * GetPointer() const;

	char * GetPointer();

	int GetSize() const;

	bool IsNull() const;

	void CopyIn(const char * data, const int size);

	/* data内存必须由FW_MALLOC分配 */
	void SetIn(char * data, const int size);
	
	void Clear();

private:
	char *  _data;
	int		_size;
};



FW_NS_END


#endif //!__FRAMEWORK_DATA_H__