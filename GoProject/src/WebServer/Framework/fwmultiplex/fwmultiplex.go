package fwmultiplex

import (
	"net/http"
)

// ServeMuxEx 多路复用器扩展
type ServeMuxEx struct {
	http.ServeMux
}

// 单例
var dnstanceMux = &ServeMuxEx{}

// GetInstance 获取单例
func GetInstance() *ServeMuxEx {
	return dnstanceMux
}

// Handle registers the handler for the given pattern
func Handle(pattern string, handler http.Handler) {
	dnstanceMux.Handle(pattern, handler)
}

// HandleFunc registers the handler function for the given pattern
func HandleFunc(pattern string, handler func(http.ResponseWriter, *http.Request)) {
	dnstanceMux.HandleFunc(pattern, handler)
}
