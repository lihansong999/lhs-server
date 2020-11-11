package usglobal

import (
	"encoding/json"
	"io/ioutil"
	"log"
)

// MySQLConfig MySQL配置信息
type MySQLConfig struct {
	Host     string
	Port     int32
	Username string
	Password string
	Database string
}

// RedisConfig Redis配置信息
type RedisConfig struct {
	Host     string
	Port     int32
	Password string
	Select   int32
}

// CenterConfig 中心服务器配置信息
type CenterConfig struct {
	Host string
	Port int32
}

// WebConfig Web服务器配置
type WebConfig struct {
	Port   int32
	MySQL  MySQLConfig
	Redis  RedisConfig
	Center CenterConfig
}

// WebServerConfig 配置
var WebServerConfig = &WebConfig{}

func loadWebConfig() bool {
	fileData, err := ioutil.ReadFile("./WebConfig/RunConfig.json")
	if err != nil {
		log.Println("读取配置文件错误：", err.Error())
		return false
	}
	err = json.Unmarshal(fileData, WebServerConfig)
	if err != nil {
		log.Println("解析配置文件错误：", err)
		return false
	}
	return true
}
