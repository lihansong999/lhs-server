import { globalConst } from '@/common/globalConst.js'

let lsObj = localStorage;
if (typeof lsObj === 'undefined') {
	/*
	如果浏览器不支持localStorage，就创建一个临时存储器，保证程序正常运行。
	*/
	function lhsStoragePrototype() {
		this.setItem = function(k, v) {
			if (typeof v === 'string'){
				this[k] = v;
			} else {
				this[k] = String(v);	
			}
		}
		this.getItem = function(k) {
			let v = this[k];
			if (typeof v === 'undefined') {
				return null;
			} else {
				return v;
			}
		}
		this.removeItem = function(k) {
			this[k] = null;
		}
		this.clear = function() {
			lsObj = new lhsStorage();
			// for(var k in this){
			// 	delete this[k];
			// }
		}
	}
	function lhsStorage() {
	}
	lhsStorage.prototype = new lhsStoragePrototype();
	lsObj = new lhsStorage();
}

const localStorageEx = {
	setItem: function(k, v) {
		lsObj.setItem(globalConst.projectName + k, v);
	},
	getItem: function(k) {
		return lsObj.getItem(globalConst.projectName + k);
	},
	removeItem: function(k) {
		lsObj.removeItem(globalConst.projectName + k);
	},
	clear: function() {
		lsObj.clear();
	}
};

export { localStorageEx };