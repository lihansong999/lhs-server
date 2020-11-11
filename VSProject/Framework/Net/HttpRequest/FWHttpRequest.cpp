#include "FWHttpRequest.h"


FW_NS_BEGIN

#define HTTPREQ_BREAK_IF(v)	if (v) break


static size_t _HeadCallbackFunc(char *buffer, size_t size, size_t nitems, void *userdata)
{
	size_t realsize = size * nitems;
	if (realsize > 0)
	{
		std::vector<FWString> * pVector = (std::vector<FWString>*)userdata;
		pVector->push_back(FWString(buffer, realsize));
	}
	return nitems * size;
}

static size_t _BodyCallbackFunc(char *ptr, size_t size, size_t nmemb, void *userdata)
{
	size_t realsize = size * nmemb;
	if (realsize > 0)
	{
		FWString * pString = (FWString*)userdata;
		pString->Append(ptr, realsize);
	}
	return realsize;
}

FWHttpRequest::HttpResponseDelegate::HttpResponseDelegate()
{

}

FWHttpRequest::HttpResponseDelegate::~HttpResponseDelegate()
{

}

FWHttpRequest::CASetting::CASetting()
	:VerifyPeer(0L)
	, VerifyHost(0L)
{

}

FWHttpRequest::RequestSetting::RequestSetting()
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

FWHttpRequest::RequestSetting::RequestSetting(const char * url, HttpResponseCallback callback)
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

FWHttpRequest::RequestSetting::RequestSetting(const char * url, HttpResponseDelegate * delegate)
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

FWHttpRequest::RequestSetting::RequestSetting(const char * url, const char * postData, size_t size, HttpResponseCallback callback)
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
		PostData.Reserve(size);
		PostData.Append(postData, size);
	}
}

FWHttpRequest::RequestSetting::RequestSetting(const char * url, const char * postData, size_t size, HttpResponseDelegate * delegate)
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
		PostData.Reserve(size);
		PostData.Append(postData, size);
	}
}


static FWHttpRequest _FWHttpRequest;

FWHttpRequest::FWHttpRequest()
{
	curl_global_init(CURL_GLOBAL_ALL);
}

FWHttpRequest::~FWHttpRequest()
{
	curl_global_cleanup();
}

FWHttpRequest * FWHttpRequest::GetInstance()
{
	return &_FWHttpRequest;
}

void FWHttpRequest::Get(const RequestSetting & requestSetting)
{
	this->_get(requestSetting, nullptr);
}

void FWHttpRequest::GetAsync(const RequestSetting & requestSetting)
{
	std::promise<int> promiseSettingEnd;
	std::future<int> futureSettingEnd = promiseSettingEnd.get_future();
	std::thread t = std::thread([this, &requestSetting, &promiseSettingEnd]()->void {
		this->_get(requestSetting, &promiseSettingEnd);
	});
	t.detach();
	futureSettingEnd.get();
}

void FWHttpRequest::Post(const RequestSetting & requestSetting)
{
	this->_post(requestSetting, nullptr);
}

void FWHttpRequest::PostAsync(const RequestSetting & requestSetting)
{
	std::promise<int> promiseSettingEnd;
	std::future<int> futureSettingEnd = promiseSettingEnd.get_future();
	std::thread t = std::thread([this, &requestSetting, &promiseSettingEnd]()->void {
		this->_post(requestSetting, &promiseSettingEnd);
	});
	t.detach();
	futureSettingEnd.get();
}

void FWHttpRequest::_get(const RequestSetting & requestSetting, void * pPromiseSettingEnd)
{
	assert(requestSetting.URL.Size() > 0 && (requestSetting.CallbackFunc != nullptr || requestSetting.CallbackObj != nullptr));
	CURLcode performCode = CURL_LAST;
	long responseCode = 0;
	std::vector<FWString> responseHead;
	FWString responseBody;
	CURL * easy_handle = nullptr;
	curl_slist * slist = nullptr;
	HttpResponseCallback callbackFunc = requestSetting.CallbackFunc;
	HttpResponseDelegate * callbackObj = requestSetting.CallbackObj;
	FW_ID custom = requestSetting.Custom;
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
			if (requestSetting.CaSetting.Path.Compare("") != 0)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_CAPATH, requestSetting.CaSetting.Path.C_Str()));
			}
			if (requestSetting.CaSetting.Info.Compare("") != 0)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_CAINFO, requestSetting.CaSetting.Info.C_Str()));
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
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_URL, requestSetting.URL.C_Str()));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HEADERFUNCTION, &_HeadCallbackFunc));
		responseHead.clear();
		responseHead.reserve(16);
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HEADERDATA, &responseHead));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, &_BodyCallbackFunc));
		responseBody = "";
		responseBody.Reserve(1024);
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &responseBody));
		if (requestSetting.UserName.Compare("") != 0)
		{
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_USERNAME, requestSetting.UserName.C_Str()));
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_PASSWORD, requestSetting.Password.C_Str()));
		}

		//head
		if (requestSetting.HttpHeadCount > 0)
		{
			for (size_t i = 0; i < requestSetting.HttpHeadCount; i++)
			{
				slist = curl_slist_append(slist, requestSetting.HttpHeadArray[i].C_Str());
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
		(*callbackFunc)(performCode, responseCode, (responseHead.size() > 0) ? (&(responseHead[0])) : (nullptr), responseHead.size(), responseBody, custom);
	if (callbackObj)
		callbackObj->OnHttpResponse(performCode, responseCode, (responseHead.size() > 0) ? (&(responseHead[0])) : (nullptr), responseHead.size(), responseBody, custom);
}

void FWHttpRequest::_post(const RequestSetting & requestSetting, void * pPromiseSettingEnd)
{
	assert(requestSetting.URL.Size() > 0 && (requestSetting.CallbackFunc != nullptr || requestSetting.CallbackObj != nullptr));
	CURLcode performCode = CURL_LAST;
	long responseCode = 0;
	std::vector<FWString> responseHead;
	FWString responseBody;
	CURL * easy_handle = nullptr;
	curl_slist * slist = nullptr;
	HttpResponseCallback callbackFunc = requestSetting.CallbackFunc;
	HttpResponseDelegate * callbackObj = requestSetting.CallbackObj;
	FW_ID custom = requestSetting.Custom;
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
			if (requestSetting.CaSetting.Path.Compare("") != 0)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_CAPATH, requestSetting.CaSetting.Path.C_Str()));
			}
			if (requestSetting.CaSetting.Info.Compare("") != 0)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_CAINFO, requestSetting.CaSetting.Info.C_Str()));
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
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_URL, requestSetting.URL.C_Str()));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HEADERFUNCTION, &_HeadCallbackFunc));
		responseHead.clear();
		responseHead.reserve(16);
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_HEADERDATA, &responseHead));
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_WRITEFUNCTION, &_BodyCallbackFunc));
		responseBody = "";
		responseBody.Reserve(1024);
		HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_WRITEDATA, &responseBody));
		if (requestSetting.UserName.Compare("") != 0)
		{
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_USERNAME, requestSetting.UserName.C_Str()));
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_PASSWORD, requestSetting.Password.C_Str()));
		}

		//post data
		if (requestSetting.PostData.Size() == 0)
		{
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDSIZE, 0L));
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDS, ""));
		}
		else
		{
			if (requestSetting.PostData.Size() > (size_t)2147483647)
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDSIZE_LARGE, (curl_off_t)(requestSetting.PostData.Size())));
			}
			else
			{
				HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_POSTFIELDSIZE, (long)(requestSetting.PostData.Size())));
			}
			HTTPREQ_BREAK_IF(CURLE_OK != curl_easy_setopt(easy_handle, CURLOPT_COPYPOSTFIELDS, requestSetting.PostData.C_Str()));
			if (requestSetting.RemoveExpect && requestSetting.PostData.Size() > 1024)
			{
				slist = curl_slist_append(slist, "Expect:");
			}
		}

		//head
		if (requestSetting.HttpHeadCount > 0)
		{
			for (size_t i = 0; i < requestSetting.HttpHeadCount; i++)
			{
				slist = curl_slist_append(slist, requestSetting.HttpHeadArray[i].C_Str());
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
		(*callbackFunc)(performCode, responseCode, (responseHead.size() > 0) ? (&(responseHead[0])) : (nullptr), responseHead.size(), responseBody, custom);
	if (callbackObj)
		callbackObj->OnHttpResponse(performCode, responseCode, (responseHead.size() > 0) ? (&(responseHead[0])) : (nullptr), responseHead.size(), responseBody, custom);
}


FW_NS_END