#include "LogicalProtocol.h"

namespace MSG_NAMESPACE {
	namespace Logical {


		LoginReq::LoginReq()
		{
			PlayerID = 0;
		}

		void LoginReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_INT64(writer, PlayerID);
			JSON_WRITE_STRING(writer, DynaPwd);
		}

		bool LoginReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_INT64(genericValue, PlayerID);
			JSON_READ_STRING(genericValue, DynaPwd);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		LoginRes::LoginRes()
		{

		}

		void LoginRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_INT(writer, LogicalServerStationID);
		}

		bool LoginRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_INT(genericValue, LogicalServerStationID);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		AddMatchReq::AddMatchReq()
		{

		}

		void AddMatchReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{

		}

		bool AddMatchReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		AddMatchRes::AddMatchRes()
		{

		}

		void AddMatchRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_INT(writer, LogicalServerStationID);
		}

		bool AddMatchRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_INT(genericValue, LogicalServerStationID);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		QuitMatchReq::QuitMatchReq()
		{

		}

		void QuitMatchReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{

		}

		bool QuitMatchReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		QuitMatchRes::QuitMatchRes()
		{

		}

		void QuitMatchRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{

		}

		bool QuitMatchRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			return true;
		}


	}
}