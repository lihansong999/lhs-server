package fwtools

import (
	"sync"
)

// GoSafeMapStringString 线程安全map[string]string
type GoSafeMapStringString struct {
	m map[string]string
	l sync.Mutex
}

// Set 设置
func (p *GoSafeMapStringString) Set(key string, value string) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		p.m = map[string]string{}
	}
	p.m[key] = value
}

// Get 得到
func (p *GoSafeMapStringString) Get(key string) string {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return ""
	}
	return p.m[key]
}

// Range 遍历
func (p *GoSafeMapStringString) Range(handler func(string, string)) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return
	}
	for key, value := range p.m {
		handler(key, value)
	}
}

// Len 大小
func (p *GoSafeMapStringString) Len() int {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return 0
	}
	return len(p.m)
}

// Delete 删除
func (p *GoSafeMapStringString) Delete(key string) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return
	}
	delete(p.m, key)
}

// Reset 重置，传nil为clear
func (p *GoSafeMapStringString) Reset(m map[string]string) {
	p.l.Lock()
	defer p.l.Unlock()
	p.m = m
}

// GoSafeMapIntString 线程安全map[int]string
type GoSafeMapIntString struct {
	m map[int]string
	l sync.Mutex
}

// Set 设置
func (p *GoSafeMapIntString) Set(key int, value string) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		p.m = map[int]string{}
	}
	p.m[key] = value
}

// Get 得到
func (p *GoSafeMapIntString) Get(key int) string {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return ""
	}
	return p.m[key]
}

// Range 遍历
func (p *GoSafeMapIntString) Range(handler func(int, string)) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return
	}
	for key, value := range p.m {
		handler(key, value)
	}
}

// Len 大小
func (p *GoSafeMapIntString) Len() int {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return 0
	}
	return len(p.m)
}

// Delete 删除
func (p *GoSafeMapIntString) Delete(key int) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return
	}
	delete(p.m, key)
}

// Reset 重置，传nil为clear
func (p *GoSafeMapIntString) Reset(m map[int]string) {
	p.l.Lock()
	defer p.l.Unlock()
	p.m = m
}

// GoSafeMapStringInterface 线程安全map[string]Interface{}
type GoSafeMapStringInterface struct {
	m map[string]interface{}
	l sync.Mutex
}

// Set 设置
func (p *GoSafeMapStringInterface) Set(key string, value interface{}) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		p.m = map[string]interface{}{}
	}
	p.m[key] = value
}

// Get 得到
func (p *GoSafeMapStringInterface) Get(key string) interface{} {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return ""
	}
	return p.m[key]
}

// Range 遍历
func (p *GoSafeMapStringInterface) Range(handler func(string, interface{})) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return
	}
	for key, value := range p.m {
		handler(key, value)
	}
}

// Len 大小
func (p *GoSafeMapStringInterface) Len() int {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return 0
	}
	return len(p.m)
}

// Delete 删除
func (p *GoSafeMapStringInterface) Delete(key string) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return
	}
	delete(p.m, key)
}

// Reset 重置，传nil为clear
func (p *GoSafeMapStringInterface) Reset(m map[string]interface{}) {
	p.l.Lock()
	defer p.l.Unlock()
	p.m = m
}

// GoSafeMapIntInterface 线程安全map[int]Interface{}
type GoSafeMapIntInterface struct {
	m map[int]interface{}
	l sync.Mutex
}

// Set 设置
func (p *GoSafeMapIntInterface) Set(key int, value interface{}) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		p.m = map[int]interface{}{}
	}
	p.m[key] = value
}

// Get 得到
func (p *GoSafeMapIntInterface) Get(key int) interface{} {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return ""
	}
	return p.m[key]
}

// Range 遍历
func (p *GoSafeMapIntInterface) Range(handler func(int, interface{})) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return
	}
	for key, value := range p.m {
		handler(key, value)
	}
}

// Len 大小
func (p *GoSafeMapIntInterface) Len() int {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return 0
	}
	return len(p.m)
}

// Delete 删除
func (p *GoSafeMapIntInterface) Delete(key int) {
	p.l.Lock()
	defer p.l.Unlock()
	if p.m == nil {
		return
	}
	delete(p.m, key)
}

// Reset 重置，传nil为clear
func (p *GoSafeMapIntInterface) Reset(m map[int]interface{}) {
	p.l.Lock()
	defer p.l.Unlock()
	p.m = m
}
