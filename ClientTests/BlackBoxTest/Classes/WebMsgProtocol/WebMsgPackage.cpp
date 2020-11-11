#include "stdafx.h"
#include "WebMsgPackage.h"
#include "../Charset.h"
#include "../Base64.h"


Message::MSGString WebMsgPackage(WebMsgBase * msg)
{
	Message::MSGString ret = "data=";
	rapidjson::StringBuffer sb;
	rapidjson::Writer<rapidjson::StringBuffer> writer(sb);
	writer.StartObject();
	if(msg)
		msg->Serialize(writer);
	writer.EndObject();
	Message::MSGString b64 = URIBase64Encode(sb.GetString(), (int)sb.GetSize());
	Base64NoPadding(&b64);
	ret.Append(b64);
	return ret;
}

bool WebMsgUnPackage(CURLcode performCode, long responseCode, const Message::MSGString & json, WebMsgBase * msg)
{
	rapidjson::GenericDocument<rapidjson::UTF8<> > doc;
	if (responseCode != 200)
	{
		AfxMessageBox(L"ÇëÇóÊ§°Ü£¡");
		return false;
	}
	doc.Parse<rapidjson::kParseDefaultFlags, rapidjson::UTF8<> >(json.C_Str(), (size_t)json.Size());
	if (doc.HasParseError() || !doc.IsObject())
	{
		AfxMessageBox(L"ÏìÓ¦ÏûÏ¢µÄ¸ñÊ½´íÎó£¡");
		return false;
	}
	if (JSON_HAS_OBJECT(doc, "Error"))
	{
		const rapidjson::GenericValue<rapidjson::UTF8<> > & err = doc["Error"];
		int code = err["Code"].GetInt();
		const char * info = err["Info"].GetString();
		CString es;
		es.Format(L"%s\n%s%d\n%s%s", L"ÏìÓ¦´íÎó£º", L"Code = ", code, L"Info = ", UTF8_2_UNICODE(info).c_str());
		AfxMessageBox(es.GetBuffer(), MB_OK | MB_ICONINFORMATION);
		return false;
	}
	if (msg)
	{
		return msg->Deserialize(doc);
	}
	return true;
}