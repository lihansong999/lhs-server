#ifndef __WEBMSGBASE_H__
#define __WEBMSGBASE_H__

#include "../Local.h"


class WebMsgBase
{
public:
	WebMsgBase();
	virtual ~WebMsgBase();

	virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const = 0;

	virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) = 0;
};




#endif //!__WEBMSGBASE_H__