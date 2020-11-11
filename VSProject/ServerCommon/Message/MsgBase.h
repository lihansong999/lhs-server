#ifndef __MESSAGE_BASE_H__
#define __MESSAGE_BASE_H__

#include "MsgLocal.h"
#include "MsgString.h"


namespace MSG_NAMESPACE {


#define JSON_HAS_OBJECT(g, k)	(g.HasMember(k) && g[k].IsObject())
#define JSON_HAS_NULL(g, k)		(g.HasMember(k) && g[k].IsNull())
#define JSON_HAS_BOOL(g, k)		(g.HasMember(k) && g[k].IsBool())
#define JSON_HAS_INT(g, k)		(g.HasMember(k) && g[k].IsInt())
#define JSON_HAS_UINT(g, k)		(g.HasMember(k) && g[k].IsUint())
#define JSON_HAS_INT64(g, k)	(g.HasMember(k) && g[k].IsInt64())
#define JSON_HAS_UINT64(g, k)	(g.HasMember(k) && g[k].IsUint64())
#define JSON_HAS_FLOAT(g, k)	(g.HasMember(k) && g[k].IsFloat())
#define JSON_HAS_DOUBLE(g, k)	(g.HasMember(k) && g[k].IsDouble())
#define JSON_HAS_STRING(g, k)	(g.HasMember(k) && g[k].IsString())
#define JSON_HAS_ARRAY(g, k)	(g.HasMember(k) && g[k].IsArray())
#define JSON_HAS_BINARY(g, k)	(g.HasMember(k) && g[k].IsString())

#define MSG_RETURN_FALSE_IF(expression)	if (!(expression)) return false

#define JSON_READ_BOOL(gv, varName) \
			MSG_RETURN_FALSE_IF(JSON_HAS_BOOL(gv, #varName)); \
			varName = gv[#varName].GetBool()

#define JSON_READ_INT(gv, varName) \
			MSG_RETURN_FALSE_IF(JSON_HAS_INT(gv, #varName)); \
			varName = gv[#varName].GetInt()

#define JSON_READ_UINT(gv, varName) \
			MSG_RETURN_FALSE_IF(JSON_HAS_UINT(gv, #varName)); \
			varName = gv[#varName].GetUint()

#define JSON_READ_INT64(gv, varName) \
			MSG_RETURN_FALSE_IF(JSON_HAS_INT64(gv, #varName)); \
			varName = gv[#varName].GetInt64()

#define JSON_READ_UINT64(gv, varName) \
			MSG_RETURN_FALSE_IF(JSON_HAS_UINT64(gv, #varName)); \
			varName = gv[#varName].GetUint64()

#define JSON_READ_FLOAT(gv, varName) \
			MSG_RETURN_FALSE_IF(JSON_HAS_FLOAT(gv, #varName)); \
			varName = gv[#varName].GetFloat()

#define JSON_READ_DOUBLE(gv, varName) \
			MSG_RETURN_FALSE_IF(JSON_HAS_DOUBLE(gv, #varName)); \
			varName = gv[#varName].GetDouble()

#define JSON_READ_STRING(gv, varName) \
			MSG_RETURN_FALSE_IF(JSON_HAS_STRING(gv, #varName)); \
			varName = gv[#varName].GetString()

#define JSON_READ_BINARY(gv, varName) \
			MSG_RETURN_FALSE_IF(JSON_HAS_BINARY(gv, #varName)); \
			varName.Assign(gv[#varName].GetString(), (size_t)gv[#varName].GetStringLength())

#define JSON_READ_ENUM32(gv, varName, enumType) \
			MSG_RETURN_FALSE_IF(JSON_HAS_INT(gv, #varName)); \
			varName = (enumType)gv[#varName].GetInt()


#define JSON_WRITE_BOOL(w, varName) \
			w.Key(#varName); \
			w.Bool(varName)

#define JSON_WRITE_INT(w, varName) \
			w.Key(#varName); \
			w.Int(varName)

#define JSON_WRITE_UINT(w, varName) \
			w.Key(#varName); \
			w.Uint(varName)

#define JSON_WRITE_INT64(w, varName) \
			w.Key(#varName); \
			w.Int64(varName)

#define JSON_WRITE_UINT64(w, varName) \
			w.Key(#varName); \
			w.Uint64(varName)

#define JSON_WRITE_FLOAT(w, varName) \
			w.Key(#varName); \
			w.Double((double)varName)

#define JSON_WRITE_DOUBLE(w, varName) \
			w.Key(#varName); \
			w.Double(varName)

#define JSON_WRITE_STRING(w, varName) \
			w.Key(#varName); \
			w.String(varName.C_Str())

#define JSON_WRITE_BINARY(w, varName) \
			w.Key(#varName); \
			w.String(varName.C_Str(), (rapidjson::SizeType)varName.Size())

#define JSON_WRITE_ENUM32(w, varName) \
			w.Key(#varName); \
			w.Int((int)varName)


	extern int MSG_DLL htonInt32(int i);

	extern int MSG_DLL ntohInt32(int i);

	extern MSG_DLL MSGString GetErrorString(int code);

	/*
	消息体继承自本类
	json = {
			"Head": {
				"MainID": 0,
				"AssistantID": 0,
				"ErrorCode": 0,
				"Reserve": 0
			},
			"Body": { Serialize从这里开始 }
		}
	*/
	class MSG_DLL MsgBodyBase
	{
	public:
		MsgBodyBase();
		virtual ~MsgBodyBase();

		virtual void Serialize(rapidjson::Writer<rapidjson::StringBuffer> & writer) const = 0;

		virtual bool Deserialize(const rapidjson::GenericValue<rapidjson::UTF8<> > & genericValue) = 0;
	};


}


#endif //!__MESSAGE_BASE_H__