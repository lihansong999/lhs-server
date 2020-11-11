#ifndef __FRAMEWORK_BASE64_H__
#define __FRAMEWORK_BASE64_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "FWData.h"
#include "FWString.h"

FW_NS_BEGIN

//rfc4648


extern FWString FW_DLL FWBase64Encode(const FWData & data);
extern FWString FW_DLL FWBase64Encode(const char * data, size_t size);

extern FWData FW_DLL FWBase64Decode(const FWString & b64);
extern FWData FW_DLL FWBase64Decode(const char * b64);
extern FWData FW_DLL FWBase64Decode(const char * b64, size_t b64Length);

//'+'->"%2B"、'/'->"%2F"、'='->"%3D"
extern FWString FW_DLL FWURLBase64Encode(const FWData & data);
extern FWString FW_DLL FWURLBase64Encode(const char * data, size_t size);

//"%2B"->'+'、"%2F"->'/'、"%3D"->'='��ignore case
extern FWData FW_DLL FWURLBase64Decode(const FWString & urlb64);
extern FWData FW_DLL FWURLBase64Decode(const char * urlb64);
extern FWData FW_DLL FWURLBase64Decode(const char * urlb64, size_t urlb64Length);

//'+'->'-'、'/'->'_'、'='->"="
extern FWString FW_DLL FWURIBase64Encode(const FWData & data);
extern FWString FW_DLL FWURIBase64Encode(const char * data, size_t size);

//"-"->'+'、"_"->'/'、"="->'='
extern FWData FW_DLL FWURIBase64Decode(const FWString & urib64);
extern FWData FW_DLL FWURIBase64Decode(const char * urib64);
extern FWData FW_DLL FWURIBase64Decode(const char * urib64, size_t urib64Length);


extern void FW_DLL FWBase64NoPadding(FWString * b64);


FW_NS_END


#endif //!__FRAMEWORK_BASE64_H__