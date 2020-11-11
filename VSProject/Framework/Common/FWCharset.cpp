#include "FWCharset.h"


FW_NS_BEGIN


static const char trailingBytesForUTF8[256] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, 3,3,3,3,3,3,3,3,4,4,4,4,5,5,5,5
};

typedef unsigned char   UTF8;

static bool isLegalUTF8(const UTF8 *source, int length) {
	UTF8 a;
	const UTF8 *srcptr = source + length;
	switch (length) {
	default: return false;
		/* Everything else falls through when "true"... */
	case 4: if ((a = (*--srcptr)) < 0x80 || a > 0xBF) return false;
	case 3: if ((a = (*--srcptr)) < 0x80 || a > 0xBF) return false;
	case 2: if ((a = (*--srcptr)) < 0x80 || a > 0xBF) return false;

		switch (*source) {
			/* no fall-through in this inner switch */
		case 0xE0: if (a < 0xA0) return false; break;
		case 0xED: if (a > 0x9F) return false; break;
		case 0xF0: if (a < 0x90) return false; break;
		case 0xF4: if (a > 0x8F) return false; break;
		default:   if (a < 0x80) return false;
		}

	case 1: if (*source >= 0x80 && *source < 0xC2) return false;
	}
	if (*source > 0xF4) return false;
	return true;
}

int FW_UTF8_STRLEN(const char * utf8)
{
	if (!utf8)
		return 0;
	const UTF8** source = (const UTF8**)(&utf8);
	const UTF8* sourceEnd = (const UTF8*)utf8 + strlen(utf8);
	int ret = 0;
	while (*source != sourceEnd) {
		int length = trailingBytesForUTF8[**source] + 1;
		if (length > sourceEnd - *source || !isLegalUTF8(*source, length))
			return 0;
		*source += length;
		++ret;
	}
	return ret;
}

#define COMMONLY_CHARACTERS_COUNT_MAX	100

FWWString FW_UTF8_2_UNICODE(const char * utf8)
{
	FWWString ret;
	if (utf8 == nullptr || strcmp(utf8, "") == 0)
		return ret;
	const int BUFF_SIZE = COMMONLY_CHARACTERS_COUNT_MAX;
	wchar_t wbuff[BUFF_SIZE];
	memset(wbuff, 0, sizeof(wchar_t) * BUFF_SIZE);
	int sizeInCharacters = ::MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wbuff, BUFF_SIZE);
	if (sizeInCharacters > 0) {
		ret.Append(wbuff);
		return ret;
	}
	if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
		return ret;
	sizeInCharacters = ::MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
	if (sizeInCharacters == 0)
		return ret;
	wchar_t * buff = new wchar_t[sizeInCharacters];
	memset(buff, 0, sizeof(wchar_t) * sizeInCharacters);
	::MultiByteToWideChar(CP_UTF8, 0, utf8, -1, buff, sizeInCharacters);
	ret.Append(buff);
	delete[] buff;
	return ret;
}

FWString FW_UNICODE_2_UTF8(const wchar_t * unicode)
{
	FWString ret;
	if (unicode == nullptr || wcscmp(unicode, L"") == 0)
		return ret;
	const int BUFF_SIZE = COMMONLY_CHARACTERS_COUNT_MAX * 3;
	char cbuff[BUFF_SIZE];
	memset(cbuff, 0, sizeof(char) * BUFF_SIZE);
	int sizeInBytes = ::WideCharToMultiByte(CP_UTF8, 0, unicode, -1, cbuff, BUFF_SIZE, NULL, NULL);
	if (sizeInBytes > 0) {
		ret.Append(cbuff);
		return ret;
	}
	if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
		return ret;
	sizeInBytes = ::WideCharToMultiByte(CP_UTF8, 0, unicode, -1, NULL, 0, NULL, NULL);
	if (sizeInBytes == 0)
		return ret;
	char * buff = new char[sizeInBytes];
	memset(buff, 0, sizeof(char) * sizeInBytes);
	::WideCharToMultiByte(CP_UTF8, 0, unicode, -1, buff, sizeInBytes, NULL, NULL);
	ret.Append(buff);
	delete[] buff;
	return ret;
}

FWString FW_UNICODE_2_ANSI(const wchar_t * unicode)
{
	FWString ret;
	if (unicode == nullptr || wcscmp(unicode, L"") == 0)
		return ret;
	const int BUFF_SIZE = COMMONLY_CHARACTERS_COUNT_MAX * 2;
	char cbuff[BUFF_SIZE];
	memset(cbuff, 0, sizeof(char) * BUFF_SIZE);
	int sizeInBytes = ::WideCharToMultiByte(CP_ACP, 0, unicode, -1, cbuff, BUFF_SIZE, NULL, NULL);
	if (sizeInBytes > 0) {
		ret.Append(cbuff);
		return ret;
	}
	if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
		return ret;
	sizeInBytes = ::WideCharToMultiByte(CP_ACP, 0, unicode, -1, NULL, 0, NULL, NULL);
	if (sizeInBytes == 0)
		return ret;
	char * buff = new char[sizeInBytes];
	memset(buff, 0, sizeof(char) * sizeInBytes);
	::WideCharToMultiByte(CP_ACP, 0, unicode, -1, buff, sizeInBytes, NULL, NULL);
	ret.Append(buff);
	delete[] buff;
	return ret;
}

FWWString FW_ANSI_2_UNICODE(const char * ansi)
{
	FWWString ret;
	if (ansi == nullptr || strcmp(ansi, "") == 0)
		return ret;
	const int BUFF_SIZE = COMMONLY_CHARACTERS_COUNT_MAX;
	wchar_t wbuff[BUFF_SIZE];
	memset(wbuff, 0, sizeof(wchar_t) * BUFF_SIZE);
	int sizeInCharacters = ::MultiByteToWideChar(CP_ACP, 0, ansi, -1, wbuff, BUFF_SIZE);
	if (sizeInCharacters > 0) {
		ret.Append(wbuff);
		return ret;
	}
	if (GetLastError() != ERROR_INSUFFICIENT_BUFFER)
		return ret;
	sizeInCharacters = ::MultiByteToWideChar(CP_ACP, 0, ansi, -1, NULL, 0);
	if (sizeInCharacters == 0)
		return ret;
	wchar_t * buff = new wchar_t[sizeInCharacters];
	memset(buff, 0, sizeof(wchar_t) * sizeInCharacters);
	::MultiByteToWideChar(CP_ACP, 0, ansi, -1, buff, sizeInCharacters);
	ret.Append(buff);
	delete[] buff;
	return ret;
}

FWString FW_UTF8_2_ANSI(const char * utf8)
{
	return FW_UNICODE_2_ANSI(FW_UTF8_2_UNICODE(utf8).C_Str());
}

FWString FW_ANSI_2_UTF8(const char * ansi)
{
	return FW_UNICODE_2_UTF8(FW_ANSI_2_UNICODE(ansi).C_Str());
}


FW_NS_END
