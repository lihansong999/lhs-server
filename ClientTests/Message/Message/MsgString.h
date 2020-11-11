#ifndef __MESSAGE_STRING_H__
#define __MESSAGE_STRING_H__

#include "MsgLocal.h"


namespace MSG_NAMESPACE {

	
	class MSG_DLL MSGString
	{
	public:
		MSGString();
		MSGString(const char * s);
		MSGString(const char * s, size_t len);
		MSGString(const MSGString & other);
		MSGString& operator=(const MSGString & other);
		MSGString& operator=(const char * s);
		MSGString(MSGString && other);
		MSGString& operator=(MSGString && other);
		~MSGString();

		void Reserve(size_t newcap);
		void Resize(size_t newsize);

		const char * C_Str() const;
		size_t Size() const;

		int Compare(const char * s) const;
		int Compare(const MSGString & s) const;

		MSGString& Assign(const char * s);
		MSGString& Assign(const char * s, size_t len);
		MSGString& Assign(const MSGString & s);

		MSGString& Append(const char * s);
		MSGString& Append(const char * s, size_t len);
		MSGString& Append(const MSGString & s);
		MSGString& operator+=(const char * s);
		MSGString& operator+=(const MSGString & s);

		size_t Find(const char * s, size_t off = 0) const;
		size_t Find(const MSGString & s, size_t off = 0) const;
		size_t Find_First_Of(const char * s, size_t off = 0) const;
		size_t Find_First_Of(const MSGString & s, size_t off = 0) const;
		size_t Find_First_Not_Of(const char * s, size_t off = 0) const;
		size_t Find_First_Not_Of(const MSGString & s, size_t off = 0) const;
		size_t RFind(const char * s, size_t off = npos) const;
		size_t RFind(const MSGString & s, size_t off = npos) const;
		size_t Find_Last_Of(const char * s, size_t off = npos) const;
		size_t Find_Last_Of(const MSGString & s, size_t off = npos) const;
		size_t Find_Last_Not_Of(const char * s, size_t off = npos) const;
		size_t Find_Last_Not_Of(const MSGString & s, size_t off = npos) const;

		MSGString& Erase(size_t off = 0);
		MSGString& Erase(size_t off, size_t count);

		void Push_Back(char c);
		void Pop_Back();

		MSGString& Replace(size_t off, size_t len, const char * s);
		MSGString& Replace(size_t off, size_t len, const MSGString & s);

		MSGString Substr(size_t off = 0, size_t count = npos);

	public:
		static const size_t npos;

	private:
		void * _string;
	};


}


#endif //!__MESSAGE_STRING_H__