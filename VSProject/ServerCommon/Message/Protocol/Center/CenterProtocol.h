#ifndef __MESSAGE_CENTERPROTOCOL_H__
#define __MESSAGE_CENTERPROTOCOL_H__
#if defined(MESSAGE_SERVER)

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Center {


		/*
		MainID��Χ
		[400000, 499999]
		*/
		

		//��¼
		const int MSG_MAIN_LOGIN = 400001;
		const int MSG_ASS_LOGIN_LOBBY = 1;		//��������¼
		const int MSG_ASS_LOGIN_LOGICAL = 2;	//�߼�����¼

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


		//ת��
		const int MSG_MAIN_FORWARD = 400002;
		const int MSG_ASS_FORWARD_LOBBY_CLOSE_PLAYER_SOCKET = 1;		//�ô��������ر�ĳ������׽���

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