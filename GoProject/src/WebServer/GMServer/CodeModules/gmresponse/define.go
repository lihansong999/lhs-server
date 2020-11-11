package gmresponse

import (
	"WebServer/Framework/fwtools"
	"WebServer/GMServer/CodeModules/gmglobal"
	"encoding/base64"
	"encoding/json"
	//"fmt"
	"net/http"
)

func init() {
	errInfoMap.Set(ErrCodeNotAPI, "找不到API")
	errInfoMap.Set(ErrCodeUnknown, "未知错误")
	errInfoMap.Set(ErrCodeParseForm, "解析请求参数错误")
	errInfoMap.Set(ErrCodeParseJSON, "解析json错误")
	errInfoMap.Set(ErrCodeIllegalParm, "非法参数")
	errInfoMap.Set(ErrCodeServerBusy, "服务器繁忙")
	errInfoMap.Set(ErrCodeNotLogged, "非法操作，尚未登录")
}

// 通用主错误码
const (
	ErrCodeNotAPI      = 1 // 找不到API
	ErrCodeUnknown     = 2 // 未知错误
	ErrCodeParseForm   = 3 // 解析参数错误
	ErrCodeParseJSON   = 4 // 解析json错误
	ErrCodeIllegalParm = 5 // 非法参数
	ErrCodeServerBusy  = 6 // 服务器繁忙
	ErrCodeNotLogged   = 7 // 非法操作，尚未登录
)

var errInfoMap = fwtools.GoSafeMapIntString{}

type errorDataRes struct {
	Code int
	Info string
}

type errorRes struct {
	Error errorDataRes
}

const jsonMarshalErrorStr = "{\"Error\": {\"Code\": 7777777,\"Info\": \"json.Marshal() error\"}}"

// ResponseError 响应错误
func ResponseError(w http.ResponseWriter, code int) {
	w.Header().Set("content-type", "text/plain; charset=utf-8")
	jst := errorRes{Error: errorDataRes{Code: code, Info: errInfoMap.Get(code)}}
	jss, err := json.Marshal(jst)
	if err != nil {
		w.Write([]byte(jsonMarshalErrorStr))
		return
	}
	w.Write(jss)
}

// ResponseWithoutData 响应不需要数据回复的情况
func ResponseWithoutData(w http.ResponseWriter) {
	w.Header().Set("content-type", "text/plain; charset=utf-8")
	w.Write([]byte("{}"))
}

// ResponseData 响应数据
func ResponseData(w http.ResponseWriter, v interface{}) {
	w.Header().Set("content-type", "text/plain; charset=utf-8")
	jss, err := json.Marshal(v)
	if err != nil {
		w.Write([]byte(jsonMarshalErrorStr))
		return
	}
	w.Write(jss)
}

// ParseArgs 解析客户端请求参数
func ParseArgs(w http.ResponseWriter, r *http.Request, v interface{}) bool {
	err := r.ParseForm()
	if err != nil {
		ResponseError(w, ErrCodeParseForm)
		return false
	}
	data, err := base64.RawURLEncoding.DecodeString(r.FormValue("data"))
	if err != nil {
		ResponseError(w, ErrCodeParseForm)
		return false
	}
	// data 必须是UTF8
	err = json.Unmarshal(data, v)
	if err != nil {
		ResponseError(w, ErrCodeParseJSON)
		return false
	}
	return true
}

// CheckLoggedInForRes API请求的处理函数中检测是否已登录，如未登录将直接响应错误
func CheckLoggedInForRes(w http.ResponseWriter, r *http.Request) (bool, string) {
	if ok, account := VerifyDynaPwdCookieAndGetAccount(r); ok {
		return true, account
	}
	ClearDynaPwdCookie(w)
	ResponseError(w, ErrCodeNotLogged)
	return false, ""
}

// SetDynaPwdCookieWithAccount 根据账号设置管理员动态密码Cookie
func SetDynaPwdCookieWithAccount(w http.ResponseWriter, account string, name string) {
	dynaPwdCookie := http.Cookie{}
	dynaPwdCookie.Name = CookieKeyDynaPwd
	dynaPwdCookie.Value = gmglobal.MakeDynaPwdWithAccount(account)
	dynaPwdCookie.Path = "/"
	//dynaPwdCookie.Domain = "150.158.172.137" //.xxx.com
	//dynaPwdCookie.MaxAge = 3600 // 过期时间（单位秒，-1为删除，如果不设置此值cookie就会在关闭浏览后失效）
	dynaPwdCookie.Secure = true                      // 是否必须是https
	dynaPwdCookie.HttpOnly = true                    // 是否阻止JavaScript读取这个cookie
	dynaPwdCookie.SameSite = http.SameSiteStrictMode // 浏览器会慢慢发展为以Lax模式为默认，如果要需要None模式需要同时设置Secure为true，因为浏览器以后会慢慢要求https下才允许None模式
	http.SetCookie(w, &dynaPwdCookie)

	loggedTagCookie := http.Cookie{}
	loggedTagCookie.Name = CookieKeyAdminName
	loggedTagCookie.Value = base64.RawURLEncoding.EncodeToString([]byte(name))
	loggedTagCookie.Path = "/"
	//loggedTagCookie.Domain = "150.158.172.137"
	//loggedTagCookie.MaxAge = 3600
	loggedTagCookie.Secure = true
	loggedTagCookie.HttpOnly = false
	loggedTagCookie.SameSite = http.SameSiteStrictMode
	http.SetCookie(w, &loggedTagCookie)
}

// VerifyDynaPwdCookieAndGetAccount 校验管理员动态密码Cookie并返回管理员账号
func VerifyDynaPwdCookieAndGetAccount(r *http.Request) (bool, string) {
	dynaPwd, err := r.Cookie(CookieKeyDynaPwd)
	if err != nil {
		return false, ""
	}
	return gmglobal.DynaPwdValidityAndGetAccount(dynaPwd.Value)
}

// ClearDynaPwdCookie 删除管理员动态密码Cookie
func ClearDynaPwdCookie(w http.ResponseWriter) {
	dynaPwdCookie := http.Cookie{}
	dynaPwdCookie.Name = CookieKeyDynaPwd
	dynaPwdCookie.Value = ""
	dynaPwdCookie.Path = "/"
	//dynaPwdCookie.Domain = "150.158.172.137"
	dynaPwdCookie.MaxAge = -1
	dynaPwdCookie.Secure = true
	dynaPwdCookie.HttpOnly = true
	dynaPwdCookie.SameSite = http.SameSiteStrictMode
	http.SetCookie(w, &dynaPwdCookie)

	loggedTagCookie := http.Cookie{}
	loggedTagCookie.Name = CookieKeyAdminName
	loggedTagCookie.Value = ""
	loggedTagCookie.Path = "/"
	//loggedTagCookie.Domain = "150.158.172.137"
	loggedTagCookie.MaxAge = -1
	loggedTagCookie.Secure = true
	loggedTagCookie.HttpOnly = false
	loggedTagCookie.SameSite = http.SameSiteStrictMode
	http.SetCookie(w, &loggedTagCookie)
}
