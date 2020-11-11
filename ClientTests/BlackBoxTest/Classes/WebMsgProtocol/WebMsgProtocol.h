#ifndef __WEBMSGPROTOCOL_H__
#define __WEBMSGPROTOCOL_H__

#include "../Local.h"
#include "WebMsgBase.h"


class RegisterAccountReq : public WebMsgBase
{
public:
	RegisterAccountReq();
	virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
	virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
public:
	Message::MSGString	Account;
	Message::MSGString	Password;
	Message::MSGString	Nickname;
	int					Sex;
};

class RegisterAccountRes : public WebMsgBase
{
public:
	RegisterAccountRes();
	virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
	virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
public:
	int					Code;	// 0成功，1非法的账号或密码，2非法的昵称或性别，3账号已存在
	Message::MSGString	Tips;	// 用户提示语句
};

class RegisterUnionidReq : public WebMsgBase
{
public:
	RegisterUnionidReq();
	virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
	virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
public:
	Message::MSGString	Unionid;
	Message::MSGString	Nickname;
	int					Sex;
};

class RegisterUnionidRes : public WebMsgBase
{
public:
	RegisterUnionidRes();
	virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
	virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
public:
	int					Code;	// 0成功，1非法的unionid，2非法的昵称或性别
	Message::MSGString	Tips;	// 用户提示语句
};

class LobbyServerSelectionInfoRes : public WebMsgBase
{
public:
	LobbyServerSelectionInfoRes();
	virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
	virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
public:
	int					LobbyServerID;
	Message::MSGString	Address;
	int					TcpPort;
	int					WsPort;
};


#endif //!__WEBMSGPROTOCOL_H__