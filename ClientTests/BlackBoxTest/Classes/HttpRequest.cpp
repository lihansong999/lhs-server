#include "stdafx.h"
#include "HttpRequest.h"


#define HTTPREQ_BREAK_IF(v)	if (v) break


static size_t _HeadCallbackFunc(char *buffer, size_t size, size_t nitems, void *userdata)
{
	size_t realsize = size * nitems;
	if (realsize > 0)
	{
		std::vector<std::string> * pVector = (std::vector<std::string>*)userdata;
		pVector->push_back(std::string(buffer, realsize));
	}
	return nitems * size;
}

static size_t _BodyCallbackFunc(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	size_t realsize = size * nmemb;
	if (realsize > 0)
	{
		std::string * pString = (std::string*)userdata;
		pString->append(ptr, realsize);
	}
	return realsize;
}

HttpRequest::HttpResponseDelegate::HttpResponseDelegate()
{

}

HttpRequest::HttpResponseDelegate::~HttpResponseDelegate()
{

}

HttpRequest::CASetting::CASetting()
	:VerifyPeer(0L)
	, VerifyHost(0L)
{

}

HttpRequest::RequestSetting::RequestSetting()
	:RemoveExpect(true)
	, Custom(0)
	, ConnectTimeOut(10L)
	, TimeOut(20L)
	, HttpHeadArray(nullptr)
	, HttpHeadCount(0)
	, FollowLocation(0)
	, MaxRedirs(-1)
	, LowSpeedTime(0)
	, LowSpeedLimit(0)
	, CallbackFunc(nullptr)
	, CallbackObj(nullptr)
{

}

HttpRequest::RequestSetting::RequestSetting(const char * url, const HttpResponseCallback & callback)
	:RemoveExpect(true)
	, Custom(0)
	, ConnectTimeOut(10L)
	, TimeOut(20L)
	, HttpHeadArray(nullptr)
	, HttpHeadCount(0)
	, FollowLocation(0)
	, MaxRedirs(-1)
	, LowSpeedTime(0)
	, LowSpeedLimit(0)
	, URL(url)
	, CallbackFunc(callback)
	, CallbackObj(nullptr)
{

}

HttpRequest::RequestSetting::RequestSetting(const char * url, HttpResponseDelegate * delegate)
	:RemoveExpect(true)
	, Custom(0)
	, ConnectTimeOut(10L)
	, TimeOut(20L)
	, HttpHeadArray(nullptr)
	, HttpHeadCount(0)
	, FollowLocation(0)
	, MaxRedirs(-1)
	, LowSpeedTime(0)
	, LowSpeedLimit(0)
	, URL(url)
	, CallbackFunc(nullptr)
	, CallbackObj(delegate)
{

}

HttpRequest::RequestSetting::RequestSetting(const char * url, const char * postData, size_t size, const HttpResponseCallback & callback)
	:RemoveExpect(true)
	, Custom(0)
	, ConnectTimeOut(10L)
	, TimeOut(20L)
	, HttpHeadArray(nullptr)
	, HttpHeadCount(0)
	, FollowLocation(0)
	, MaxRedirs(-1)
	, LowSpeedTime(0)
	, LowSpeedLimit(0)
	, URL(url)
	, CallbackFunc(callback)
	, CallbackObj(nullptr)
{
	if (postData && size > 0)
	{
		PostData.reserve(size);
		PostData.append(postData, size);
	}
}

HttpRequest::RequestSetting::RequestSetting(const char * url, const char * postData, size_t size, HttpResponseDelegate * delegate)
	:RemoveExpect(true)
	, Custom(0)
	, ConnectTimeOut(10L)
	, TimeOut(20L)
	, HttpHeadArray(nullptr)
	, HttpHeadCount(0)
	, FollowLocation(0)
	, MaxRedirs(-1)
	, LowSpeedTime(0)
	, LowSpeedLimit(0)
	, URL(url)
	, CallbackFunc(nullptr)
	, CallbackObj(delegate)
{
	if (postData && size > 0)
	{
		PostData.reserve(size);
		PostData.append(postData, size);
	}
}


static HttpRequest _HttpRequest;

HttpRequest::HttpRequest()
{
	curl_global_init(CURL_GLOBAL_ALL);
}

HttpRequest::~HttpRequest()
{
	curl_global_cleanup();
}

HttpRequest * HttpRequest::GetInstance()
{
	return &_HttpRequest;
}

void HttpRequest::Get(const RequestSetting & requestSetting)
{
	this->_get(requestSetting, nullptr);
}

void HttpRequest::GetAsync(const RequestSetting & requestSetting)
{
	std::promise<int> promiseSettingEnd;
	std::future<int> futureSettingEnd = promiseSettingEnd.get_future();
	std::thread t = std::thread([this, &requestSetting, &promiseSettingEnd]()->void {
		this->_get(requestSetting, &promiseSettingEnd);
	});
	t.detach();
	futureSettingEnd.get();
}

void HttpRequest::Post(const RequestSetting & requestSetting)
{
	this->_post(requestSetting, nullptr);
}

void HttpRequest::PostAsync(const RequestSetting & requestSetting)
{
	std::promise<int> promiseSettingEnd;
	std::future<int> futureSettingEnd = promiseSettingEnd.get_future();
	std::thread t = std::thread([this, &requestSetting, &promiseSettingEnd]()->void {
		this->_post(requestSetting, &promiseSettingEnd);
	});
	t.detach();
	futureSettingEnd.get();
}

void HttpRequest::_get(const RequestSetting & requestSetting, void * pPromiseSettingEnd)
{
	assert(requestSetting.URL.size() > 0 && (requestSetting.CallbackFunc != nullptr || requestSetting.CallbackObj != nullptr));
	CURLcode performCode = CURL_LAST;
	long responseCode = 0;
	std::vector<std::string> responseHead;
	std::string responseBody;
	CURL * easy_handle = nullptr;
	curl_slist * slist = nullptr;
	HttpResponseCallback callbackFunc = requestSetting.CallbackFunc;
	HttpResponseDelegate * callbackObj = requestSetting.CallbackObj;
	long long custom = requestSetting.Custom;
	std::promise<int> * ps = (std::promise<int>*)pPromiseSettingEnd;
	do
	{
		easy_handle = curl_easy_init();
		HTTPREQ_BREAK_IF(!easy_handle);

		//ssl
		if (requestSetting.CaSetting.VerifyPeer == 0L)
		{
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYPEER, 0L));
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYHOST, 0L));
		}
		else
		{
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYPEER, requestSetting.CaSetting.VerifyPeer));
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYHOST, requestSetting.CaSetting.VerifyHost));
			if (requestSetting.CaSetting.Path.compare("") != 0)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_CAPATH, requestSetting.CaSetting.Path.c_str()));
			}
			if (requestSetting.CaSetting.Info.compare("") != 0)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_CAINFO, requestSetting.CaSetting.Info.c_str()));
			}
		}

		//common
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HTTPGET, 1L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_VERBOSE, 0L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_NOSIGNAL, 1L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_ACCEPT_ENCODING, ""));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_TIMEOUT, requestSetting.TimeOut));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_CONNECTTIMEOUT, requestSetting.ConnectTimeOut));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_RESUME_FROM, 0L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HEADER, 0L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_NOBODY, 0L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_NOPROGRESS, 1L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_URL, requestSetting.URL.c_str()));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HEADERFUNCTION, &_HeadCallbackFunc));
		responseHead.clear();
		responseHead.reserve(16);
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HEADERDATA, &responseHead));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, &_BodyCallbackFunc));
		responseBody = "";
		responseBody.reserve(1024);
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &responseBody));
		if (requestSetting.UserName.compare("") != 0)
		{
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_USERNAME, requestSetting.UserName.c_str()));
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_PASSWORD, requestSetting.Password.c_str()));
		}

		//head
		if (requestSetting.HttpHeadCount > 0)
		{
			for (size_t i = 0; i < requestSetting.HttpHeadCount; i++)
			{
				slist = curl_slist_append(slist, requestSetting.HttpHeadArray[i].c_str());
			}
			if (slist)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HTTPHEADER, slist));
			}
		}

		//redirect
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_FOLLOWLOCATION, requestSetting.FollowLocation));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_MAXREDIRS, requestSetting.MaxRedirs));

		//abort if slower than LowSpeedLimit bytes/sec during LowSpeedTime seconds
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_LOW_SPEED_TIME, requestSetting.LowSpeedTime));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_LOW_SPEED_LIMIT, requestSetting.LowSpeedLimit));

		if (ps)
		{
			ps->set_value(0);
			ps = nullptr;
		}

		HTTPREQ_BREAK_IF(CURLE_OK != (performCode = curl_easy_perform(easy_handle)));
		curl_easy_getinfo(easy_handle, CURLINFO_RESPONSE_CODE, &responseCode);

	} while (false);

	if (ps)
	{
		ps->set_value(0);
		ps = nullptr;
	}

	if (easy_handle)
		curl_easy_cleanup(easy_handle);
	if (slist)
		curl_slist_free_all(slist);

	if (callbackFunc)
		callbackFunc(performCode, responseCode, responseHead, responseBody, custom);
	if (callbackObj)
		callbackObj->OnHttpResponse(performCode, responseCode, responseHead, responseBody, custom);
}

void HttpRequest::_post(const RequestSetting & requestSetting, void * pPromiseSettingEnd)
{
	assert(requestSetting.URL.size() > 0 && (requestSetting.CallbackFunc != nullptr || requestSetting.CallbackObj != nullptr));
	CURLcode performCode = CURL_LAST;
	long responseCode = 0;
	std::vector<std::string> responseHead;
	std::string responseBody;
	CURL * easy_handle = nullptr;
	curl_slist * slist = nullptr;
	HttpResponseCallback callbackFunc = requestSetting.CallbackFunc;
	HttpResponseDelegate * callbackObj = requestSetting.CallbackObj;
	long long custom = requestSetting.Custom;
	std::promise<int> * ps = (std::promise<int>*)pPromiseSettingEnd;
	do
	{
		easy_handle = curl_easy_init();
		HTTPREQ_BREAK_IF(!easy_handle);

		//ssl
		if (requestSetting.CaSetting.VerifyPeer == 0L)
		{
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYPEER, 0L));
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYHOST, 0L));
		}
		else
		{
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYPEER, requestSetting.CaSetting.VerifyPeer));
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_SSL_VERIFYHOST, requestSetting.CaSetting.VerifyHost));
			if (requestSetting.CaSetting.Path.compare("") != 0)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_CAPATH, requestSetting.CaSetting.Path.c_str()));
			}
			if (requestSetting.CaSetting.Info.compare("") != 0)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_CAINFO, requestSetting.CaSetting.Info.c_str()));
			}
		}

		//common
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_POST, 1L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_VERBOSE, 0L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_NOSIGNAL, 1L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_ACCEPT_ENCODING, ""));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_TIMEOUT, requestSetting.TimeOut));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_CONNECTTIMEOUT, requestSetting.ConnectTimeOut));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_RESUME_FROM, 0L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HEADER, 0L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_NOBODY, 0L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_NOPROGRESS, 1L));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_URL, requestSetting.URL.c_str()));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HEADERFUNCTION, &_HeadCallbackFunc));
		responseHead.clear();
		responseHead.reserve(16);
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HEADERDATA, &responseHead));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, &_BodyCallbackFunc));
		responseBody = "";
		responseBody.reserve(1024);
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &responseBody));
		if (requestSetting.UserName.compare("") != 0)
		{
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_USERNAME, requestSetting.UserName.c_str()));
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_PASSWORD, requestSetting.Password.c_str()));
		}

		//post data
		if (requestSetting.PostData.size() == 0)
		{
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDSIZE, 0L));
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDS, ""));
		}
		else
		{
			if (requestSetting.PostData.size() > (size_t)2147483647)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDSIZE_LARGE, (curl_off_t)(requestSetting.PostData.size())));
			}
			else
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDSIZE, (long)(requestSetting.PostData.size())));
			}
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_COPYPOSTFIELDS, requestSetting.PostData.c_str()));
			if (requestSetting.RemoveExpect && requestSetting.PostData.size() > 1024)
			{
				slist = curl_slist_append(slist, "Expect:");
			}
		}

		//head
		if (requestSetting.HttpHeadCount > 0)
		{
			for (size_t i = 0; i < requestSetting.HttpHeadCount; i++)
			{
				slist = curl_slist_append(slist, requestSetting.HttpHeadArray[i].c_str());
			}
			if (slist)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HTTPHEADER, slist));
			}
		}

		//redirect
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_FOLLOWLOCATION, requestSetting.FollowLocation));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_MAXREDIRS, requestSetting.MaxRedirs));

		//abort if slower than LowSpeedLimit bytes/sec during LowSpeedTime seconds
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_LOW_SPEED_TIME, requestSetting.LowSpeedTime));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_LOW_SPEED_LIMIT, requestSetting.LowSpeedLimit));

		if (ps)
		{
			ps->set_value(0);
			ps = nullptr;
		}

		HTTPREQ_BREAK_IF(CURLE_OK != (performCode = curl_easy_perform(easy_handle)));
		curl_easy_getinfo(easy_handle, CURLINFO_RESPONSE_CODE, &responseCode);

	} while (false);

	if (ps)
	{
		ps->set_value(0);
		ps = nullptr;
	}

	if (easy_handle)
		curl_easy_cleanup(easy_handle);
	if (slist)
		curl_slist_free_all(slist);

	if (callbackFunc)
		callbackFunc(performCode, responseCode, responseHead, responseBody, custom);
	if (callbackObj)
		callbackObj->OnHttpResponse(performCode, responseCode, responseHead, responseBody, custom);
}
