#include "SCTools.h"

SC_NS_BEGIN


bool AccountValidity(const char * account)
{
	std::string var = account;
	std::regex pattern("^[A-Za-z0-9]+$");
	return var.size() >= 6 && var.size() <= 12 && std::regex_match(var, pattern);
}

bool PasswordValidity(const char * password)
{
	std::string var = password;
	std::regex pattern("^[A-Za-z0-9]+$");
	return var.size() >= 6 && var.size() <= 12 && std::regex_match(var, pattern);
}

bool DynaPwdValidity(const char * dynaPwd)
{
	std::string var = dynaPwd;
	std::regex pattern("^[A-Fa-f0-9]+$");
	return var.size() == 32 && std::regex_match(var, pattern);
}

bool UnionidValidity(const char * unionid)
{
	std::string var = unionid;
	std::regex pattern("^[\x01-\x7F]+$");
	return var.size() >= 6 && var.size() <= 64 && std::regex_match(var, pattern);
}

bool NicknameValidity(const char * nickname)
{
	return nickname && strlen(nickname) <= 120;
}

bool SexValidity(int sex)
{
	return sex >= -128 && sex <= 127;
}


SC_NS_END