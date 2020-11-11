import axios from 'axios'
//import { Base64 } from 'js-base64' // nonsupport IE /* base64 https://github.com/dankogai/js-base64 */
import { Base64 } from '@/third_party/js-base64-support-ie/base64.es6.js' // support IE /* https://github.com/dankogai/js-base64#if-you-really-really-need-an-es5-version */
import router from '@/router'
import store from '@/store'
import { MessageAir } from '@/views/common/MessageAir.js'

const SvrErrCodes = {
	ErrCodeNotAPI: 1,			// 找不到API
	ErrCodeUnknown: 2,			// 未知错误
	ErrCodeParseForm: 3,		// 解析参数错误
	ErrCodeParseJSON: 4,		// 解析json错误
	ErrCodeIllegalParm: 5,		// 非法参数
	ErrCodeServerBusy: 6,		// 服务器繁忙
	ErrCodeNotLogged: 7,		// 非法操作，尚未登录
};

const Request = {
	pack: function(obj) {
		if (typeof obj !== 'object') {
			return Base64.encode('{}');
		}
		let jsonStr = JSON.stringify(obj);
		return Base64.encodeURI(jsonStr); // '+'->'-' '/'->'_' NoPadding
	},
	unpack: function(data) {
		/*eslint no-param-reassign:0*/
		if (typeof data === 'string') {
			try {
				data = JSON.parse(data);
			} catch (e) { /* Ignore */ }
		}
		return data;
	},
	req: function(api, obj) {
		return new Promise(function (resolve, reject) {
			axios.post(api, 'data=' + Request.pack(obj), {
				/*
				设置baseURL，Vue-CLI axios在开发模式下的跨域，配合vue.config.js中的proxy,
				proxy参考https://github.com/chimurai/http-proxy-middleware
				*/
				baseURL: (typeof process === 'object' && process.env && process.env.NODE_ENV === 'development' /* production */)?('/dev_cross'):(null),
				timeout: 12000,
				withCredentials: true,
				responseType: 'text',
				transformResponse: [function (data) {
					return Request.unpack(data);
				}],
				validateStatus: function (status) {
					return status == 200;
				}
			})
			.then(function (response) {
				if (response.data.Error) {
					if (response.data.Error.Code === SvrErrCodes.ErrCodeNotLogged) {
						store.commit('LoginStore/setIsLogged', false);
						if (router.currentRoute.name !== 'Login') {
							router.push({
								name: 'Login', 
								params: {
									loggedJump: { 
										name: router.currentRoute.name,
										params: router.currentRoute.params
									}
								}
							});
						}
					} else {
						MessageAir.show(response.data.Error.Info);
					}
				}
				resolve(response.data);
			})
			.catch(function (error) {
				MessageAir.show(error);
				reject(error);
			});
		});
	}
};
export { Request, SvrErrCodes }

// 原型链继承加super调用的样例(所有子类实例共享同一个父类实例)
// function ParentClassCtor() {
// 	this.value = 'parent value';
// 	this.func = function() {
// 		alert(this.value);
// 	}
// }
// function ChildClassCtor() {
// 	this.value = 'child value';
// 	this.value2 = 'child value2';
// }
// ChildClassCtor.prototype = new ParentClassCtor();
// var childObj = new ChildClassCtor();
// childObj.__proto__.func();
// Object.getPrototypeOf(childObj).func();
// childObj.__proto__.func.call(childObj);
// Object.getPrototypeOf(childObj).func.call(childObj);

// 利用getter/setter监听对象的属性改变的样例
// var obj = {};
// let mappingValue = 0;
// Object.defineProperty(obj, 'value', {
// 	configurable: true, // 当且仅当该属性的 configurable 键值为 true 时，该属性的描述符才能够被改变，同时该属性也能从对应的对象上被删除
// 	enumerable: true, // 当且仅当该属性的 enumerable 键值为 true 时，该属性才会出现在对象的枚举属性中
// 	get: function() {
// 		return mappingValue;
// 	},
// 	set: function(v) {
// 		mappingValue = v;
// 	}
// });
// obj.value = 10;
// alert(obj.value === mappingValue);