#include "FWTools.h"
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/aes.h>
#include "../ThirdParty/libcurl/include/curl.h"
#include "../ThirdParty/zlib/include/zlib.h"


FW_NS_BEGIN


void * FW_MALLOC(size_t size)
{
	return malloc(size);
}

void * FW_REALLOC(void * block, size_t size)
{
	return realloc(block, size);
}

void FW_FREE(void * pointer)
{
	free(pointer);
}

long long FW_TIME()
{
	SYSTEMTIME sysTime;
	GetLocalTime(&sysTime);
	FILETIME fileTime;
	SystemTimeToFileTime(&sysTime, &fileTime);
	long long s = (((long long)((unsigned int)fileTime.dwHighDateTime)) << 32 & 0xffffffff00000000) | (((long long)((unsigned int)fileTime.dwLowDateTime)) & 0x00000000ffffffff);
	return s / 10000LL;
}

unsigned int FW_NumberOfProcessors()
{
	//return std::thread::hardware_concurrency();
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);
	return (unsigned int)sysInfo.dwNumberOfProcessors;
}

void FWMD5(const char * data, size_t size, char * out_md5)
{
	MD5_CTX st;
	MD5_Init(&st);
	MD5_Update(&st, data, size);
	MD5_Final((unsigned char *)out_md5, &st);
}

void FWMD5_STRING(const char * data, size_t size, char * out_md5_stringBuf)
{
	unsigned char buf[FW_MD5_LENGTH];
	FWMD5(data, size, (char*)buf);
	for (int i = 0; i < sizeof(buf); i++)
	{
		int offset = i * 2;
		sprintf_s(out_md5_stringBuf + offset, 3, "%02x", buf[i]);
	}
	out_md5_stringBuf[FW_MD5_STRBUF_LENGTH - 1] = '\0';
}

void FWSHA1(const char * data, size_t size, char * out_sha1)
{
	SHA_CTX st;
	SHA1_Init(&st);
	SHA1_Update(&st, data, size);
	SHA1_Final((unsigned char *)out_sha1, &st);
}

void FWSHA1_STRING(const char * data, size_t size, char * out_sha1_stringBuf)
{
	unsigned char buf[FW_SHA1_LENGTH];
	FWSHA1(data, size, (char*)buf);
	for (int i = 0; i < sizeof(buf); i++)
	{
		int offset = i * 2;
		sprintf_s(out_sha1_stringBuf + offset, 3, "%02x", buf[i]);
	}
	out_sha1_stringBuf[FW_SHA1_STRBUF_LENGTH - 1] = '\0';
}

void FWSHA256(const char * data, size_t size, char * out_sha256)
{
	SHA256_CTX st;
	SHA256_Init(&st);
	SHA256_Update(&st, data, size);
	SHA256_Final((unsigned char *)out_sha256, &st);
}

void FWSHA256_STRING(const char * data, size_t size, char * out_sha256_stringBuf)
{
	unsigned char buf[FW_SHA256_LENGTH];
	FWSHA256(data, size, (char*)buf);
	for (int i = 0; i < sizeof(buf); i++)
	{
		int offset = i * 2;
		sprintf_s(out_sha256_stringBuf + offset, 3, "%02x", buf[i]);
	}
	out_sha256_stringBuf[FW_SHA256_STRBUF_LENGTH - 1] = '\0';
}

size_t FWAESPaddedSize(size_t size)
{
	return size + AES_BLOCK_SIZE - size % AES_BLOCK_SIZE;
}

bool FWAESEncrypt(const char * key, const int bits, const char * iv, char * data, size_t size, size_t * out_size)
{
	AES_KEY aes_key;
	if (AES_set_encrypt_key((const unsigned char *)key, bits, &aes_key) != 0)
		return false;
	char ivec[16];
	memcpy(ivec, iv, 16);
	size_t outSize = FWAESPaddedSize(size);
	size_t padding = outSize - size;
	memset(data + size, (int)padding, padding);
	AES_cbc_encrypt((unsigned char *)data, (unsigned char *)data, outSize, &aes_key, (unsigned char *)ivec, AES_ENCRYPT);
	if (out_size)
		*out_size = outSize;
	return true;
}

bool FWAESDecrypt(const char * key, const int bits, const char * iv, char * data, size_t size, size_t * out_size)
{
	if (size == 0 || size % 16 > 0)
		return false;
	AES_KEY aes_key;
	if (AES_set_decrypt_key((const unsigned char *)key, bits, &aes_key) != 0)
		return false;
	char ivec[16];
	memcpy(ivec, iv, 16);
	AES_cbc_encrypt((unsigned char *)data, (unsigned char *)data, size, &aes_key, (unsigned char *)ivec, AES_DECRYPT);
	size_t padding = (size_t)data[size - 1];
	size_t outSize = size - padding;
	if (out_size)
		*out_size = outSize;
	return true;
}


FW_NS_END
