package gmresponse

// InitForMain 在main模块的initAllModules函数中调用执行初始化
func InitForMain() bool {
	if !initAssets() {
		return false
	}
	if !initLogin() {
		return false
	}
	if !initMISC() {
		return false
	}

	// 在此添加初始化代码
	// ...

	return true
}
