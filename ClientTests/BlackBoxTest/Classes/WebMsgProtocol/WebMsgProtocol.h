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
	int					Code;	// 0�ɹ���1�Ƿ����˺Ż����룬2�Ƿ����ǳƻ��Ա�3�˺��Ѵ���
	Message::MSGString	Tips;	// �û���ʾ���
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
	int					Code;	// 0�ɹ���1�Ƿ���unionid��2�Ƿ����ǳƻ��Ա�
	Message::MSGString	Tips;	// �û���ʾ���
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