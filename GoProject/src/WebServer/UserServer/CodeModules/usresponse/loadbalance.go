package usresponse

import (
	//"WebServer/Framework/fwmysqlhelper"
	//"WebServer/Framework/fwredishelper"
	"WebServer/UserServer/CodeModules/usdatabasetools"
	//"WebServer/UserServer/CodeModules/usglobal"
	//"encoding/json"
	//"fmt"
	//"log"
	"net/http"
	//"strconv"
)

func initLoadbalance() bool {
	// 分配大厅服务器Host
	HandleFunc("/api/GetLobbyHost", getLobbyHostHandler)
	// 分配逻辑服务器Host
	HandleFunc("/api/GetLogicalHost", getLogicalHostHandler)

	return true
}

func getLobbyHostHandler(w http.ResponseWriter, r *http.Request) {
	infoRes, code := usdatabasetools.SelectionLobbyService()
	if code == 0 {
		ResponseData(w, infoRes)
	} else {
		ResponseError(w, ErrCodeServerBusy)
	}
}

func getLogicalHostHandler(w http.ResponseWriter, r *http.Request) {
	infoRes, code := usdatabasetools.SelectionLogicalService()
	if code == 0 {
		ResponseData(w, infoRes)
	} else {
		ResponseError(w, ErrCodeServerBusy)
	}
}
