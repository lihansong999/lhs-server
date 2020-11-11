import { localStorageEx } from './localStorageEx.js'
/*
本地存储，只能用来优化体验，功能逻辑不可依赖此存储来实现，
功能逻辑相关的状态存储控制只能用@/store模块来实现。
*/

/*
在localStore里面扩充方法，操作localStorageEx模块进行存储，
注意key不能重复，同源不同工程也不能重复，所以格式定为如下：
	前后端统一的工程名 + Key名
	localStorageEx模块中会自动加入工程名
*/
const localStore = {
	setIsRememberAccount: function(v) {
		localStorageEx.setItem('IsRememberAccount', (v)?('1'):(''));
	},
	getIsRememberAccount: function() {
		return !!localStorageEx.getItem('IsRememberAccount');
	},
	setLastAccount: function(v) {
		localStorageEx.setItem('LastAccount', v);
	},
	getLastAccount: function() {
		let r = localStorageEx.getItem('LastAccount')
		return (typeof r === 'string')?(r):('');
	},
	
	/* 这这里添加新操作 */
	
};

export { localStore }