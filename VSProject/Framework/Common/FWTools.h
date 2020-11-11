#ifndef __FRAMEWORK_TOOLS_H__
#define __FRAMEWORK_TOOLS_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"

FW_NS_BEGIN

/*
生命周期自动执行回调的对象
*/
template <class TC, class TD>
class FWLifeCycleExecute
{
public:
	FWLifeCycleExecute(const TC & c, const TD & d)
		:_d(d)
	{
		if (c)
		{
			c();
		}
	}
	~FWLifeCycleExecute()
	{
		if (_d)
		{
			_d();
		}
	}
private:
	TD _d;
};

//malloc memory
extern FW_DLL void * FW_MALLOC(size_t size);

//realloc memory
extern FW_DLL void * FW_REALLOC(void * block, size_t size);

//free memory
extern void FW_DLL FW_FREE(void * pointer);

//millisecond intervals that have elapsed since 12:00 A.M. January 1, 1601 Coordinated Universal Time (UTC).
extern long long FW_DLL FW_TIME();

//取得CPU核心数量
extern unsigned int FW_DLL FW_NumberOfProcessors();

//md5
#if defined(MD5_DIGEST_LENGTH)
#define FW_MD5_LENGTH MD5_DIGEST_LENGTH
#else
#define FW_MD5_LENGTH 16
#endif
extern void FW_DLL FWMD5(const char * data, size_t size, char * out_md5);
#define FW_MD5_STRBUF_LENGTH (FW_MD5_LENGTH * 2 + 1)
extern void FW_DLL FWMD5_STRING(const char * data, size_t size, char * out_md5_stringBuf);

//sha1
#if defined(SHA_DIGEST_LENGTH)
#define FW_SHA1_LENGTH SHA_DIGEST_LENGTH
#else
#define FW_SHA1_LENGTH 20
#endif
extern void FW_DLL FWSHA1(const char * data, size_t size, char * out_sha1);
#define FW_SHA1_STRBUF_LENGTH (FW_SHA1_LENGTH * 2 + 1)
extern void FW_DLL FWSHA1_STRING(const char * data, size_t size, char * out_sha1_stringBuf);

//sha256
#if defined(SHA256_DIGEST_LENGTH)
#define FW_SHA256_LENGTH SHA256_DIGEST_LENGTH
#else
#define FW_SHA256_LENGTH 32
#endif
extern void FW_DLL FWSHA256(const char * data, size_t size, char * out_sha256);
#define FW_SHA256_STRBUF_LENGTH (FW_SHA256_LENGTH * 2 + 1)
extern void FW_DLL FWSHA256_STRING(const char * data, size_t size, char * out_sha256_stringBuf);

//aes cbc model, pkcs5padding
extern size_t FW_DLL FWAESPaddedSize(size_t size);
extern bool FW_DLL FWAESEncrypt(const char * key, const int bits, const char * iv, char * data, size_t size, size_t * out_size);
extern bool FW_DLL FWAESDecrypt(const char * key, const int bits, const char * iv, char * data, size_t size, size_t * out_size);


FW_NS_END


#endif //!__FRAMEWORK_TOOLS_H__