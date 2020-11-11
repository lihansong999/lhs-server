package fwhttpserver

import (
	"net/http"
)

// ServerEx 服务扩展
type ServerEx struct {
	http.Server
}

// ListenAndServe http
func ListenAndServe(addr string, handler http.Handler) error {
	server := &ServerEx{http.Server{Addr: addr, Handler: handler}}
	return server.ListenAndServe()
}

// ListenAndServeTLS https
func ListenAndServeTLS(addr, certFile, keyFile string, handler http.Handler) error {
	server := &ServerEx{http.Server{Addr: addr, Handler: handler}}
	return server.ListenAndServeTLS(certFile, keyFile)
}
