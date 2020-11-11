#include "FWString.h"


FW_NS_BEGIN


const size_t FWString::npos = std::string::npos;

FWString::FWString()
{
	_string = new std::string();
}

FWString::FWString(const char * s, size_t len)
{
	_string = new std::string(s, len);
}

FWString::FWString(const char * s)
{
	_string = new std::string(s);
}

FWString::FWString(const FWString & other)
{
	_string = new std::string(*((std::string*)other._string));
}

FWString& FWString::operator=(const char * s)
{
	*((std::string*)_string) = s;
	return *this;
}

FWString& FWString::operator=(const FWString & other)
{
	*((std::string*)_string) = *((std::string*)other._string);
	return *this;
}

FWString::FWString(FWString && other)
{
	_string = new std::string(std::move(*((std::string*)other._string)));
}

FWString& FWString::operator=(FWString && other)
{
	*((std::string*)_string) = std::move(*((std::string*)other._string));
	return *this;
}

FWString::~FWString()
{
	delete ((std::string*)_string);
}

void FWString::Reserve(size_t newcap)
{
	((std::string*)_string)->reserve(newcap);
}

void FWString::Resize(size_t newsize)
{
	((std::string*)_string)->resize(newsize);
}

const char * FWString::C_Str() const
{
	return ((std::string*)_string)->c_str();
}

size_t FWString::Size() const
{
	return ((std::string*)_string)->size();
}

int FWString::Compare(const char * s) const
{
	return ((std::string*)_string)->compare(s);
}

int FWString::Compare(const FWString & s) const
{
	return ((std::string*)_string)->compare(*((std::string*)s._string));
}

FWString& FWString::Assign(const char * s)
{
	((std::string*)_string)->assign(s);
	return *this;
}

FWString& FWString::Assign(const char * s, size_t len)
{
	((std::string*)_string)->assign(s, len);
	return *this;
}

FWString& FWString::Assign(const FWString & s)
{
	((std::string*)_string)->assign(*((std::string*)s._string));
	return *this;
}

FWString& FWString::Append(const char * s)
{
	((std::string*)_string)->append(s);
	return *this;
}

FWString& FWString::Append(const char * s, size_t len)
{
	((std::string*)_string)->append(s, len);
	return *this;
}

FWString& FWString::Append(const FWString & s)
{
	((std::string*)_string)->append(*((std::string*)s._string));
	return *this;
}

FWString& FWString::operator+=(const char * s)
{
	return this->Append(s);
}

FWString& FWString::operator+=(const FWString & s)
{
	return this->Append(s);
}

size_t FWString::Find(const char * s, size_t off /*= 0*/) const
{
	return ((std::string*)_string)->find(s, off);
}

size_t FWString::Find(const FWString & s, size_t off /*= 0*/) const
{
	return ((std::string*)_string)->find(*((std::string*)s._string), off);
}

size_t FWString::RFind(const char * s, size_t off /*= npos*/) const
{
	return ((std::string*)_string)->rfind(s, off);
}

size_t FWString::RFind(const FWString & s, size_t off /*= npos*/) const
{
	return ((std::string*)_string)->rfind(*((std::string*)s._string), off);
}

size_t FWString::Find_First_Of(const char * s, size_t off /*= 0*/) const
{
	return ((std::string*)_string)->find_first_of(s, off);
}

size_t FWString::Find_First_Of(const FWString & s, size_t off /*= 0*/) const
{
	return ((std::string*)_string)->find_first_of(*((std::string*)s._string), off);
}

size_t FWString::Find_First_Not_Of(const char * s, size_t off /*= 0*/) const
{
	return ((std::string*)_string)->find_first_not_of(s, off);
}

size_t FWString::Find_First_Not_Of(const FWString & s, size_t off /*= 0*/) const
{
	return ((std::string*)_string)->find_first_not_of(*((std::string*)s._string), off);
}

size_t FWString::Find_Last_Of(const char * s, size_t off /*= npos*/) const
{
	return ((std::string*)_string)->find_last_of(s, off);
}

size_t FWString::Find_Last_Of(const FWString & s, size_t off /*= npos*/) const
{
	return ((std::string*)_string)->find_last_of(*((std::string*)s._string), off);
}

size_t FWString::Find_Last_Not_Of(const char * s, size_t off /*= npos*/) const
{
	return ((std::string*)_string)->find_last_not_of(s, off);
}

size_t FWString::Find_Last_Not_Of(const FWString & s, size_t off /*= npos*/) const
{
	return ((std::string*)_string)->find_last_not_of(*((std::string*)s._string), off);
}

FWString& FWString::Erase(size_t off /*= 0*/)
{
	((std::string*)_string)->erase(off);
	return *this;
}

FWString& FWString::Erase(size_t off, size_t count)
{
	((std::string*)_string)->erase(off, count);
	return *this;
}

void FWString::Push_Back(char c)
{
	((std::string*)_string)->push_back(c);
}

void FWString::Pop_Back()
{
	((std::string*)_string)->pop_back();
}

FWString& FWString::Replace(size_t off, size_t len, const char * s)
{
	((std::string*)_string)->replace(off, len, s);
	return *this;
}

FWString& FWString::Replace(size_t off, size_t len, const FWString & s)
{
	((std::string*)_string)->replace(off, len, *((std::string*)s._string));
	return *this;
}

FWString FWString::Substr(size_t off /*= 0*/, size_t count /*= npos*/)
{
	std::string r = ((std::string*)_string)->substr(off, count);
	return FWString(r.c_str(), r.size());
}


//////////////////////////////////////////////////////////////////////////


const size_t FWWString::npos = std::wstring::npos;

FWWString::FWWString()
{
	_wstring = new std::wstring();
}

FWWString::FWWString(const wchar_t * s, size_t len)
{
	_wstring = new std::wstring(s, len);
}

FWWString::FWWString(const wchar_t * s)
{
	_wstring = new std::wstring(s);
}

FWWString::FWWString(const FWWString & other)
{
	_wstring = new std::wstring(*((std::wstring*)other._wstring));
}

FWWString& FWWString::operator=(const wchar_t * s)
{
	*((std::wstring*)_wstring) = s;
	return *this;
}

FWWString& FWWString::operator=(const FWWString & other)
{
	*((std::wstring*)_wstring) = *((std::wstring*)other._wstring);
	return *this;
}

FWWString::FWWString(FWWString && other)
{
	_wstring = new std::wstring(std::move(*((std::wstring*)other._wstring)));
}

FWWString& FWWString::operator=(FWWString && other)
{
	*((std::wstring*)_wstring) = std::move(*((std::wstring*)other._wstring));
	return *this;
}

FWWString::~FWWString()
{
	delete ((std::wstring*)_wstring);
}

void FWWString::Reserve(size_t newcap)
{
	((std::wstring*)_wstring)->reserve(newcap);
}

void FWWString::Resize(size_t newsize)
{
	((std::wstring*)_wstring)->resize(newsize);
}

const wchar_t * FWWString::C_Str() const
{
	return ((std::wstring*)_wstring)->c_str();
}

size_t FWWString::Size() const
{
	return ((std::wstring*)_wstring)->size();
}

int FWWString::Compare(const wchar_t * s)
{
	return ((std::wstring*)_wstring)->compare(s);
}

int FWWString::Compare(const FWWString & s)
{
	return ((std::wstring*)_wstring)->compare(*((std::wstring*)s._wstring));
}

FWWString& FWWString::Assign(const wchar_t * s)
{
	((std::wstring*)_wstring)->assign(s);
	return *this;
}

FWWString& FWWString::Assign(const wchar_t * s, size_t len)
{
	((std::wstring*)_wstring)->assign(s, len);
	return *this;
}

FWWString& FWWString::Assign(const FWWString & s)
{
	((std::wstring*)_wstring)->assign(*((std::wstring*)s._wstring));
	return *this;
}

FWWString& FWWString::Append(const wchar_t * s)
{
	((std::wstring*)_wstring)->append(s);
	return *this;
}

FWWString& FWWString::Append(const wchar_t * s, size_t len)
{
	((std::wstring*)_wstring)->append(s, len);
	return *this;
}

FWWString& FWWString::Append(const FWWString & s)
{
	((std::wstring*)_wstring)->append(*((std::wstring*)s._wstring));
	return *this;
}

FWWString& FWWString::operator+=(const wchar_t * s)
{
	return this->Append(s);
}

FWWString& FWWString::operator+=(const FWWString & s)
{
	return this->Append(s);
}

size_t FWWString::Find(const wchar_t * s, size_t off /*= 0*/) const
{
	return ((std::wstring*)_wstring)->find(s, off);
}

size_t FWWString::Find(const FWWString & s, size_t off /*= 0*/) const
{
	return ((std::wstring*)_wstring)->find(*((std::wstring*)s._wstring), off);
}

size_t FWWString::RFind(const wchar_t * s, size_t off /*= npos*/) const
{
	return ((std::wstring*)_wstring)->rfind(s, off);
}

size_t FWWString::RFind(const FWWString & s, size_t off /*= npos*/) const
{
	return ((std::wstring*)_wstring)->rfind(*((std::wstring*)s._wstring), off);
}

size_t FWWString::Find_First_Of(const wchar_t * s, size_t off /*= 0*/) const
{
	return ((std::wstring*)_wstring)->find_first_of(s, off);
}

size_t FWWString::Find_First_Of(const FWWString & s, size_t off /*= 0*/) const
{
	return ((std::wstring*)_wstring)->find_first_of(*((std::wstring*)s._wstring), off);
}

size_t FWWString::Find_First_Not_Of(const wchar_t * s, size_t off /*= 0*/) const
{
	return ((std::wstring*)_wstring)->find_first_not_of(s, off);
}

size_t FWWString::Find_First_Not_Of(const FWWString & s, size_t off /*= 0*/) const
{
	return ((std::wstring*)_wstring)->find_first_not_of(*((std::wstring*)s._wstring), off);
}

size_t FWWString::Find_Last_Of(const wchar_t * s, size_t off /*= npos*/) const
{
	return ((std::wstring*)_wstring)->find_last_of(s, off);
}

size_t FWWString::Find_Last_Of(const FWWString & s, size_t off /*= npos*/) const
{
	return ((std::wstring*)_wstring)->find_last_of(*((std::wstring*)s._wstring), off);
}

size_t FWWString::Find_Last_Not_Of(const wchar_t * s, size_t off /*= npos*/) const
{
	return ((std::wstring*)_wstring)->find_last_not_of(s, off);
}

size_t FWWString::Find_Last_Not_Of(const FWWString & s, size_t off /*= npos*/) const
{
	return ((std::wstring*)_wstring)->find_last_not_of(*((std::wstring*)s._wstring), off);
}

FWWString& FWWString::Erase(size_t off /*= 0*/)
{
	((std::wstring*)_wstring)->erase(off);
	return *this;
}

FWWString& FWWString::Erase(size_t off, size_t count)
{
	((std::wstring*)_wstring)->erase(off, count);
	return *this;
}

void FWWString::Push_Back(wchar_t c)
{
	((std::wstring*)_wstring)->push_back(c);
}

void FWWString::Pop_Back()
{
	((std::wstring*)_wstring)->pop_back();
}

FWWString& FWWString::Replace(size_t off, size_t len, const wchar_t * s)
{
	((std::wstring*)_wstring)->replace(off, len, s);
	return *this;
}

FWWString& FWWString::Replace(size_t off, size_t len, const FWWString & s)
{
	((std::wstring*)_wstring)->replace(off, len, *((std::wstring*)s._wstring));
	return *this;
}

FWWString FWWString::Substr(size_t off /*= 0*/, size_t count /*= npos*/)
{
	std::wstring r = ((std::wstring*)_wstring)->substr(off, count);
	return FWWString(r.c_str(), r.size());
}


FW_NS_END