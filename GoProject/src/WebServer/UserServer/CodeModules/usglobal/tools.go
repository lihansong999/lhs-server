package usglobal

import (
	//"WebServer/Framework/fwtools"
	//"encoding/json"
	//"net/http"
	"regexp"
)

// AccountValidity 验证账号有效性
func AccountValidity(account string) bool {
	l := len(account)
	if l < 6 || l > 12 {
		return false
	}
	ok, err := regexp.MatchString("^[A-Za-z0-9]+$", account)
	if err != nil {
		return false
	}
	return ok
}

// PasswordValidity 验证密码有效性
func PasswordValidity(password string) bool {
	l := len(password)
	if l < 6 || l > 12 {
		return false
	}
	ok, err := regexp.MatchString("^[A-Za-z0-9]+$", password)
	if err != nil {
		return false
	}
	return ok
}

// DynaPwdValidity 验证动态密码有效性
func DynaPwdValidity(dynaPwd string) bool {
	l := len(dynaPwd)
	if l != 32 {
		return false
	}
	ok, err := regexp.MatchString("^[A-Fa-f0-9]+$", dynaPwd)
	if err != nil {
		return false
	}
	return ok
}

// UnionidValidity 验证唯一码有效性
func UnionidValidity(unionid string) bool {
	l := len(unionid)
	if l < 6 || l > 64 {
		return false
	}
	ok, err := regexp.MatchString("^[\x01-\x7F]+$", unionid)
	if err != nil {
		return false
	}
	return ok
}

// NicknameValidity 验证昵称有效性
func NicknameValidity(nickname string) bool {
	return len(nickname) <= 120
}

// SexValidity 验证性别有效性
func SexValidity(sex int) bool {
	return sex >= -128 && sex <= 127
}
