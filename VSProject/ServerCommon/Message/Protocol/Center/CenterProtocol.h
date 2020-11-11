#ifndef __MESSAGE_CENTERPROTOCOL_H__
#define __MESSAGE_CENTERPROTOCOL_H__
#if defined(MESSAGE_SERVER)

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Center {


		/*
		MainID范围
		[400000, 499999]
		*/
		

		//登录
		const int MSG_MAIN_LOGIN = 400001;
		const int MSG_ASS_LOGIN_LOBBY = 1;		//大厅服登录
		const int MSG_ASS_LOGIN_LOGICAL = 2;	//逻辑服登录

		class MSG_DLL LoginReq : public MsgBodyBase
		{
		public:
			LoginReq();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			int ServerID;
		};

		class MSG_DLL LoginRes : public MsgBodyBase
		{
		public:
			LoginRes();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			bool IsSucceed;
		};


		//转发
		const int MSG_MAIN_FORWARD = 400002;
		const int MSG_ASS_FORWARD_LOBBY_CLOSE_PLAYER_SOCKET = 1;		//让大厅服服关闭某个玩家套接字

		class MSG_DLL ForwardClosePlayerSocketReq : public MsgBodyBase
		{
		public:
			ForwardClosePlayerSocketReq();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			ForceOfflineType	Type;
			int					TargetServerID;
			PLAYERID_T			PlayerID;
			int					NetType;
			unsigned int		NetIndex;
			long long			NetActivityID;
		};

		class MSG_DLL ForwardClosePlayerSocketNote : public MsgBodyBase
		{
		public:
			ForwardClosePlayerSocketNote();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			ForceOfflineType	Type;
			PLAYERID_T			PlayerID;
			int					NetType;
			unsigned int		NetIndex;
			long long			NetActivityID;
		};


	}
}


#endif
#endif //!__MESSAGE_CENTERPROTOCOL_H__