import { CookiesEx } from './js-cookie-ex.js'
/*
在cookies里面扩充方法，操作CookiesEx进行存储，
注意前后端key都不能重复，同源不同工程也不能重复，所以格式定为如下：
	后端key格式：前后端统一的工程名 + "svr_" + Key名
	前端key格式：前后端统一的工程名 + 'cli_' + Key名
	前端CookiesEx模块中会自动加入工程名
*/
const cookies = {
	getAdminName: function(v) {
		return CookiesEx.get('svr_adminName')
	},
	
	/* 这这里添加新操作 */
	
};

export { cookies }