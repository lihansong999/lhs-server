package usresponse

import (
	"WebServer/Framework/fwmysqlhelper"
	//"WebServer/Framework/fwredishelper"
	"WebServer/UserServer/CodeModules/usdatabasetools"
	"WebServer/UserServer/CodeModules/usglobal"
	"crypto/sha256"
	"encoding/base64"
	"encoding/hex"
	//"encoding/json"
	//"fmt"
	//"log"
	"net/http"
	//"strconv"
)

func initRegister() bool {
	// 账号注册
	HandleFunc("/api/AccountRegister", accountRegisterHandler)
	// 唯一码注册
	HandleFunc("/api/UnionidRegister", unionidRegisterHandler)

	return true
}

// RegisterAccountReq 账号注册请求结构
type RegisterAccountReq struct {
	Account  string
	Password string
	Nickname string
	Sex      int
}

// RegisterAccountRes 账号注册回复结构
type RegisterAccountRes struct {
	Code int    // 0成功，1非法的账号或密码，2非法的昵称或性别，3账号已存在
	Tips string // 用户提示语句
}

func accountRegisterHandler(w http.ResponseWriter, r *http.Request) {
	infoReq := RegisterAccountReq{}
	ok := ParseArgs(w, r, &infoReq)
	if !ok {
		return
	}
	if usglobal.AccountValidity(infoReq.Account) == false || usglobal.PasswordValidity(infoReq.Password) == false {
		ResponseData(w, RegisterAccountRes{1, "非法的账号或密码"})
		return
	}
	if usglobal.NicknameValidity(infoReq.Nickname) == false || usglobal.SexValidity(infoReq.Sex) == false {
		ResponseData(w, RegisterAccountRes{2, "非法的昵称或性别"})
		return
	}
	nicknameB64 := base64.RawURLEncoding.EncodeToString([]byte(infoReq.Nickname))
	multiQueryResult, err := usdatabasetools.MySQLHelper.Query("CALL register_new_account(?, ?, ?, ?);", infoReq.Account, infoReq.Password, nicknameB64, infoReq.Sex)
	if err != nil {
		ResponseError(w, ErrCodeServerBusy)
		return
	}
	rowQueryResult := fwmysqlhelper.GetFirstRowQueryResult(multiQueryResult)
	if rowQueryResult == nil {
		ResponseError(w, ErrCodeServerBusy)
		return
	}
	retSlice, ok := (*rowQueryResult)["`ret`"]
	if !ok {
		ResponseError(w, ErrCodeServerBusy)
		return
	}
	ret := string(retSlice)
	if ret == "0" {
		ResponseData(w, RegisterAccountRes{0, "注册成功"})
	} else if ret == "-1" || ret == "-2" || ret == "-3" {
		ResponseData(w, RegisterAccountRes{1, "非法的账号或密码"})
	} else if ret == "-4" {
		ResponseData(w, RegisterAccountRes{2, "非法的昵称或性别"})
	} else if ret == "-5" {
		ResponseData(w, RegisterAccountRes{3, "账号已存在"})
	} else {
		ResponseError(w, ErrCodeServerBusy)
	}
	return
}

// RegisterUnionidReq 唯一码注册请求结构
type RegisterUnionidReq struct {
	Unionid  string
	Nickname string
	Sex      int
}

// RegisterUnionidRes 唯一码注册回复结构
type RegisterUnionidRes struct {
	Code int    // 0成功，1非法的unionid，2非法的昵称或性别
	Tips string // 用户提示语句
}

func unionidRegisterHandler(w http.ResponseWriter, r *http.Request) {
	infoReq := RegisterUnionidReq{}
	ok := ParseArgs(w, r, &infoReq)
	if !ok {
		return
	}
	if usglobal.UnionidValidity(infoReq.Unionid) == false {
		ResponseData(w, RegisterUnionidRes{1, "非法的unionid"})
		return
	}
	if usglobal.NicknameValidity(infoReq.Nickname) == false || usglobal.SexValidity(infoReq.Sex) == false {
		ResponseData(w, RegisterUnionidRes{2, "非法的昵称或性别"})
		return
	}
	nicknameB64 := base64.RawURLEncoding.EncodeToString([]byte(infoReq.Nickname))
	unionidSha256Values := sha256.Sum256([]byte(infoReq.Unionid))
	unionidSha256 := hex.EncodeToString(unionidSha256Values[:])
	multiQueryResult, err := usdatabasetools.MySQLHelper.Query("CALL register_new_account_unionid(?, ?, ?, ?);", unionidSha256, infoReq.Unionid, nicknameB64, infoReq.Sex)
	if err != nil {
		ResponseError(w, ErrCodeServerBusy)
		return
	}
	rowQueryResult := fwmysqlhelper.GetFirstRowQueryResult(multiQueryResult)
	if rowQueryResult == nil {
		ResponseError(w, ErrCodeServerBusy)
		return
	}
	retSlice, ok := (*rowQueryResult)["`ret`"]
	if !ok {
		ResponseError(w, ErrCodeServerBusy)
		return
	}
	ret := string(retSlice)
	if ret == "0" {
		ResponseData(w, RegisterUnionidRes{0, "注册成功"})
	} else if ret == "-1" || ret == "-2" || ret == "-3" {
		ResponseData(w, RegisterUnionidRes{1, "非法的unionid"})
	} else if ret == "-4" {
		ResponseData(w, RegisterUnionidRes{2, "非法的昵称或性别"})
	} else {
		ResponseError(w, ErrCodeServerBusy)
	}
	return
}
