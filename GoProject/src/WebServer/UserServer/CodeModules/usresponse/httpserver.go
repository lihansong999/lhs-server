package usresponse

import (
	"WebServer/Framework/fwhttpserver"
	"WebServer/Framework/fwmultiplex"
	"net/http"
)

// Handle registers the handler for the given pattern
func Handle(pattern string, handler http.Handler) {
	fwmultiplex.Handle(pattern, handler)
}

// HandleFunc registers the handler function for the given pattern
func HandleFunc(pattern string, handler func(http.ResponseWriter, *http.Request)) {
	fwmultiplex.HandleFunc(pattern, handler)
}

// ListenAndServe http
func ListenAndServe(addr string) error {
	return fwhttpserver.ListenAndServe(addr, fwmultiplex.GetInstance())
}

// ListenAndServeTLS https
func ListenAndServeTLS(addr, certFile, keyFile string) error {
	return fwhttpserver.ListenAndServeTLS(addr, certFile, keyFile, fwmultiplex.GetInstance())
}
