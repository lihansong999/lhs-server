#ifndef __MESSAGE_COMMONPROTOCOL_H__
#define __MESSAGE_COMMONPROTOCOL_H__

#include "../../MsgBase.h"
#include "../ProtocolTypeDef.h"


namespace MSG_NAMESPACE {
	namespace Common {


		/*
		MainID·¶Î§
		[100000, 199999]
		*/


		//²âÊÔ
		const int MSG_MAIN_TEST = 100001;

		const int MSG_ASS_TEST_HEARTBEAT = 1; //ÐÄÌø
		class MSG_DLL BeartbeatReq : public MsgBodyBase
		{
		public:
			BeartbeatReq();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:

		};

		class MSG_DLL BeartbeatRes : public MsgBodyBase
		{
		public:
			BeartbeatRes();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:

		};
		
		const int MSG_ASS_TEST_PROBE = 2; //Ì½²â
		class MSG_DLL ProbeReq : public MsgBodyBase
		{
		public:
			ProbeReq();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:
			MSGString	Check;
		};

		class MSG_DLL ProbeRes : public MsgBodyBase
		{
		public:
			ProbeRes();
			virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const override;
			virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) override;
		public:

		};


	}
}


#endif //!__MESSAGE_COMMONPROTOCOL_H__