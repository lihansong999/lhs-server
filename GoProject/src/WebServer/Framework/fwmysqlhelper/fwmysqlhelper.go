// 本模块是对使用github.com/go-sql-driver/mysql驱动的database/sql模块的进一步简单封装
// MySQLHelper对象的成员方法除了Open和Close之外其余的都是线程安全的，但在调用之前必须先调用Open
// 使用样例:
// mh := fwmysqlhelper.New()
// if mh.Open("127.0.0.1", "root", "654321", "lhs_db", 3306, "utf8mb4", 8, 20, 20) == nil {
// 	defer mh.Close()
// }
// multiQueryResult, err := mh.Query("SELECT * FROM test_table;")
// if err != nil {
// 	if fwmysqlhelper.IsMySQLError(err) {
// 		// 这是MySQL返回的错误
// 	}
// 	if fwmysqlhelper.IsNotExec(err) {
// 		// 只有这种错误才能肯定刚才发送的语句没有被MySQL服务器执行，
// 	}
// } else {
// 	// multiQueryResult的用法查看MultiQueryResult类型定义处注释
// }

package fwmysqlhelper

import (
	"database/sql"
	"database/sql/driver"
	"fmt"
	"github.com/go-sql-driver/mysql"
)

// MySQLHelper 对象结构体
type MySQLHelper struct {
	db             *sql.DB
	host           string
	username       string
	password       string
	database       string
	charSet        string
	connectTimeOut int32
	readTimeOut    int32
	writeTimeOut   int32
	port           int32
}

// New 创建一个MySQLHelper对象
func New() *MySQLHelper {
	return &MySQLHelper{}
}

// IsMySQLError 判断是不是一个MySQL错误
func IsMySQLError(err error) bool {
	if _, ok := err.(*mysql.MySQLError); ok {
		return true
	}
	return false
}

// IsNotExec 用于判断Query或Execute方法的错误返回值是否能确定MySQL尚未执行命令
func IsNotExec(err error) bool {
	return err == driver.ErrBadConn
}

// Open 打开数据库句柄
// 并未立即建立与MySQL服务器的连接，在有必要的时候内部会自动进行连接，
// 如果需要立即连接，可以在Open成功之后调用Ping
func (p *MySQLHelper) Open(host string, username string, password string, database string, port int32, charSet string, connectTimeOut int32, readTimeOut int32, writeTimeOut int32) error {
	if p.db != nil {
		panic("重复Open搞锤子？")
	}
	p.host = host
	p.username = username
	p.password = password
	p.database = database
	p.port = port
	if charSet != "" {
		p.charSet = charSet
	} else {
		p.charSet = "utf8mb4"
	}
	if connectTimeOut > 0 {
		p.connectTimeOut = connectTimeOut
	} else {
		p.connectTimeOut = 0
	}
	if readTimeOut > 0 {
		p.readTimeOut = readTimeOut
	} else {
		p.readTimeOut = 0
	}
	if writeTimeOut > 0 {
		p.writeTimeOut = writeTimeOut
	} else {
		p.writeTimeOut = 0
	}
	dataSourceName := fmt.Sprintf("%s:%s@tcp(%s:%d)/%s?charset=%s&timeout=%ds&readTimeout=%ds&writeTimeout=%ds&multiStatements=%t", p.username, p.password, p.host, p.port, p.database, p.charSet, p.connectTimeOut, p.readTimeOut, p.writeTimeOut, false)
	var err error
	// Open并未建立连接，sql中维护了一个连接池，在有必要的时候才会进行连接
	p.db, err = sql.Open("mysql", dataSourceName)
	return err
}

// Close 关闭数据库句柄
// 很少会使用，一般只会在退出进程的时候才调用
func (p *MySQLHelper) Close() {
	if p.db != nil {
		p.db.Close()
		p.db = nil
	}
}

// GetDB 得到sql.DB指针
// 很少会使用，使用前必须对database/sql和github.com/go-sql-driver/mysql模块足够熟悉
// 一般只用于三种特别的需求：
//   1.事务 https://golang.org/pkg/database/sql/#example_Conn_BeginTx
//   2.预编译语句 https://github.com/go-sql-driver/mysql/wiki/Examples#Prepared-Statements
//   3.对连接池进行设置，例如SetMaxOpenConns
func (p *MySQLHelper) GetDB() *sql.DB {
	if p.db != nil {
		return p.db
	}
	return nil
}

// Ping 检测与数据库服务器的连接
func (p *MySQLHelper) Ping() error {
	return p.db.Ping()
}

// Query 执行查询SQL
// 如果multiStatements=true可多语句查询，不建议使用多语句
// 如果执行INSERT、UPDATE语句将无法在结果集中获得信息，更无法获得affected_rows和insert_id，INSERT、UPDATE建议使用Exec方法
func (p *MySQLHelper) Query(query string, args ...interface{}) (*MultiQueryResult, error) {
	rows, err := p.db.Query(query, args...)
	if err != nil {
		return nil, err
	}
	defer rows.Close()
	return MakeQueryResult(rows)
}

// Exec 执行SQL
// 如果multiStatements=true可多语句执行，不建议使用多语句，无法获得多语句返回的多个结果
// 如果执行SELECT语句将无法在结果中获得信息，SELECT必须使用Query方法
func (p *MySQLHelper) Exec(query string, args ...interface{}) (sql.Result, error) {
	return p.db.Exec(query, args...)
}
