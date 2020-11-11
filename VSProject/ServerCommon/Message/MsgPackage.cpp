#include "MsgPackage.h"

namespace MSG_NAMESPACE {
	
	
	MsgPackageSend::MsgPackageSend(int mainID, int assistantID, const MsgBodyBase * body)
		:_serialized(new std::string())
	{
		rapidjson::StringBuffer sb;
		rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
		writer.StartObject();
		writer.Key("Head");
		writer.StartObject();
		writer.Key("MainID");
		writer.Int(mainID);
		writer.Key("AssistantID");
		writer.Int(assistantID);
		writer.Key("ErrorCode");
		writer.Int(0);
		writer.Key("Reserve");
		writer.Int(0);
		writer.EndObject();
		writer.Key("Body");
		writer.StartObject();
		if (body)
		{
			body->Serialize(writer);
		}
		writer.EndObject();
		writer.EndObject();
		int s = htonInt32((int)sb.GetSize());
		((std::string*)_serialized)->append((char*)(&s), sizeof(int));
		((std::string*)_serialized)->append(sb.GetString(), sb.GetSize());
	}

	MsgPackageSend::MsgPackageSend(int mainID, int assistantID, int errorCode, const MsgBodyBase * body)
		:_serialized(new std::string())
	{
		rapidjson::StringBuffer sb;
		rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
		writer.StartObject();
		writer.Key("Head");
		writer.StartObject();
		writer.Key("MainID");
		writer.Int(mainID);
		writer.Key("AssistantID");
		writer.Int(assistantID);
		writer.Key("ErrorCode");
		writer.Int(errorCode);
		writer.Key("Reserve");
		writer.Int(0);
		writer.EndObject();
		writer.Key("Body");
		writer.StartObject();
		if (errorCode != 0 && body)
		{
			body->Serialize(writer);
		}
		writer.EndObject();
		writer.EndObject();
		int s = htonInt32((int)sb.GetSize());
		((std::string*)_serialized)->append((char*)(&s), sizeof(int));
		((std::string*)_serialized)->append(sb.GetString(), sb.GetSize());
	}

	MsgPackageSend::MsgPackageSend(int mainID, int assistantID, int errorCode, int reserve, const MsgBodyBase * body)
		:_serialized(new std::string())
	{
		rapidjson::StringBuffer sb;
		rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
		writer.StartObject();
		writer.Key("Head");
		writer.StartObject();
		writer.Key("MainID");
		writer.Int(mainID);
		writer.Key("AssistantID");
		writer.Int(assistantID);
		writer.Key("ErrorCode");
		writer.Int(errorCode);
		writer.Key("Reserve");
		writer.Int(reserve);
		writer.EndObject();
		writer.Key("Body");
		writer.StartObject();
		if (errorCode != 0 && body)
		{
			body->Serialize(writer);
		}
		writer.EndObject();
		writer.EndObject();
		int s = htonInt32((int)sb.GetSize());
		((std::string*)_serialized)->append((char*)(&s), sizeof(int));
		((std::string*)_serialized)->append(sb.GetString(), sb.GetSize());
	}

	MsgPackageSend::~MsgPackageSend()
	{
		delete ((std::string*)_serialized);
	}

	const char * MsgPackageSend::GetBuffer() const
	{
		return ((std::string*)_serialized)->c_str();
	}

	int MsgPackageSend::GetSize() const
	{
		return (int)((std::string*)_serialized)->size();
	}


	//////////////////////////////////////////////////////////////////////////


	MsgPackageRecv::MsgPackageRecv(const char * buf, int size, int * out_validSize)
		:_mainID(0)
		, _assistantID(0)
		, _errorCode(0)
		, _reserve(0)
	{
		if (out_validSize)
		{
			*out_validSize = 0;
		}
		if (size < sizeof(int))
		{
			return;
		}
		int s = ntohInt32(*((int*)buf));
		if (s < 0 || s > MSG_PACKAGE_MAX)
		{
			return;
		}
		int validSize = s + sizeof(int);
		if (size < validSize)
		{
			return;
		}
		_doc.Parse<rapidjson::kParseDefaultFlags, rapidjson::UTF8<> >(buf + sizeof(int), (size_t)s);
		if (_doc.HasParseError() || !_doc.IsObject())
		{
			return;
		}
		if (!JSON_HAS_OBJECT(_doc, "Head"))
		{
			return;
		}
		const rapidjson::GenericValue<rapidjson::UTF8<> > & head = _doc["Head"];
		if (!JSON_HAS_INT(head, "MainID"))
		{
			return;
		}
		_mainID = head["MainID"].GetInt();
		if (!JSON_HAS_INT(head, "AssistantID"))
		{
			return;
		}
		_assistantID = head["AssistantID"].GetInt();
		if (!JSON_HAS_INT(head, "ErrorCode"))
		{
			return;
		}
		_errorCode = head["ErrorCode"].GetInt();
		if (!JSON_HAS_INT(head, "Reserve"))
		{
			return;
		}
		_reserve = head["Reserve"].GetInt();
		if (out_validSize)
		{
			*out_validSize = validSize;
		}
	}

	MsgPackageRecv::~MsgPackageRecv()
	{

	}

	int MsgPackageRecv::TestBufferValidity(const char * buf, int size, int * out_validCount)
	{
		if (out_validCount)
		{
			*out_validCount = 0;
		}
		int validCount = 0;
		int validSize = 0;
		for (; validCount < INT_MAX; validCount++)
		{
			if (size < validSize + (int)sizeof(int))
			{
				break;
			}
			int s = ntohInt32(*((int*)(buf + validSize)));
			if (s <= 0 || s > MSG_PACKAGE_MAX)
			{
				return -1;
			}
			int vs = s + sizeof(int);
			if (size < validSize + vs)
			{
				break;
			}
			validSize += vs;
		}
		if (out_validCount)
		{
			*out_validCount = validCount;
		}
		return validSize;
	}

	int MsgPackageRecv::GetMainID() const
	{
		return _mainID;
	}

	int MsgPackageRecv::GetAssistantID() const
	{
		return _assistantID;
	}

	int MsgPackageRecv::GetErrorCode() const
	{
		return _errorCode;
	}

	int MsgPackageRecv::GetReserve() const
	{
		return _reserve;
	}

	bool MsgPackageRecv::Deserialize(MsgBodyBase * body) const
	{
		if (_errorCode != 0)
		{
			return false;
		}
		if (!JSON_HAS_OBJECT(_doc, "Body"))
		{
			return false;
		}
		const rapidjson::GenericValue<rapidjson::UTF8<> > & b = _doc["Body"];
		return body->Deserialize(b);
	}


}