import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

import LoginStore from './loginStore'

export default new Vuex.Store({
	state: {
	},
	namespaced: true,
	strict: true,
	mutations: {
	},
	actions: {
	},
	modules: {
		LoginStore
	}
})
