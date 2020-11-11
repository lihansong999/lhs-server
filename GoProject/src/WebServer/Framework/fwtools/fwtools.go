package fwtools

import (
	"fmt"
	"os"
	"path/filepath"
)

func init() {
	fmt.Println("ModuleFileName:", GetModuleFileName())
	fmt.Println("ModuleFileDirectory:", GetModuleFileDirectory())
}

// GetModuleFileName 获取当前执行文件全路径
func GetModuleFileName() string {
	path, _ := filepath.Abs(os.Args[0])
	return path
}

// GetModuleFileDirectory 获取当前执行文件所在目录，不包含末尾'\\'
func GetModuleFileDirectory() string {
	dir := filepath.Dir(GetModuleFileName())
	return dir
}
