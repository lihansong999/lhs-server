package gmresponse

import (
	"WebServer/Framework/fwmysqlhelper"
	//"WebServer/Framework/fwredishelper"
	"WebServer/GMServer/CodeModules/gmdatabasetools"
	"WebServer/GMServer/CodeModules/gmglobal"
	//"encoding/json"
	//"fmt"
	//"log"
	"net/http"
	//"strconv"
)

func initLogin() bool {

	// 登录请求
	HandleFunc("/api/loginReq", loginReqHandler)

	// 登出请求
	HandleFunc("/api/logoutReq", logoutReqHandler)

	return true
}

type loginInfoReq struct {
	Username string
	Password string
}

type loginInfoRes struct {
	Succeed bool
	ErrInfo string
}

func loginReqHandler(w http.ResponseWriter, r *http.Request) {
	infoReq := loginInfoReq{}
	ok := ParseArgs(w, r, &infoReq)
	if !ok {
		return
	}
	if gmglobal.AccountValidity(infoReq.Username) != true {
		ResponseError(w, ErrCodeIllegalParm)
		return
	}
	if gmglobal.PasswordValidity(infoReq.Password) != true {
		ResponseError(w, ErrCodeIllegalParm)
		return
	}
	multiQueryResult, err := gmdatabasetools.MySQLHelper.Query("SELECT `name` FROM `admin_info` WHERE `account` = ? AND `pwd` = ? LIMIT 1;", infoReq.Username, infoReq.Password)
	if err != nil {
		ResponseData(w, loginInfoRes{false, "账号或密码错误"})
		return
	}
	rowQueryResult := fwmysqlhelper.GetFirstRowQueryResult(multiQueryResult)
	if rowQueryResult == nil {
		ResponseData(w, loginInfoRes{false, "账号或密码错误"})
		return
	}
	adminNameSlice, ok := (*rowQueryResult)["name"]
	if !ok {
		ResponseData(w, loginInfoRes{false, "账号或密码错误"})
		return
	}
	if len(adminNameSlice) == 0 {
		ResponseData(w, loginInfoRes{false, "账号或密码错误"})
		return
	}
	SetDynaPwdCookieWithAccount(w, infoReq.Username, string(adminNameSlice))
	ResponseData(w, loginInfoRes{true, ""})
}

func logoutReqHandler(w http.ResponseWriter, r *http.Request) {
	ClearDynaPwdCookie(w)
	ResponseWithoutData(w)
}
