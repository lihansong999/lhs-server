#ifndef __MESSAGE_LOGICALPROTOCOL_H__
#define __MESSAGE_LOGICALPROTOCOL_H__

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Logical {


		/*
		MainID范围
		[300000, 399999]
		*/


		//登录
		const int MSG_MAIN_LOGIN = 300001;
		const int MSG_ASS_LOGIN_DYNAMIC_PASSWORD = 1;

		class MSG_DLL LoginReq : public MsgBodyBase
		{
		public:
			LoginReq();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			PLAYERID_T	PlayerID;
			MSGString	DynaPwd;
		};

		class MSG_DLL LoginRes : public MsgBodyBase
		{
		public:
			LoginRes();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			int LogicalServerStationID;	//为0时可发送加入比赛消息
		};


		//比赛消息
		const int MSG_MAIN_MATCH = 300002;

		const int MSG_ASS_MATCH_REQ_ADD = 1;	//加入比赛
		class MSG_DLL AddMatchReq : public MsgBodyBase
		{
		public:
			AddMatchReq();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:

		};

		class MSG_DLL AddMatchRes : public MsgBodyBase
		{
		public:
			AddMatchRes();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			int LogicalServerStationID;
		};

		const int MSG_ASS_MATCH_REQ_QUIT = 2;	//退出比赛
		class MSG_DLL QuitMatchReq : public MsgBodyBase
		{
		public:
			QuitMatchReq();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:

		};

		class MSG_DLL QuitMatchRes : public MsgBodyBase
		{
		public:
			QuitMatchRes();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:

		};


	}
}


#endif //!__MESSAGE_LOGICALPROTOCOL_H__