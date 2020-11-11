package gmresponse

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
	if mustLoggedIn(pattern) == false {
		fwmultiplex.HandleFunc(pattern, handler)
	} else {
		fwmultiplex.HandleFunc(pattern, func(w http.ResponseWriter, r *http.Request) {
			if isLoggedIn, _ := CheckLoggedInForRes(w, r); isLoggedIn == false {
				return
			}
			handler(w, r)
		})
	}
}

// ListenAndServe http
func ListenAndServe(addr string) error {
	return fwhttpserver.ListenAndServe(addr, fwmultiplex.GetInstance())
}

// ListenAndServeTLS https
func ListenAndServeTLS(addr, certFile, keyFile string) error {
	return fwhttpserver.ListenAndServeTLS(addr, certFile, keyFile, fwmultiplex.GetInstance())
}

func mustLoggedIn(pattern string) bool {
	switch pattern {
	case "/":
		return false
	case "/api/loginReq":
		return false
	case "/api/logoutReq":
		return false
	}
	return true
}
