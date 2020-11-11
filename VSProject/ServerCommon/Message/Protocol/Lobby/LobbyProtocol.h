#ifndef __MESSAGE_LOBBYPROTOCOL_H__
#define __MESSAGE_LOBBYPROTOCOL_H__

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Lobby {


		/*
		MainID��Χ
		[200000, 299999]
		*/


		//��¼
		const int MSG_MAIN_LOGIN = 200001;
		const int MSG_ASS_LOGIN_ACCOUNT = 1;
		const int MSG_ASS_LOGIN_UNIONID = 2;

		class MSG_DLL LoginReq : public MsgBodyBase
		{
		public:
			LoginReq();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			MSGString Account;
			MSGString Password;
			MSGString Unionid;
		};

		class MSG_DLL LoginRes : public MsgBodyBase
		{
		public:
			LoginRes();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			PLAYERID_T	PlayerID;
			MSGString	DynaPwd;
			int			LobbyServerID;
			int			LogicalServerID;	//����0˵���ڱ����У�����LogicalAddr,LogicalTcpPort,LogicalWsPort��������
			MSGString	LogicalAddr;
			int			LogicalTcpPort;
			int			LogicalWsPort;
		};


		//��ȡ�����Ϣ
		const int MSG_MAIN_REQUEST_PLAYERINFO = 200002;
		const int MSG_ASS_REQUEST_PLAYERINFO_WITH_PLAYERID = 1;

		class MSG_DLL PlayerInfoReq : public MsgBodyBase
		{
		public:
			PlayerInfoReq();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			PLAYERID_T	PlayerID;
		};

		class MSG_DLL PlayerInfoRes : public MsgBodyBase
		{
		public:
			PlayerInfoRes();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			PLAYERID_T		PlayerID;
			MSGString		Nickname;
			int				Sex;
			GOLDS_T			Golds;
			DIAMONDS_T		Diamonds;
			int				LobbyServerID;
			int				LogicalServerID;
		};


		//֪ͨ��Ϣ
		const int MSG_MAIN_NOTIFY = 200003;

		const int MSG_ASS_NOTIFY_FORCE_OFFLINE = 1;	//��ұ�ǿ������
		class MSG_DLL NotifyForceOfflineRes : public MsgBodyBase
		{
		public:
			NotifyForceOfflineRes();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			PLAYERID_T			PlayerID;
			ForceOfflineType	Type;
		};


		//������Ϣ
		const int MSG_MAIN_MATCH = 200004;

		const int MSG_ASS_MATCH_REQ_ADD_SVR = 1;	//������������
		class MSG_DLL MatchReq : public MsgBodyBase
		{
		public:
			MatchReq();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			
		};

		class MSG_DLL MatchRes : public MsgBodyBase
		{
		public:
			MatchRes();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			int			LogicalServerID;
			MSGString	LogicalAddr;
			int			LogicalTcpPort;
			int			LogicalWsPort;
		};


	}
}


#endif //!__MESSAGE_LOBBYPROTOCOL_H__