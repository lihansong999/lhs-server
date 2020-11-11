package gmconsolecmd

import (
	"WebServer/Framework/fwconsolecmd"
	"WebServer/GMServer/CodeModules/gmdatabasetools"
	"WebServer/GMServer/CodeModules/gmglobal"
	"encoding/json"
	"fmt"
	"log"
)

func init() {
	fwconsolecmd.Bind("--showRunConfig", "查看服务器载入的运行配置信息", showRunConfigHandler)
	fwconsolecmd.Bind("--reloadRedisScriptSha1", "从MySQL重新加载所有Redis脚本Sha1到内存中", reloadRedisScriptSha1Handler)
}

func showRunConfigHandler(args ...interface{}) {
	jss, err := json.MarshalIndent(gmglobal.WebServerConfig, "", "   ")
	if err != nil {
		log.Println("gmglobal.WebServerConfig结构体转换到json字符串错误：", err)
	}
	fmt.Println(string(jss))
}

func reloadRedisScriptSha1Handler(args ...interface{}) {
	gmdatabasetools.ReloadRedisScriptSha1()
}
