// 本模块是对控制台交互的封装
// 调用Bind绑定命令回调
// 找个合适的地方Run即可

package fwconsolecmd

import (
	"WebServer/Framework/fwtools"
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
	"time"
)

type cmdMapValue struct {
	handler func(...interface{})
	desc    string
}

var cmdMap = fwtools.GoSafeMapStringInterface{}

func init() {
	Bind("--help", "帮助", func(args ...interface{}) {
		fmt.Println("命令集：")
		cmdMap.Range(func(key string, value interface{}) {
			if key != "--help" {
				v, ok := value.(*cmdMapValue)
				if ok {
					fmt.Println("  \"" + key + "\"：" + v.desc)
				}
			}
		})
	})
}

// Bind 绑定命令回调
func Bind(cmd string, desc string, handler func(...interface{})) {
	cmdMap.Set(cmd, &cmdMapValue{handler: handler, desc: desc})
}

func call(cmd string, args ...interface{}) {
	value := cmdMap.Get(cmd)
	if value != nil {
		v, ok := value.(*cmdMapValue)
		if ok {
			v.handler(args...)
		}
	} else {
		fmt.Println("找不到命令 \"" + cmd + "\" ，输入 \"--help\" 可查看帮助！")
	}
}

// Run 运行
func Run() {
	inReader := bufio.NewReader(os.Stdin)
	for true {
		inputBytes, err := inReader.ReadBytes('\n')
		if err != nil {
			log.Println("读取输入错误：", err)
			time.Sleep(5 * time.Second)
			continue
		}
		length := len(inputBytes)
		if length > 1 && inputBytes[length-2] == '\r' {
			inputBytes = inputBytes[:length-2]
			length -= 2
		} else {
			inputBytes = inputBytes[:length-1]
			length--
		}
		args := strings.Fields(string(inputBytes))
		length = len(args)
		if length == 1 {
			call(args[0])
		} else if length > 1 {
			argsReal := []interface{}{}
			for k, v := range args {
				if k > 0 {
					argsReal = append(argsReal, v)
				}
			}
			call(args[0], argsReal...)
		}
	}
}
