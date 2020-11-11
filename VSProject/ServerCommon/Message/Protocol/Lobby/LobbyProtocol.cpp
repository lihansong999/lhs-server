#include "LobbyProtocol.h"

namespace MSG_NAMESPACE {
	namespace Lobby {


		LoginReq::LoginReq()
		{

		}

		void LoginReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_STRING(writer, Account);
			JSON_WRITE_STRING(writer, Password);
			JSON_WRITE_STRING(writer, Unionid);
		}

		bool LoginReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_STRING(genericValue, Account);
			JSON_READ_STRING(genericValue, Password);
			JSON_READ_STRING(genericValue, Unionid);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		LoginRes::LoginRes()
		{
			PlayerID = 0;
			LobbyServerID = 0;
			LogicalServerID = 0;
			LogicalTcpPort = 0;
			LogicalWsPort = 0;
		}

		void LoginRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_INT64(writer, PlayerID);
			JSON_WRITE_STRING(writer, DynaPwd);
			JSON_WRITE_INT(writer, LobbyServerID);
			JSON_WRITE_INT(writer, LogicalServerID);
			JSON_WRITE_STRING(writer, LogicalAddr);
			JSON_WRITE_INT(writer, LogicalTcpPort);
			JSON_WRITE_INT(writer, LogicalWsPort);
		}

		bool LoginRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_INT64(genericValue, PlayerID);
			JSON_READ_STRING(genericValue, DynaPwd);
			JSON_READ_INT(genericValue, LobbyServerID);
			JSON_READ_INT(genericValue, LogicalServerID);
			JSON_READ_STRING(genericValue, LogicalAddr);
			JSON_READ_INT(genericValue, LogicalTcpPort);
			JSON_READ_INT(genericValue, LogicalWsPort);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		PlayerInfoReq::PlayerInfoReq()
		{
			PlayerID = 0;
		}

		void PlayerInfoReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_INT64(writer, PlayerID);
		}

		bool PlayerInfoReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_INT64(genericValue, PlayerID);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		PlayerInfoRes::PlayerInfoRes()
		{
			PlayerID = 0;
			Sex = 0;
			Golds = 0;
			Diamonds = 0;
			LobbyServerID = 0;
			LogicalServerID = 0;
		}

		void PlayerInfoRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_INT64(writer, PlayerID);
			JSON_WRITE_STRING(writer, Nickname);
			JSON_WRITE_INT(writer, Sex);
			JSON_WRITE_INT64(writer, Golds);
			JSON_WRITE_INT64(writer, Diamonds);
			JSON_WRITE_INT(writer, LobbyServerID);
			JSON_WRITE_INT(writer, LogicalServerID);
		}

		bool PlayerInfoRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_INT64(genericValue, PlayerID);
			JSON_READ_STRING(genericValue, Nickname);
			JSON_READ_INT(genericValue, Sex);
			JSON_READ_INT64(genericValue, Golds);
			JSON_READ_INT64(genericValue, Diamonds);
			JSON_READ_INT(genericValue, LobbyServerID);
			JSON_READ_INT(genericValue, LogicalServerID);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		NotifyForceOfflineRes::NotifyForceOfflineRes()
		{
			PlayerID = 0;
			Type = FOT_UNKNOWN;
		}

		void NotifyForceOfflineRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_INT64(writer, PlayerID);
			JSON_WRITE_ENUM32(writer, Type);
		}

		bool NotifyForceOfflineRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_INT64(genericValue, PlayerID);
			JSON_READ_ENUM32(genericValue, Type, ForceOfflineType);

			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		MatchReq::MatchReq()
		{

		}

		void MatchReq::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{

		}

		bool MatchReq::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			return true;
		}


		//////////////////////////////////////////////////////////////////////////


		MatchRes::MatchRes()
		{
			LogicalServerID = 0;
			LogicalTcpPort = 0;
			LogicalWsPort = 0;
		}

		void MatchRes::Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const
		{
			JSON_WRITE_INT(writer, LogicalServerID);
			JSON_WRITE_STRING(writer, LogicalAddr);
			JSON_WRITE_INT(writer, LogicalTcpPort);
			JSON_WRITE_INT(writer, LogicalWsPort);
		}

		bool MatchRes::Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue)
		{
			JSON_READ_INT(genericValue, LogicalServerID);
			JSON_READ_STRING(genericValue, LogicalAddr);
			JSON_READ_INT(genericValue, LogicalTcpPort);
			JSON_READ_INT(genericValue, LogicalWsPort);

			return true;
		}


	}
}