import { cookies } from '@/cookies'

export default {
	state: {
		IsLogged: !!cookies.getAdminName() // 通过查看cookie中是否有管理员姓名的记录来判断是否已经登录
	},
	namespaced: true,
	strict: true,
	mutations: {
		setIsLogged: function(state, v) {
			state.IsLogged = v;
		}
	},
	actions: {
	},
	modules: {
	}
}