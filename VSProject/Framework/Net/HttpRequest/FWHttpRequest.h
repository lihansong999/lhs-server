#ifndef __FRAMEWORK_HTTPREQUEST_H__
#define __FRAMEWORK_HTTPREQUEST_H__

#include "../../FWLocal.h"
#include "../../FWTypeDefine.h"
#include "../../Common/FWString.h"

FW_NS_BEGIN


/*
Http«Î«Û
*/
class FW_DLL FWHttpRequest
{
public:

	//"folded headers" divided into two element
	typedef void(*HttpResponseCallback)(CURLcode, long, const FWString *, size_t, const FWString &, FW_ID);

	class FW_DLL HttpResponseDelegate
	{
	public:
		HttpResponseDelegate();
		virtual ~HttpResponseDelegate();
		//"folded headers" divided into two element
		virtual void OnHttpResponse(CURLcode performCode, long responseCode, const FWString * headArray, size_t headCount, const FWString & bodyData, FW_ID custom) = 0;
	};

	struct FW_DLL CASetting {
		CASetting();

		//must
		long VerifyPeer;	//must 1, default 0
		long VerifyHost;	//0 or 2

		//optional
		FWString Path;		//ca folder, windows invalid
		FWString Info;		//ca file
	};

	struct FW_DLL RequestSetting {
		RequestSetting();
		RequestSetting(const char * url, HttpResponseCallback callback);
		RequestSetting(const char * url, HttpResponseDelegate * delegate);
		RequestSetting(const char * url, const char * postData, size_t size, HttpResponseCallback callback);
		RequestSetting(const char * url, const char * postData, size_t size, HttpResponseDelegate * delegate);

		//must
		FWString				URL;

		//at least one
		HttpResponseCallback	CallbackFunc;
		HttpResponseDelegate  *	CallbackObj;

		//optional, post
		FWString				PostData;
		bool					RemoveExpect;	//post method remove head "Expect: 100-continue", default true

		//optional, user custom data
		FW_ID					Custom;

		//optional, common
		long					ConnectTimeOut;	//default 10
		long					TimeOut;		//default 20
		FWString			  *	HttpHeadArray;
		size_t					HttpHeadCount;
		FWString				UserName;
		FWString				Password;
		
		//optional, redirect
		long					FollowLocation;	//default 1
		long					MaxRedirs;		//default -1

		//optional, abort if slower than LowSpeedLimit bytes/sec during LowSpeedTime seconds
		long					LowSpeedTime;	//default 0
		long					LowSpeedLimit;	//default 0

		//optional, https CA verify
		CASetting				CaSetting;
	};

public:
	FWHttpRequest();
	~FWHttpRequest();

	static FWHttpRequest * GetInstance();

	void Get(const RequestSetting & requestSetting);

	void GetAsync(const RequestSetting & requestSetting);

	void Post(const RequestSetting & requestSetting);

	void PostAsync(const RequestSetting & requestSetting);

private:
	void _get(const RequestSetting & requestSetting, void * pPromiseSettingEnd);
	void _post(const RequestSetting & requestSetting, void * pPromiseSettingEnd);

};


FW_NS_END

#endif // __FRAMEWORK_HTTPREQUEST_H__
