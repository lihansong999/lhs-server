package gmresponse

import (
	//"WebServer/Framework/fwmysqlhelper"
	//"WebServer/Framework/fwredishelper"
	//"WebServer/GMServer/CodeModules/gmdatabasetools"
	//"WebServer/GMServer/CodeModules/gmglobal"
	//"encoding/json"
	//"fmt"
	//"log"
	"net/http"
	//"strconv"
)

func initMISC() bool {

	// 关于
	HandleFunc("/api/aboutReq", aboutReqHandler)

	return true
}

type aboutInfoRes struct {
	Description string
}

func aboutReqHandler(w http.ResponseWriter, r *http.Request) {
	ResponseData(w, aboutInfoRes{"后台系统<br />版本:1.0.0"})
}
