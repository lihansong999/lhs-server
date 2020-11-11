#if defined(MESSAGE_SERVER)

#include "CenterProtocol.h"

namespace MSG_NAMESPACE {
	namespace Center {


		LoginReq::LoginReq()
		{
			ServerID = 0;
		}

		void LoginReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_INT(writer, ServerID);
		}

		bool LoginReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_INT(genericValue, ServerID);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		LoginRes::LoginRes()
		{
			IsSucceed = false;
		}

		void LoginRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_BOOL(writer, IsSucceed);
		}

		bool LoginRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_BOOL(genericValue, IsSucceed);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		ForwardClosePlayerSocketReq::ForwardClosePlayerSocketReq()
		{
			Type = FOT_UNKNOWN;
			TargetServerID = 0;
			PlayerID = 0;
			NetType = 0;
			NetIndex = 0;
			NetActivityID = 0;
		}

		void ForwardClosePlayerSocketReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_ENUM32(writer, Type);
			JSON_WRITE_INT(writer, TargetServerID);
			JSON_WRITE_INT64(writer, PlayerID);
			JSON_WRITE_INT(writer, NetType);
			JSON_WRITE_UINT(writer, NetIndex);
			JSON_WRITE_INT64(writer, NetActivityID);
		}

		bool ForwardClosePlayerSocketReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_ENUM32(genericValue, Type, ForceOfflineType);
			JSON_READ_INT(genericValue, TargetServerID);
			JSON_READ_INT64(genericValue, PlayerID);
			JSON_READ_INT(genericValue, NetType);
			JSON_READ_UINT(genericValue, NetIndex);
			JSON_READ_INT64(genericValue, NetActivityID);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		ForwardClosePlayerSocketNote::ForwardClosePlayerSocketNote()
		{
			Type = FOT_UNKNOWN;
			PlayerID = 0;
			NetType = 0;
			NetIndex = 0;
			NetActivityID = 0;
		}

		void ForwardClosePlayerSocketNote::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_ENUM32(writer, Type);
			JSON_WRITE_INT64(writer, PlayerID);
			JSON_WRITE_INT(writer, NetType);
			JSON_WRITE_UINT(writer, NetIndex);
			JSON_WRITE_INT64(writer, NetActivityID);
		}

		bool ForwardClosePlayerSocketNote::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_ENUM32(genericValue, Type, ForceOfflineType);
			JSON_READ_INT64(genericValue, PlayerID);
			JSON_READ_INT(genericValue, NetType);
			JSON_READ_UINT(genericValue, NetIndex);
			JSON_READ_INT64(genericValue, NetActivityID);

			return true;
		}


	}
}


#endif