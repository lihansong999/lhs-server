#ifndef __BASE64_H__
#define __BASE64_H__

#include "Local.h"
#include "Data.h"

extern Message::MSGString Base64Encode(const Data & data);
extern Message::MSGString Base64Encode(const char * data, size_t size);

extern Data Base64Decode(const Message::MSGString & b64);
extern Data Base64Decode(const char * b64);
extern Data Base64Decode(const char * b64, size_t b64Length);

//'+'->"%2B"、'/'->"%2F"、'='->"%3D"
extern Message::MSGString URLBase64Encode(const Data & data);
extern Message::MSGString URLBase64Encode(const char * data, size_t size);

//"%2B"->'+'、"%2F"->'/'、"%3D"->'='��ignore case
extern Data URLBase64Decode(const Message::MSGString & urlb64);
extern Data URLBase64Decode(const char * urlb64);
extern Data URLBase64Decode(const char * urlb64, size_t urlb64Length);

//'+'->'-'、'/'->'_'、'='->"="
extern Message::MSGString URIBase64Encode(const Data & data);
extern Message::MSGString URIBase64Encode(const char * data, size_t size);

//"-"->'+'、"_"->'/'、"="->'='
extern Data URIBase64Decode(const Message::MSGString & urib64);
extern Data URIBase64Decode(const char * urib64);
extern Data URIBase64Decode(const char * urib64, size_t urib64Length);


extern void Base64NoPadding(Message::MSGString * b64);


#endif //!__BASE64_H__