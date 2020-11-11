package fwlogsetting

import (
	"WebServer/Framework/fwtools"
	"fmt"
	"log"
	"os"
	"runtime"
)

type logWrite struct {
	file     *os.File
	filename string
}

func (l *logWrite) Write(p []byte) (n int, err error) {
	n, err = os.Stderr.Write(p)
	if l.file == nil {
		l.file, err = os.OpenFile(l.filename, os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0666)
		if err != nil {
			os.Stderr.Write([]byte("打开日志文件失败：" + err.Error() + "\n"))
			return n, nil
		}
	}
	n, err = l.file.Write(p)
	return n, err
}

func init() {
	filenameSlice := []byte(fwtools.GetModuleFileName())
	preIndex := 0
	for i := len(filenameSlice) - 1; i >= 0; i-- {
		if filenameSlice[i] == '\\' || filenameSlice[i] == '/' {
			preIndex = i + 1
			break
		}
	}
	nameIndex := len(filenameSlice)
	for i := len(filenameSlice) - 1; i >= 0; i-- {
		if filenameSlice[i] == '.' {
			nameIndex = i
			break
		}
	}
	logfilename := string(filenameSlice[0:preIndex]) + string(filenameSlice[preIndex:nameIndex]) + "_Log.txt"
	fmt.Println("log file path:", logfilename)
	lw := &logWrite{file: nil, filename: logfilename}
	runtime.SetFinalizer(lw, func(obj *logWrite) {
		if obj.file != nil {
			obj.file.Close()
		}
	})
	log.SetOutput(lw)
}
