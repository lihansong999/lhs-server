package usresponse

import (
	//"WebServer/Framework/fwmysqlhelper"
	//"WebServer/Framework/fwredishelper"
	//"WebServer/UserServer/CodeModules/usdatabasetools"
	//"WebServer/UserServer/CodeModules/usglobal"
	//"encoding/json"
	//"fmt"
	//"log"
	"net/http"
	//"strconv"
	"strings"
)

func initAssets() bool {

	// 文件资源服务
	HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		if r.Method != "GET" {
			http.Error(w, "Method not allowed", http.StatusMethodNotAllowed)
			return
		}
		if strings.HasPrefix(r.URL.Path, "/lhs_resources") {
			http.ServeFile(w, r, "./WebResources/lhs_resources"+strings.Replace(r.URL.Path, "/lhs_resources", "", 1))
		} else {
			http.ServeFile(w, r, "./WebResources/FrontEndPackage"+r.URL.Path)
		}
		return
	})

	return true
}
