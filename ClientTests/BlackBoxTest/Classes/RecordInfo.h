#pragma once

#include "Local.h"
#include "TypeDefine.h"

class RecordInfo
{
public:
	RecordInfo();
	~RecordInfo();

	static RecordInfo * GetInstance();

	std::string GetModuleFileName();
	std::string GetModuleFileDirectory();

	void Save_Account(const std::string & var);
	std::string Read_Account();

	void Save_Password(const std::string & var);
	std::string Read_Password();

	void Save_Unionid(const std::string & var);
	std::string Read_Unionid();

	void Save_WebHost(const std::string & var);
	std::string Read_WebHost();

	void Save_LobbyHost(const std::string & var);
	std::string Read_LobbyHost();

	void Save_LobbyPort(int var);
	int Read_LobbyPort();

private:
	void _save();

private:
	std::string _path;
	std::string _account;
	std::string _password;
	std::string _unionid;
	std::string _webHost;
	std::string _lobbyHost;
	int			_lobbyPort;
};