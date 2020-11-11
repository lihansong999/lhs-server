package gmdatabasetools

import (
	"WebServer/Framework/fwmysqlhelper"
	"WebServer/Framework/fwtools"
	"fmt"
	"log"
)

// ScriptSha1Map Redis脚本Sha1表
var ScriptSha1Map = fwtools.GoSafeMapStringString{}

// ReloadRedisScriptSha1 从MySQL重新加载所有Redis脚本Sha1到内存中
func ReloadRedisScriptSha1() bool {
	multiQueryResult, err := MySQLHelper.Query("SELECT `filename`, `sha1` FROM `redis_script_info`")
	if err != nil {
		log.Println("在MySQL中查找Redis脚本Sha1失败：", err)
		return false
	}
	singleQueryResult := fwmysqlhelper.GetSingleQueryResult(multiQueryResult, 0)
	if singleQueryResult == nil {
		log.Println("在MySQL中查找Redis脚本Sha1失败，没有查询结果！")
		return false
	}
	if len(*singleQueryResult) == 0 {
		fmt.Println("MySQL中没有任何Redis脚本的sha1")
		return true
	}
	ssm := map[string]string{}
	for _, rowResult := range *singleQueryResult {
		filename, _ := rowResult["filename"]
		sha1, _ := rowResult["sha1"]
		ssm[string(filename)] = string(sha1)
	}
	ScriptSha1Map.Reset(ssm)
	fmt.Println("Redis脚本sha1载入成功")
	return true
}
