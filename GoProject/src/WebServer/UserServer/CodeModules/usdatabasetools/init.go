package usdatabasetools

// InitForMain 在main模块的initAllModules函数中调用执行初始化
func InitForMain() bool {
	if !initDatabaseTools() {
		return false
	}

	// 在此添加初始化代码
	// ...

	return true
}
