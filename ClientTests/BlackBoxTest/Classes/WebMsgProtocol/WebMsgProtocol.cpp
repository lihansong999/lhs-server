#include "stdafx.h"
#include "WebMsgProtocol.h"


RegisterAccountReq::RegisterAccountReq()
{
	Sex = 0;
}

void RegisterAccountReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
{
	JSON_WRITE_STRING(writer, Account);
	JSON_WRITE_STRING(writer, Password);
	JSON_WRITE_STRING(writer, Nickname);
	JSON_WRITE_INT(writer, Sex);
}

bool RegisterAccountReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
{
	JSON_READ_STRING(genericValue, Account);
	JSON_READ_STRING(genericValue, Password);
	JSON_READ_STRING(genericValue, Nickname);
	JSON_READ_INT(genericValue, Sex);

	return true;
}

RegisterAccountRes::RegisterAccountRes()
{
	Code = 0;
}

void RegisterAccountRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
{
	JSON_WRITE_STRING(writer, Tips);
	JSON_WRITE_INT(writer, Code);
}

bool RegisterAccountRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
{
	JSON_READ_STRING(genericValue, Tips);
	JSON_READ_INT(genericValue, Code);

	return true;
}

RegisterUnionidReq::RegisterUnionidReq()
{
	Sex = 0;
}

void RegisterUnionidReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
{
	JSON_WRITE_STRING(writer, Unionid);
	JSON_WRITE_STRING(writer, Nickname);
	JSON_WRITE_INT(writer, Sex);
}

bool RegisterUnionidReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
{
	JSON_READ_STRING(genericValue, Unionid);
	JSON_READ_STRING(genericValue, Nickname);
	JSON_READ_INT(genericValue, Sex);

	return true;
}

RegisterUnionidRes::RegisterUnionidRes()
{
	Code = 0;
}

void RegisterUnionidRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
{
	JSON_WRITE_STRING(writer, Tips);
	JSON_WRITE_INT(writer, Code);
}

bool RegisterUnionidRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
{
	JSON_READ_STRING(genericValue, Tips);
	JSON_READ_INT(genericValue, Code);

	return true;
}

LobbyServerSelectionInfoRes::LobbyServerSelectionInfoRes()
{
	LobbyServerID = 0;
	TcpPort = 0;
	WsPort = 0;
}

void LobbyServerSelectionInfoRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
{
	JSON_WRITE_INT(writer, LobbyServerID);
	JSON_WRITE_STRING(writer, Address);
	JSON_WRITE_INT(writer, TcpPort);
	JSON_WRITE_INT(writer, WsPort);
}

bool LobbyServerSelectionInfoRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
{
	JSON_READ_INT(genericValue, LobbyServerID);
	JSON_READ_STRING(genericValue, Address);
	JSON_READ_INT(genericValue, TcpPort);
	JSON_READ_INT(genericValue, WsPort);

	return true;
}