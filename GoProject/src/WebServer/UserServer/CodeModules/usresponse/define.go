package usresponse

import (
	"WebServer/Framework/fwtools"
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
