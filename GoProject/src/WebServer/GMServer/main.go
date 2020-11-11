package main

import (
	"WebServer/Framework/fwconsolecmd"
	_ "WebServer/Framework/fwlogsetting"
	_ "WebServer/GMServer/CodeModules/gmconsolecmd"
	"WebServer/GMServer/CodeModules/gmdatabasetools"
	"WebServer/GMServer/CodeModules/gmglobal"
	"WebServer/GMServer/CodeModules/gmresponse"
	"fmt"
	"log"
	"math/rand"
	"strconv"
	"time"
)

// 所有模块初始化，调用各个模块的 InitForMain 函数
func initAllModules() bool {
	if !gmglobal.InitForMain() {
		return false
	}
	if !gmdatabasetools.InitForMain() {
		return false
	}
	if !gmresponse.InitForMain() {
		return false
	}

	// 在此添加模块初始化代码
	// ...

	return true
}

func main() {

	rand.Seed(time.Now().UnixNano())

	// 初始化其他所有模块
	if !initAllModules() {
		return
	}

	// 服务开始
	ch := make(chan string, 1)
	go func(c chan string) {
		defer func() {
			c <- "https service ended"
		}()
		var addr string = ":" + strconv.Itoa(int(gmglobal.WebServerConfig.Port))
		fmt.Println("https service start, port" + addr)
		err := gmresponse.ListenAndServeTLS(addr, "Certificate/server.crt", "Certificate/server.key")
		if err != nil {
			log.Println(err)
		}
	}(ch)
	fwconsolecmd.Run()
	fmt.Println(<-ch)
}
