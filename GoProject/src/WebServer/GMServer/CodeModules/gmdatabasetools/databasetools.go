package gmdatabasetools

import (
	"WebServer/Framework/fwmysqlhelper"
	"WebServer/Framework/fwredishelper"
	"WebServer/GMServer/CodeModules/gmglobal"
	"fmt"
	//"github.com/gomodule/redigo/redis"
	"log"
	"strconv"
)

// MySQLHelper fwmysqlhelper.MySQLHelper实例
var MySQLHelper *fwmysqlhelper.MySQLHelper

// RedisHelper fwredishelper.RedisHelper实例
var RedisHelper *fwredishelper.RedisHelper

func initDatabaseTools() bool {
	MySQLHelper = fwmysqlhelper.New()
	err := MySQLHelper.Open(gmglobal.WebServerConfig.MySQL.Host, gmglobal.WebServerConfig.MySQL.Username, gmglobal.WebServerConfig.MySQL.Password, gmglobal.WebServerConfig.MySQL.Database, gmglobal.WebServerConfig.MySQL.Port, "utf8mb4", 8, 20, 20)
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
	var redisHost string = gmglobal.WebServerConfig.Redis.Host + ":" + strconv.Itoa(int(gmglobal.WebServerConfig.Redis.Port))
	RedisHelper.Init(redisHost, gmglobal.WebServerConfig.Redis.Password, gmglobal.WebServerConfig.Redis.Select, 8, 20)
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
