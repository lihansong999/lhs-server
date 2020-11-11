package main

import (
	"WebServer/Framework/fwconsolecmd"
	_ "WebServer/Framework/fwlogsetting"
	_ "WebServer/UserServer/CodeModules/usconsolecmd"
	"WebServer/UserServer/CodeModules/usdatabasetools"
	"WebServer/UserServer/CodeModules/usglobal"
	"WebServer/UserServer/CodeModules/usresponse"
	"fmt"
	"log"
	"strconv"
)

// 所有模块初始化，调用各个模块的 InitForMain 函数
func initAllModules() bool {
	if !usglobal.InitForMain() {
		return false
	}
	if !usdatabasetools.InitForMain() {
		return false
	}
	if !usresponse.InitForMain() {
		return false
	}

	// 在此添加模块初始化代码
	// ...

	return true
}

func main() {
	// 初始化其他所有模块
	if !initAllModules() {
		return
	}

	// 服务开始
	ch := make(chan string, 1)
	go func(c chan string) {
		defer func() {
			c <- "http service ended"
		}()
		var addr string = ":" + strconv.Itoa(int(usglobal.WebServerConfig.Port))
		fmt.Println("http service start, port" + addr)
		err := usresponse.ListenAndServe(addr)
		if err != nil {
			log.Println(err)
		}
	}(ch)
	fwconsolecmd.Run()
	fmt.Println(<-ch)
}
