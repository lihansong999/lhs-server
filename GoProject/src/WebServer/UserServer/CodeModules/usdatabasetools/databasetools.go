package usdatabasetools

import (
	"WebServer/Framework/fwmysqlhelper"
	"WebServer/Framework/fwredishelper"
	"WebServer/UserServer/CodeModules/usglobal"
	"fmt"
	"github.com/gomodule/redigo/redis"
	"log"
	"strconv"
)

// MySQLHelper fwmysqlhelper.MySQLHelper实例
var MySQLHelper *fwmysqlhelper.MySQLHelper

// RedisHelper fwredishelper.RedisHelper实例
var RedisHelper *fwredishelper.RedisHelper

func initDatabaseTools() bool {
	MySQLHelper = fwmysqlhelper.New()
	err := MySQLHelper.Open(usglobal.WebServerConfig.MySQL.Host, usglobal.WebServerConfig.MySQL.Username, usglobal.WebServerConfig.MySQL.Password, usglobal.WebServerConfig.MySQL.Database, usglobal.WebServerConfig.MySQL.Port, "utf8mb4", 8, 20, 20)
	if err != nil {
		log.Println("数据库Open失败：", err)
		return false
	}
	err = MySQLHelper.Ping()
	if err != nil {
		log.Println("数据库连接失败：", err)
		return false
	}
	fmt.Println("数据库连接成功")

	RedisHelper = fwredishelper.New()
	var redisHost string = usglobal.WebServerConfig.Redis.Host + ":" + strconv.Itoa(int(usglobal.WebServerConfig.Redis.Port))
	RedisHelper.Init(redisHost, usglobal.WebServerConfig.Redis.Password, usglobal.WebServerConfig.Redis.Select, 8, 20)
	err = RedisHelper.Connect()
	if err != nil {
		log.Println("Redis连接失败：", err)
		return false
	}
	fmt.Println("Redis连接成功")

	if !ReloadRedisScriptSha1() {
		return false
	}

	return true
}

// LobbyServerSelectionInfoRes 选择大厅服务器返回的信息结构
type LobbyServerSelectionInfoRes struct {
	LobbyServerID int
	Address       string
	TCPPort       int `json:"TcpPort"`
	WsPort        int
}

// LogicalServerSelectionInfoRes 选择逻辑服务器返回的信息结构
type LogicalServerSelectionInfoRes struct {
	LogicalServerID int
	Address         string
	TCPPort         int `json:"TcpPort"`
	WsPort          int
}

// SelectionLobbyService return: 0成功, -1没有查询到匹配的服务器信息, -2错误
func SelectionLobbyService() (LobbyServerSelectionInfoRes, int) {
	info := LobbyServerSelectionInfoRes{}
	reply, err := RedisHelper.Command("EVALSHA", ScriptSha1Map.Get("SelectionLobbyService.lua"), 0)
	if err != nil {
		return info, -2
	}
	arr, err := redis.Values(reply, err)
	if err != nil || len(arr) != 4 {
		return info, -1
	}
	_, err = redis.Scan(arr, &info.Address, &info.TCPPort, &info.WsPort, &info.LobbyServerID)
	if err != nil {
		return info, -2
	}
	return info, 0
}

// SelectionLogicalService return: 0成功, -1没有查询到匹配的服务器信息, -2错误
func SelectionLogicalService() (LogicalServerSelectionInfoRes, int) {
	info := LogicalServerSelectionInfoRes{}
	reply, err := RedisHelper.Command("EVALSHA", ScriptSha1Map.Get("SelectionLogicalService.lua"), 0)
	if err != nil {
		return info, -2
	}
	arr, err := redis.Values(reply, err)
	if err != nil || len(arr) != 4 {
		return info, -1
	}
	_, err = redis.Scan(arr, &info.Address, &info.TCPPort, &info.WsPort, &info.LogicalServerID)
	if err != nil {
		return info, -2
	}
	return info, 0
}
