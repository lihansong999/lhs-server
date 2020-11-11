#include "FWBase64.h"
#include "FWTools.h"

FW_NS_BEGIN


static unsigned char _ALPHABET[] = {
	0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
	0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50,
	0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
	0x59, 0x5a, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
	0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
	0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
	0x77, 0x78, 0x79, 0x7a, 0x30, 0x31, 0x32, 0x33,
	0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x2b, 0x2f,
};

static unsigned char _DECODETABLE[] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3e, 0xff, 0xff, 0xff, 0x3f,
	0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
	0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
	0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

static unsigned char _ALPHABET_URI[] = {
	0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48,
	0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50,
	0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58,
	0x59, 0x5a, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
	0x67, 0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e,
	0x6f, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76,
	0x77, 0x78, 0x79, 0x7a, 0x30, 0x31, 0x32, 0x33,
	0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x2d, 0x5f,
};

static unsigned char _DECODETABLE_URI[] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3e, 0xff, 0xff,
	0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e,
	0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0xff, 0xff, 0xff, 0xff, 0x3f,
	0xff, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
	0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x30, 0x31, 0x32, 0x33, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
};

static void _B64Encode(const char * in, int in_len, FWString & out)
{
	unsigned int bits = 0;
	int char_count = 0;
	for (int in_index = 0; in_index < in_len; in_index++)
	{
		bits |= (unsigned char)in[in_index];
		char_count++;
		if (char_count == 3)
		{
			out.Push_Back((char)(_ALPHABET[(bits >> 18) & 0x3f]));
			out.Push_Back((char)(_ALPHABET[(bits >> 12) & 0x3f]));
			out.Push_Back((char)(_ALPHABET[(bits >> 6) & 0x3f]));
			out.Push_Back((char)(_ALPHABET[bits & 0x3f]));
			bits = 0;
			char_count = 0;
		}
		else
		{
			bits <<= 8;
		}
	}
	if (char_count > 0)
	{
		if (char_count == 1) 
		{
			bits <<= 8;
		}
		out.Push_Back((char)(_ALPHABET[(bits >> 18) & 0x3f]));
		out.Push_Back((char)(_ALPHABET[(bits >> 12) & 0x3f]));
		if (char_count > 1) 
		{
			out.Push_Back((char)(_ALPHABET[(bits >> 6) & 0x3f]));
		}
		else 
		{
			out.Push_Back('=');
		}
		out.Push_Back('=');
	}
}

static bool _B64Decode(const char * in, int in_len, char * out, int * out_len)
{
	*out_len = 0;
	int bits = 0;
	int char_count = 0;
	for (int in_index = 0; in_index < in_len; in_index++)
	{
		char c = in[in_index];
		if (c == '=')
		{
			switch (char_count) 
			{
			case 1:
			{
				return false;
			}
				break;
			case 2:
			{				
				out[(*out_len)++] = (bits >> 10);
			}
				break;
			case 3:
			{
				out[(*out_len)++] = (bits >> 16);
				out[(*out_len)++] = ((bits >> 8) & 0xff);
			}
				break;
			default:
				break;
			}
			bits = 0;
			char_count = 0;
			continue;
		}
		if (c == '\0')
		{
			if (in_index == in_len - 1)
			{
				break;
			}
			else
			{
				return false;
			}
		}
		if (_DECODETABLE[c] == 255)
		{
			return false;
		}
		bits |= _DECODETABLE[c];
		char_count++;
		if (char_count == 4) 
		{
			out[(*out_len)++] = (bits >> 16);
			out[(*out_len)++] = ((bits >> 8) & 0xff);
			out[(*out_len)++] = (bits & 0xff);
			bits = 0;
			char_count = 0;
		}
		else 
		{
			bits <<= 6;
		}
	}
	switch (char_count)
	{
	case 1:
	{
		return false;
	}
		break;
	case 2:
	{
		out[(*out_len)++] = (bits >> 10);
	}
		break;
	case 3:
	{
		out[(*out_len)++] = (bits >> 16);
		out[(*out_len)++] = ((bits >> 8) & 0xff);
	}
		break;
	default:
		break;
	}
	return true;
}

static int _B64EnBound(int size)
{
	return (size + 2) / 3 * 4 + 1;
}

static int _B64DeBound(int size)
{
	return (size + 3) / 4 * 3;
}

//url

static void _URLB64Push(FWString & out, char c)
{
	switch (c)
	{
	case '+':
		out.Append("%2B");
		break;
	case '/':
		out.Append("%2F");
		break;
	default:
		out.Push_Back(c);
		break;
	}
}

static void _URLB64Encode(const char * in, int in_len, FWString & out)
{
	unsigned int bits = 0;
	int char_count = 0;
	for (int in_index = 0; in_index < in_len; in_index++)
	{
		bits |= (unsigned char)in[in_index];
		char_count++;
		if (char_count == 3)
		{
			_URLB64Push(out, (char)(_ALPHABET[(bits >> 18) & 0x3f]));
			_URLB64Push(out, (char)(_ALPHABET[(bits >> 12) & 0x3f]));
			_URLB64Push(out, (char)(_ALPHABET[(bits >> 6) & 0x3f]));
			_URLB64Push(out, (char)(_ALPHABET[bits & 0x3f]));
			bits = 0;
			char_count = 0;
		}
		else
		{
			bits <<= 8;
		}
	}
	if (char_count > 0)
	{
		if (char_count == 1)
		{
			bits <<= 8;
		}
		_URLB64Push(out, (char)(_ALPHABET[(bits >> 18) & 0x3f]));
		_URLB64Push(out, (char)(_ALPHABET[(bits >> 12) & 0x3f]));
		if (char_count > 1)
		{
			_URLB64Push(out, (char)(_ALPHABET[(bits >> 6) & 0x3f]));
		}
		else
		{
			out.Append("%3D");
		}
		out.Append("%3D");
	}
}

static bool _URLB64Decode(const char * in, int in_len, char * out, int * out_len)
{
	*out_len = 0;
	int bits = 0;
	int char_count = 0;
	for (int in_index = 0; in_index < in_len; in_index++)
	{
		char c = in[in_index];
		if (c == '%')
		{
			if (in_index + 2 >= in_len)
			{
				return false;
			}
			char tempChar[] = { in[in_index + 1],in[in_index + 2],'\0' };
			in_index += 2;
			if (strcmp(tempChar,"2B") == 0)
			{
				c = '+';
			}
			else if (strcmp(tempChar, "2F") == 0)
			{
				c = '/';
			}
			else if (strcmp(tempChar, "3D") == 0)
			{
				c = '=';
			}
			else if (strcmp(tempChar, "2b") == 0)
			{
				c = '+';
			}
			else if (strcmp(tempChar, "2f") == 0)
			{
				c = '/';
			}
			else if (strcmp(tempChar, "3d") == 0)
			{
				c = '=';
			}
			else
			{
				return false;
			}
		}
		if (c == '=')
		{
			switch (char_count)
			{
			case 1:
			{
				return false;
			}
				break;
			case 2:
			{
				out[(*out_len)++] = (bits >> 10);
			}
				break;
			case 3:
			{
				out[(*out_len)++] = (bits >> 16);
				out[(*out_len)++] = ((bits >> 8) & 0xff);
			}
				break;
			default:
				break;
			}
			bits = 0;
			char_count = 0;
			continue;
		}
		if (c == '\0')
		{
			if (in_index == in_len - 1)
			{
				break;
			}
			else
			{
				return false;
			}
		}
		if (_DECODETABLE[c] == 255)
		{
			return false;
		}
		bits |= _DECODETABLE[c];
		char_count++;
		if (char_count == 4)
		{
			out[(*out_len)++] = (bits >> 16);
			out[(*out_len)++] = ((bits >> 8) & 0xff);
			out[(*out_len)++] = (bits & 0xff);
			bits = 0;
			char_count = 0;
		}
		else
		{
			bits <<= 6;
		}
	}
	switch (char_count)
	{
	case 1:
	{
		return false;
	}
		break;
	case 2:
	{
		out[(*out_len)++] = (bits >> 10);
	}
		break;
	case 3:
	{
		out[(*out_len)++] = (bits >> 16);
		out[(*out_len)++] = ((bits >> 8) & 0xff);
	}
		break;
	default:
		break;
	}
	return true;
}

static int _URLB64EnBound(int size)
{
	return (int)(((double)_B64EnBound(size)) * 1.2);
}

static int _URLB64DeBound(int size)
{
	return _B64DeBound(size);
}

//uri

static void _URIB64Encode(const char * in, int in_len, FWString & out)
{
	unsigned int bits = 0;
	int char_count = 0;
	for (int in_index = 0; in_index < in_len; in_index++)
	{
		bits |= (unsigned char)in[in_index];
		char_count++;
		if (char_count == 3)
		{
			out.Push_Back((char)(_ALPHABET_URI[(bits >> 18) & 0x3f]));
			out.Push_Back((char)(_ALPHABET_URI[(bits >> 12) & 0x3f]));
			out.Push_Back((char)(_ALPHABET_URI[(bits >> 6) & 0x3f]));
			out.Push_Back((char)(_ALPHABET_URI[bits & 0x3f]));
			bits = 0;
			char_count = 0;
		}
		else
		{
			bits <<= 8;
		}
	}
	if (char_count > 0)
	{
		if (char_count == 1)
		{
			bits <<= 8;
		}
		out.Push_Back((char)(_ALPHABET_URI[(bits >> 18) & 0x3f]));
		out.Push_Back((char)(_ALPHABET_URI[(bits >> 12) & 0x3f]));
		if (char_count > 1)
		{
			out.Push_Back((char)(_ALPHABET_URI[(bits >> 6) & 0x3f]));
		}
		else
		{
			out.Push_Back('=');
		}
		out.Push_Back('=');
	}
}

static bool _URIB64Decode(const char * in, int in_len, char * out, int * out_len)
{
	*out_len = 0;
	int bits = 0;
	int char_count = 0;
	for (int in_index = 0; in_index < in_len; in_index++)
	{
		char c = in[in_index];
		if (c == '=')
		{
			switch (char_count)
			{
			case 1:
			{
				return false;
			}
				break;
			case 2:
			{
				out[(*out_len)++] = (bits >> 10);
			}
				break;
			case 3:
			{
				out[(*out_len)++] = (bits >> 16);
				out[(*out_len)++] = ((bits >> 8) & 0xff);
			}
				break;
			default:
				break;
			}
			bits = 0;
			char_count = 0;
			continue;
		}
		if (c == '\0')
		{
			if (in_index == in_len - 1)
			{
				break;
			}
			else
			{
				return false;
			}
		}
		if (_DECODETABLE_URI[c] == 255)
		{
			return false;
		}
		bits |= _DECODETABLE_URI[c];
		char_count++;
		if (char_count == 4)
		{
			out[(*out_len)++] = (bits >> 16);
			out[(*out_len)++] = ((bits >> 8) & 0xff);
			out[(*out_len)++] = (bits & 0xff);
			bits = 0;
			char_count = 0;
		}
		else
		{
			bits <<= 6;
		}
	}
	switch (char_count)
	{
	case 1:
	{
		return false;
	}
		break;
	case 2:
	{
		out[(*out_len)++] = (bits >> 10);
	}
		break;
	case 3:
	{
		out[(*out_len)++] = (bits >> 16);
		out[(*out_len)++] = ((bits >> 8) & 0xff);
	}
		break;
	default:
		break;
	}
	return true;
}

static int _URIB64EnBound(int size)
{
	return (size + 2) / 3 * 4 + 1;
}

static int _URIB64DeBound(int size)
{
	return (size + 3) / 4 * 3;
}

FWString FWBase64Encode(const FWData & data)
{
	return FWBase64Encode(data.GetPointer(), data.GetSize());
}

FWString FWBase64Encode(const char * data, size_t size)
{
	FWString ret;
	ret.Reserve(_B64EnBound((int)size));
	_B64Encode(data, (int)size, ret);
	return ret;
}

FWData FWBase64Decode(const FWString & b64)
{
	return FWBase64Decode(b64.C_Str(), b64.Size());
}

FWData FWBase64Decode(const char * b64)
{
	return FWBase64Decode(b64, strlen(b64));
}

FWData FWBase64Decode(const char * b64, size_t b64Length)
{
	FWData ret;
	int dataSize = 0;
	const int dataBound = _B64DeBound((int)b64Length);
	if (dataBound <= 0)
	{
		return ret;
	}
	char * buffer = (char*)FW_MALLOC(dataBound);
	if (!_B64Decode(b64, (int)b64Length, buffer, &dataSize))
	{
		FW_FREE(buffer);
		return ret;
	}
	ret.SetIn(buffer, dataSize);
	return ret;
}

FWString FWURLBase64Encode(const FWData & data)
{
	return FWURLBase64Encode(data.GetPointer(), data.GetSize());
}

FWString FWURLBase64Encode(const char * data, size_t size)
{
	FWString ret;
	ret.Reserve(_URLB64EnBound((int)size));
	_URLB64Encode(data, (int)size, ret);
	return ret;
}

FWData FWURLBase64Decode(const FWString & urlb64)
{
	return FWURLBase64Decode(urlb64.C_Str(), urlb64.Size());
}

FWData FWURLBase64Decode(const char * urlb64)
{
	return FWURLBase64Decode(urlb64, strlen(urlb64));
}

FWData FWURLBase64Decode(const char * urlb64, size_t urlb64Length)
{
	FWData ret;
	int dataSize = 0;
	const int dataBound = _URLB64DeBound((int)urlb64Length);
	if (dataBound <= 0)
	{
		return ret;
	}
	char * buffer = (char*)FW_MALLOC(dataBound);
	if (!_URLB64Decode(urlb64, (int)urlb64Length, buffer, &dataSize))
	{
		FW_FREE(buffer);
		return ret;
	}
	ret.SetIn(buffer, dataSize);
	return ret;
}

FWString FWURIBase64Encode(const FWData & data)
{
	return FWURIBase64Encode(data.GetPointer(), data.GetSize());
}

FWString FWURIBase64Encode(const char * data, size_t size)
{
	FWString ret;
	ret.Reserve(_URIB64EnBound((int)size));
	_URIB64Encode(data, (int)size, ret);
	return ret;
}

FWData FWURIBase64Decode(const FWString & urib64)
{
	return FWURIBase64Decode(urib64.C_Str(), urib64.Size());
}

FWData FWURIBase64Decode(const char * urib64)
{
	return FWURIBase64Decode(urib64, strlen(urib64));
}

FWData FWURIBase64Decode(const char * urib64, size_t urib64Length)
{
	FWData ret;
	int dataSize = 0;
	const int dataBound = _URIB64DeBound((int)urib64Length);
	if (dataBound <= 0)
	{
		return ret;
	}
	char * buffer = (char*)FW_MALLOC(dataBound);
	if (!_URIB64Decode(urib64, (int)urib64Length, buffer, &dataSize))
	{
		FW_FREE(buffer);
		return ret;
	}
	ret.SetIn(buffer, dataSize);
	return ret;
}

void FWBase64NoPadding(FWString * b64)
{
	if (b64->Size() == 0)
		return;
	size_t count = 0;
	for (size_t off = b64->Size() - 1; off >= 0; off--)
	{
		if ((b64->C_Str())[off] != '=')
			break;
		count++;
	}
	if (count > 0)
		b64->Replace(b64->Size() - count, count, "");
}


FW_NS_END