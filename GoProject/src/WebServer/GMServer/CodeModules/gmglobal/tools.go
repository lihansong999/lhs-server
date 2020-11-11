package gmglobal

import (
	"WebServer/Framework/fwtools"
	//"bytes"
	"encoding/base64"
	//"encoding/json"
	//"fmt"
	//"io"
	"math/rand"
	//"net/http"
	"regexp"
	"strconv"
	"strings"
	"time"
)

// AccountValidity 验证管理员账号有效性（只校验格式，与数据库验证无关）
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

// PasswordValidity 验证管理员密码有效性（只校验格式，与数据库验证无关）
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

var dynaPwdCryptoKey = []byte("haha-heihei-lhs7")
var dynaPwdCryptoIV = []byte("HansongIsTheKing")

// MakeDynaPwdWithAccount 根据管理员账号生成管理员动态密码（与数据库验证无关）
func MakeDynaPwdWithAccount(account string) string {
	if AccountValidity(account) != true {
		return ""
	}
	accSlice := []byte(account)
	ctSlice := []byte(strconv.FormatInt(time.Now().Unix(), 10))
	randSlice := []byte(strconv.Itoa(rand.Intn(10000) + 123456))
	sepSlice := []byte("*l*h*s*") // 因账号需要异或随机数，所有有低概率重复风险
	for i, j := 0, 0; i < len(accSlice); i++ {
		accSlice[i] ^= randSlice[j]
		if j++; j >= len(randSlice) {
			j = 0
		}
	}
	data := make([]byte, 0, len(accSlice)+len(ctSlice)+len(randSlice)+len(sepSlice)*2)
	data = append(data, accSlice...)
	data = append(data, sepSlice...)
	data = append(data, ctSlice...)
	data = append(data, sepSlice...)
	data = append(data, randSlice...)
	err := fwtools.AESEncrypt(dynaPwdCryptoKey, dynaPwdCryptoIV, &data)
	if err != nil {
		return ""
	}
	return base64.RawURLEncoding.EncodeToString(data)
}

// DynaPwdValidityAndGetAccount 验证管理员动态密码有效性并返回管理员账号（只校验格式，与数据库验证无关）
func DynaPwdValidityAndGetAccount(dynaPwd string) (bool, string) {
	if l := len(dynaPwd); l < 12 || l > 256 {
		return false, ""
	}
	data, err := base64.RawURLEncoding.DecodeString(dynaPwd)
	if err != nil {
		return false, ""
	}
	err = fwtools.AESDecrypt(dynaPwdCryptoKey, dynaPwdCryptoIV, &data)
	if err != nil {
		return false, ""
	}
	texts := strings.Split(string(data), "*l*h*s*")
	if len(texts) != 3 || len(texts[0]) == 0 || len(texts[1]) == 0 || len(texts[2]) != 6 {
		return false, ""
	}
	ok, err := regexp.MatchString("^[0-9]+$", texts[1])
	if err != nil || ok == false {
		return false, ""
	}
	lastTime, err := strconv.ParseInt(texts[1], 10, 64)
	if err != nil {
		return false, ""
	}
	if time.Now().Unix()-lastTime > 28800 { // 管理员动态密码有效期只有8小时
		return false, ""
	}
	accSlice := []byte(texts[0])
	randSlice := []byte(texts[2])
	for i, j := 0, 0; i < len(accSlice); i++ {
		accSlice[i] ^= randSlice[j]
		if j++; j >= len(randSlice) {
			j = 0
		}
	}
	account := string(accSlice)
	if AccountValidity(account) != true {
		return false, ""
	}
	return true, account
}
