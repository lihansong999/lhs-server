import Cookies from 'js-cookie' // https://github.com/js-cookie/js-cookie
import { globalConst } from '@/common/globalConst.js'

const CookiesEx = {
	set: function(k, ...args) {
		return Cookies.set(globalConst.projectName + k, ...args)
	},
	get: function(k, ...args) {
		return Cookies.get(globalConst.projectName + k, ...args)
	},
	remove: function(k, ...args) {
		return Cookies.remove(globalConst.projectName + k, ...args)
	}
};

export { CookiesEx }