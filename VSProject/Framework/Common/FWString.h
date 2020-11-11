#ifndef __FRAMEWORK_STRING_H__
#define __FRAMEWORK_STRING_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"

FW_NS_BEGIN


/*
×Ö·û´®
*/
class FW_DLL FWString
{
public:
	FWString();
	FWString(const char * s);
	FWString(const char * s, size_t len);
	FWString(const FWString & other);
	FWString& operator=(const FWString & other);
	FWString& operator=(const char * s);
	FWString(FWString && other);
	FWString& operator=(FWString && other);
	~FWString();

	void Reserve(size_t newcap);
	void Resize(size_t newsize);

	const char * C_Str() const;
	size_t Size() const;

	int Compare(const char * s) const;
	int Compare(const FWString & s) const;

	FWString& Assign(const char * s);
	FWString& Assign(const char * s, size_t len);
	FWString& Assign(const FWString & s);

	FWString& Append(const char * s);
	FWString& Append(const char * s, size_t len);
	FWString& Append(const FWString & s);
	FWString& operator+=(const char * s);
	FWString& operator+=(const FWString & s);

	size_t Find(const char * s, size_t off = 0) const;
	size_t Find(const FWString & s, size_t off = 0) const;
	size_t Find_First_Of(const char * s, size_t off = 0) const;
	size_t Find_First_Of(const FWString & s, size_t off = 0) const;
	size_t Find_First_Not_Of(const char * s, size_t off = 0) const;
	size_t Find_First_Not_Of(const FWString & s, size_t off = 0) const;
	size_t RFind(const char * s, size_t off = npos) const;
	size_t RFind(const FWString & s, size_t off = npos) const;
	size_t Find_Last_Of(const char * s, size_t off = npos) const;
	size_t Find_Last_Of(const FWString & s, size_t off = npos) const;
	size_t Find_Last_Not_Of(const char * s, size_t off = npos) const;
	size_t Find_Last_Not_Of(const FWString & s, size_t off = npos) const;

	FWString& Erase(size_t off = 0);
	FWString& Erase(size_t off, size_t count);

	void Push_Back(char c);
	void Pop_Back();

	FWString& Replace(size_t off, size_t len, const char * s);
	FWString& Replace(size_t off, size_t len, const FWString & s);

	FWString Substr(size_t off = 0, size_t count = npos);

public:
	static const size_t npos;

private:
	void * _string;
};


//////////////////////////////////////////////////////////////////////////


/*
Unicode×Ö·û´®
*/
class FW_DLL FWWString
{
public:
	FWWString();
	FWWString(const wchar_t * s);
	FWWString(const wchar_t * s, size_t len);
	FWWString(const FWWString & other);
	FWWString& operator=(const FWWString & other);
	FWWString& operator=(const wchar_t * s);
	FWWString(FWWString && other);
	FWWString& operator=(FWWString && other);
	~FWWString();

	void Reserve(size_t newcap);
	void Resize(size_t newsize);

	const wchar_t * C_Str() const;
	size_t Size() const;

	int Compare(const wchar_t * s);
	int Compare(const FWWString & s);

	FWWString& Assign(const wchar_t * s);
	FWWString& Assign(const wchar_t * s, size_t len);
	FWWString& Assign(const FWWString & s);

	FWWString& Append(const wchar_t * s);
	FWWString& Append(const wchar_t * s, size_t len);
	FWWString& Append(const FWWString & s);
	FWWString& operator+=(const wchar_t * s);
	FWWString& operator+=(const FWWString & s);

	size_t Find(const wchar_t * s, size_t off = 0) const;
	size_t Find(const FWWString & s, size_t off = 0) const;
	size_t Find_First_Of(const wchar_t * s, size_t off = 0) const;
	size_t Find_First_Of(const FWWString & s, size_t off = 0) const;
	size_t Find_First_Not_Of(const wchar_t * s, size_t off = 0) const;
	size_t Find_First_Not_Of(const FWWString & s, size_t off = 0) const;
	size_t RFind(const wchar_t * s, size_t off = npos) const;
	size_t RFind(const FWWString & s, size_t off = npos) const;
	size_t Find_Last_Of(const wchar_t * s, size_t off = npos) const;
	size_t Find_Last_Of(const FWWString & s, size_t off = npos) const;
	size_t Find_Last_Not_Of(const wchar_t * s, size_t off = npos) const;
	size_t Find_Last_Not_Of(const FWWString & s, size_t off = npos) const;

	FWWString& Erase(size_t off = 0);
	FWWString& Erase(size_t off, size_t count);

	void Push_Back(wchar_t c);
	void Pop_Back();

	FWWString& Replace(size_t off, size_t len, const wchar_t * s);
	FWWString& Replace(size_t off, size_t len, const FWWString & s);

	FWWString Substr(size_t off = 0, size_t count = npos);

public:
	static const size_t npos;

private:
	void * _wstring;
};


FW_NS_END


#endif //!__FRAMEWORK_STRING_H__