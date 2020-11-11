#include "CommonProtocol.h"

namespace MSG_NAMESPACE {
	namespace Common {


		BeartbeatReq::BeartbeatReq()
		{

		}

		void BeartbeatReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{

		}

		bool BeartbeatReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		BeartbeatRes::BeartbeatRes()
		{

		}

		void BeartbeatRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{

		}

		bool BeartbeatRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		ProbeReq::ProbeReq()
		{

		}

		void ProbeReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_STRING(writer, Check);
		}

		bool ProbeReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_STRING(genericValue, Check);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		ProbeRes::ProbeRes()
		{

		}

		void ProbeRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{

		}

		bool ProbeRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			return true;
		}


	}
}