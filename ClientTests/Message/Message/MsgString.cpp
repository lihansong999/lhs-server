#include "MsgString.h"


namespace MSG_NAMESPACE {


	const size_t MSGString::npos = std::string::npos;

	MSGString::MSGString()
	{
		_string = new std::string();
	}

	MSGString::MSGString(const char * s, size_t len)
	{
		_string = new std::string(s, len);
	}

	MSGString::MSGString(const char * s)
	{
		_string = new std::string(s);
	}

	MSGString::MSGString(const MSGString & other)
	{
		_string = new std::string(*((std::string*)other._string));
	}

	MSGString& MSGString::operator=(const char * s)
	{
		*((std::string*)_string) = s;
		return *this;
	}

	MSGString& MSGString::operator=(const MSGString & other)
	{
		*((std::string*)_string) = *((std::string*)other._string);
		return *this;
	}

	MSGString::MSGString(MSGString && other)
	{
		_string = new std::string(std::move(*((std::string*)other._string)));
	}

	MSGString& MSGString::operator=(MSGString && other)
	{
		*((std::string*)_string) = std::move(*((std::string*)other._string));
		return *this;
	}

	MSGString::~MSGString()
	{
		delete ((std::string*)_string);
	}

	void MSGString::Reserve(size_t newcap)
	{
		((std::string*)_string)->reserve(newcap);
	}

	void MSGString::Resize(size_t newsize)
	{
		((std::string*)_string)->resize(newsize);
	}

	const char * MSGString::C_Str() const
	{
		return ((std::string*)_string)->c_str();
	}

	size_t MSGString::Size() const
	{
		return ((std::string*)_string)->size();
	}

	int MSGString::Compare(const char * s) const
	{
		return ((std::string*)_string)->compare(s);
	}

	int MSGString::Compare(const MSGString & s) const
	{
		return ((std::string*)_string)->compare(*((std::string*)s._string));
	}

	MSGString& MSGString::Assign(const char * s)
	{
		((std::string*)_string)->assign(s);
		return *this;
	}

	MSGString& MSGString::Assign(const char * s, size_t len)
	{
		((std::string*)_string)->assign(s, len);
		return *this;
	}

	MSGString& MSGString::Assign(const MSGString & s)
	{
		((std::string*)_string)->assign(*((std::string*)s._string));
		return *this;
	}

	MSGString& MSGString::Append(const char * s)
	{
		((std::string*)_string)->append(s);
		return *this;
	}

	MSGString& MSGString::Append(const char * s, size_t len)
	{
		((std::string*)_string)->append(s, len);
		return *this;
	}

	MSGString& MSGString::Append(const MSGString & s)
	{
		((std::string*)_string)->append(*((std::string*)s._string));
		return *this;
	}

	MSGString& MSGString::operator+=(const char * s)
	{
		return this->Append(s);
	}

	MSGString& MSGString::operator+=(const MSGString & s)
	{
		return this->Append(s);
	}

	size_t MSGString::Find(const char * s, size_t off /*= 0*/) const
	{
		return ((std::string*)_string)->find(s, off);
	}

	size_t MSGString::Find(const MSGString & s, size_t off /*= 0*/) const
	{
		return ((std::string*)_string)->find(*((std::string*)s._string), off);
	}

	size_t MSGString::RFind(const char * s, size_t off /*= npos*/) const
	{
		return ((std::string*)_string)->rfind(s, off);
	}

	size_t MSGString::RFind(const MSGString & s, size_t off /*= npos*/) const
	{
		return ((std::string*)_string)->rfind(*((std::string*)s._string), off);
	}

	size_t MSGString::Find_First_Of(const char * s, size_t off /*= 0*/) const
	{
		return ((std::string*)_string)->find_first_of(s, off);
	}

	size_t MSGString::Find_First_Of(const MSGString & s, size_t off /*= 0*/) const
	{
		return ((std::string*)_string)->find_first_of(*((std::string*)s._string), off);
	}

	size_t MSGString::Find_First_Not_Of(const char * s, size_t off /*= 0*/) const
	{
		return ((std::string*)_string)->find_first_not_of(s, off);
	}

	size_t MSGString::Find_First_Not_Of(const MSGString & s, size_t off /*= 0*/) const
	{
		return ((std::string*)_string)->find_first_not_of(*((std::string*)s._string), off);
	}

	size_t MSGString::Find_Last_Of(const char * s, size_t off /*= npos*/) const
	{
		return ((std::string*)_string)->find_last_of(s, off);
	}

	size_t MSGString::Find_Last_Of(const MSGString & s, size_t off /*= npos*/) const
	{
		return ((std::string*)_string)->find_last_of(*((std::string*)s._string), off);
	}

	size_t MSGString::Find_Last_Not_Of(const char * s, size_t off /*= npos*/) const
	{
		return ((std::string*)_string)->find_last_not_of(s, off);
	}

	size_t MSGString::Find_Last_Not_Of(const MSGString & s, size_t off /*= npos*/) const
	{
		return ((std::string*)_string)->find_last_not_of(*((std::string*)s._string), off);
	}

	MSGString& MSGString::Erase(size_t off /*= 0*/)
	{
		((std::string*)_string)->erase(off);
		return *this;
	}

	MSGString& MSGString::Erase(size_t off, size_t count)
	{
		((std::string*)_string)->erase(off, count);
		return *this;
	}

	void MSGString::Push_Back(char c)
	{
		((std::string*)_string)->push_back(c);
	}

	void MSGString::Pop_Back()
	{
		((std::string*)_string)->pop_back();
	}

	MSGString& MSGString::Replace(size_t off, size_t len, const char * s)
	{
		((std::string*)_string)->replace(off, len, s);
		return *this;
	}

	MSGString& MSGString::Replace(size_t off, size_t len, const MSGString & s)
	{
		((std::string*)_string)->replace(off, len, *((std::string*)s._string));
		return *this;
	}

	MSGString MSGString::Substr(size_t off /*= 0*/, size_t count /*= npos*/)
	{
		std::string r = ((std::string*)_string)->substr(off, count);
		return MSGString(r.c_str(), r.size());
	}

	
}