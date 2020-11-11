#ifndef __HTTPREQUEST_H__
#define __HTTPREQUEST_H__

#include "Local.h"


/*
Http«Î«Û
*/
class HttpRequest
{
public:

	//"folded headers" divided into two element
	typedef std::function<void(CURLcode, long, const std::vector<std::string> &, const std::string &, long long)> HttpResponseCallback;

	class HttpResponseDelegate
	{
	public:
		HttpResponseDelegate();
		virtual ~HttpResponseDelegate();
		//"folded headers" divided into two element
		virtual void OnHttpResponse(CURLcode performCode, long responseCode, const std::vector<std::string> & headData, const std::string & bodyData, long long custom) = 0;
	};

	struct CASetting {
		CASetting();

		//must
		long VerifyPeer;	//must 1, default 0
		long VerifyHost;	//0 or 2

		//optional
		std::string Path;		//ca folder, windows invalid
		std::string Info;		//ca file
	};

	struct RequestSetting {
		RequestSetting();
		RequestSetting(const char * url, const HttpResponseCallback & callback);
		RequestSetting(const char * url, HttpResponseDelegate * delegate);
		RequestSetting(const char * url, const char * postData, size_t size, const HttpResponseCallback & callback);
		RequestSetting(const char * url, const char * postData, size_t size, HttpResponseDelegate * delegate);

		//must
		std::string				URL;

		//at least one
		HttpResponseCallback	CallbackFunc;
		HttpResponseDelegate  *	CallbackObj;

		//optional, post
		std::string				PostData;
		bool					RemoveExpect;	//post method remove head "Expect: 100-continue", default true

		//optional, user custom data
		long long				Custom;

		//optional, common
		long					ConnectTimeOut;	//default 10
		long					TimeOut;		//default 20
		std::string			  *	HttpHeadArray;
		size_t					HttpHeadCount;
		std::string				UserName;
		std::string				Password;
		
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
	HttpRequest();
	~HttpRequest();

	static HttpRequest * GetInstance();

	void Get(const RequestSetting & requestSetting);

	void GetAsync(const RequestSetting & requestSetting);

	void Post(const RequestSetting & requestSetting);

	void PostAsync(const RequestSetting & requestSetting);

private:
	void _get(const RequestSetting & requestSetting, void * pPromiseSettingEnd);
	void _post(const RequestSetting & requestSetting, void * pPromiseSettingEnd);

};


#endif // __HTTPREQUEST_H__
