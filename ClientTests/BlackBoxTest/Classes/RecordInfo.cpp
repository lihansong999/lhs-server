#include "stdafx.h"
#include "RecordInfo.h"


static RecordInfo _RecordInfo;

RecordInfo::RecordInfo()
	:_lobbyPort(0)
{
	_path = this->GetModuleFileDirectory();
	_path.append("\\RecordInfo.json");
	FILE * fp = _fsopen(_path.c_str(), "rb", _SH_DENYWR);
	if (fp)
	{
		fseek(fp, 0, SEEK_END);
		long filesize = ftell(fp);
		fseek(fp, 0, SEEK_SET);
		if (filesize > 0L)
		{
			char * buffer = new char[filesize + 1];
			size_t c = fread(buffer, 1, filesize, fp);
			buffer[filesize] = '\0';
			rapidjson::GenericDocument<rapidjson::UTF8<> > recordDocument;
			recordDocument.Parse<rapidjson::kParseDefaultFlags, rapidjson::UTF8<> >(buffer);
			delete[] buffer;
			if (!recordDocument.HasParseError())
			{
				if (recordDocument.HasMember("Account"))
				{
					_account = recordDocument["Account"].GetString();
				}
				if (recordDocument.HasMember("Password"))
				{
					_password = recordDocument["Password"].GetString();
				}
				if (recordDocument.HasMember("Unionid"))
				{
					_unionid = recordDocument["Unionid"].GetString();
				}
				if (recordDocument.HasMember("WebHost"))
				{
					_webHost = recordDocument["WebHost"].GetString();
				}
				if (recordDocument.HasMember("LobbyHost"))
				{
					_lobbyHost = recordDocument["LobbyHost"].GetString();
				}
				if (recordDocument.HasMember("LobbyPort"))
				{
					_lobbyPort = recordDocument["LobbyPort"].GetInt();
				}
			}
		}
		fclose(fp);
	}
}

RecordInfo::~RecordInfo()
{

}

RecordInfo * RecordInfo::GetInstance()
{
	return &_RecordInfo;
}

std::string RecordInfo::GetModuleFileName()
{
	char buffer[1024/*MAX_PATH*/] = { 0 };
	GetModuleFileNameA(NULL, buffer, 1024/*MAX_PATH*/);
	return buffer;
}

std::string RecordInfo::GetModuleFileDirectory()
{
	char buffer[1024/*MAX_PATH*/] = { 0 };
	DWORD r = GetModuleFileNameA(NULL, buffer, 1024/*MAX_PATH*/);
	if (r > 0)
	{
		for (int i = (int)r; i >= 0; i--)
		{
			if (buffer[i] == '\\')
			{
				buffer[i] = '\0';
				break;
			}
		}
	}
	return buffer;
}

void RecordInfo::Save_Account(const std::string & var)
{
	if (_account.compare(var) != 0)
	{
		_account = var;
		_save();
	}
}

std::string RecordInfo::Read_Account()
{
	return _account;
}

void RecordInfo::Save_Password(const std::string & var)
{
	if (_password.compare(var) != 0)
	{
		_password = var;
		_save();
	}
}

std::string RecordInfo::Read_Password()
{
	return _password;
}

void RecordInfo::Save_Unionid(const std::string & var)
{
	if (_unionid.compare(var) != 0)
	{
		_unionid = var;
		_save();
	}
}

std::string RecordInfo::Read_Unionid()
{
	return _unionid;
}

void RecordInfo::Save_WebHost(const std::string & var)
{
	if (_webHost.compare(var) != 0)
	{
		_webHost = var;
		_save();
	}
}

std::string RecordInfo::Read_WebHost()
{
	return _webHost;
}

void RecordInfo::Save_LobbyHost(const std::string & var)
{
	if (_lobbyHost.compare(var) != 0)
	{
		_lobbyHost = var;
		_save();
	}
}

std::string RecordInfo::Read_LobbyHost()
{
	return _lobbyHost;
}

void RecordInfo::Save_LobbyPort(int var)
{
	if (_lobbyPort != var)
	{
		_lobbyPort = var;
		_save();
	}
}

int RecordInfo::Read_LobbyPort()
{
	return _lobbyPort;
}

void RecordInfo::_save()
{
	rapidjson::StringBuffer s;
	rapidjson::Writer<rapidjson::StringBuffer> writer(s);
	writer.StartObject();
	writer.Key("Account");
	writer.String(_account.c_str(), (rapidjson::SizeType)_account.size());
	writer.Key("Password");
	writer.String(_password.c_str());
	writer.Key("Unionid");
	writer.String(_unionid.c_str());
	writer.Key("WebHost");
	writer.String(_webHost.c_str());
	writer.Key("LobbyHost");
	writer.String(_lobbyHost.c_str());
	writer.Key("LobbyPort");
	writer.Int(_lobbyPort);
	writer.EndObject();
	FILE * fp = _fsopen(_path.c_str(), "wb", _SH_DENYWR);
	if (fp)
	{
		fwrite(s.GetString(), 1, s.GetSize(), fp);
		fclose(fp);
	}
}