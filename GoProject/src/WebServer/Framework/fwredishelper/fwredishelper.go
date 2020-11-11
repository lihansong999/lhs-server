// 本模块是对github.com/gomodule/redigo/redis的进一步简单封装
// RedisHelper对象的所有成员方法都是线程安全的
// 使用样例:
// rh := fwredishelper.New()
// rh.Init("127.0.0.1:6379", "654321", 0, 8, 20)
// rh.Connect()
// defer rh.Disconnect()
// reply, err := rh.Command("SET", "name", "lihansong")
// if err == nil && reply == "OK" {
// 	fmt.Println("Set succeed")
// }

package fwredishelper

import (
	"github.com/gomodule/redigo/redis"
	"log"
	"sync"
	"time"
)

// RedisHelper 对象结构体
type RedisHelper struct {
	mutex          sync.Mutex
	conn           redis.Conn
	host           string
	password       string
	selectIndex    int32
	connectTimeOut time.Duration
	rwTimeOut      time.Duration
}

// New 创建一个RedisHelper对象
func New() *RedisHelper {
	return &RedisHelper{}
}

// Init 初始化，在调用RedisHelper对象的其他方法之前至少调用一次
// 多次调用Connect时无需重复Init，除非需要修改初始化值
// Init内部会调用Disconnect，这会让已经建立的连接立刻断开
// host：Redis服务器地址，例如"127.0.0.1:6379"
// passwd：Redis服务器密码，""表示忽略密码
// selectIndex：Redis服务器字典下标，传0为使用默认值
// connectTimeOut：连接Redis服务器的超时时间，传0为使用默认值
// rwTimeOut：连接Redis服务器的套接字读写超时时间，传0为使用默认值
func (p *RedisHelper) Init(host string, password string, selectIndex int32, connectTimeOut int32, rwTimeOut int32) {
	p.mutex.Lock()
	defer p.mutex.Unlock()
	p.disconnect()
	p.host = host
	p.password = password
	p.selectIndex = selectIndex
	p.connectTimeOut = time.Duration(connectTimeOut) * time.Second
	p.rwTimeOut = time.Duration(rwTimeOut) * time.Second
}

func (p *RedisHelper) connect() error {
	p.disconnect()
	var err error
	p.conn, err = redis.DialTimeout("tcp", p.host, p.connectTimeOut, p.rwTimeOut, p.rwTimeOut)
	if err != nil {
		p.disconnect()
		log.Println(err)
		return err
	}
	if p.password != "" {
		reply, err := p.conn.Do("AUTH", p.password)
		if err != nil || reply != "OK" {
			p.disconnect()
			log.Println("授权失败：", err)
			return err
		}
	}
	if p.selectIndex != 0 {
		reply, err := p.conn.Do("SELECT", p.selectIndex)
		if err != nil || reply != "OK" {
			p.disconnect()
			log.Println("SELECT失败：", err)
			return err
		}
	}
	return nil
}

// Connect 连接Redis服务器
// 如果初始化时password参数有效，连接后将会自动发送AUTH命令
// 如果初始化时selectIndex!=0，连接后将会自动发送SELECT命令
func (p *RedisHelper) Connect() error {
	p.mutex.Lock()
	defer p.mutex.Unlock()
	return p.connect()
}

func (p *RedisHelper) disconnect() {
	if p.conn != nil {
		p.conn.Close()
		p.conn = nil
	}
}

// Disconnect 断开与Redis服务器的连接
func (p *RedisHelper) Disconnect() {
	p.mutex.Lock()
	defer p.mutex.Unlock()
	p.disconnect()
}

// Ping 检测与Redis服务器的连接状态
// 返回值：
// 	true保持连接中
// 	false无响应
func (p *RedisHelper) Ping() bool {
	p.mutex.Lock()
	defer p.mutex.Unlock()
	if p.conn == nil {
		return false
	}
	reply, err := p.conn.Do("PING")
	if err != nil {
		p.disconnect()
		return false
	}
	value, ok := reply.(string)
	if ok == false || value != "PONG" {
		p.disconnect()
		return false
	}
	return true
}

// Command 执行Redis命令
// 如果尚未连接Redis服务器Command内部将会自动尝试一次连接，但前提是Init设置无误
func (p *RedisHelper) Command(commandName string, args ...interface{}) (interface{}, error) {
	p.mutex.Lock()
	defer p.mutex.Unlock()
	if p.conn == nil {
		err := p.connect()
		if err != nil {
			return nil, err
		}
	}
	//return p.conn.Do(commandName, args...)
	var reply interface{}
	var err error
	err = p.conn.Send(commandName, args...)
	if err != nil {
		p.disconnect()
		return nil, err
	}
	err = p.conn.Flush()
	if err != nil {
		p.disconnect()
		return nil, err
	}
	reply, err = p.conn.Receive()
	if err != nil {
		_, ok := err.(redis.Error)
		if !ok {
			p.disconnect()
		}
		return nil, err
	}
	return reply, nil
}
