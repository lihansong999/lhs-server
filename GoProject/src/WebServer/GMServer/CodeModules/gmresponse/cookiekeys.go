package gmresponse

import (
	"WebServer/GMServer/CodeModules/gmglobal"
)

/*
cookie keys 定义文件
注意前后端key都不能重复，同源不同工程也不能重复，所以格式定为如下：
	后端key格式：前后端统一的工程名 + "svr_" + Key名
	前端key格式：前后端统一的工程名 + "cli_" + Key名
*/

// CookieKeyDynaPwd 动态密码
const CookieKeyDynaPwd = gmglobal.ProjectName + "svr_dynaPwd"

// CookieKeyAdminName 管理员姓名
const CookieKeyAdminName = gmglobal.ProjectName + "svr_adminName"
