/*
The 'core-js/stable' and 'regenerator-runtime/runtime' has been automatically imported
As of Babel 7.4.0, this package has been deprecated in favor of directly
including core-js/stable (to polyfill ECMAScript features) and
regenerator-runtime/runtime (needed to use transpiled generator functions):
*/
//import 'core-js/stable'
//import 'regenerator-runtime/runtime'

//import Vue from 'vue'
import Vue from 'vue/dist/vue.runtime.esm.js'
//import Vue from 'vue/dist/vue.esm.js'

/* ElementUI */
import ElementUI from 'element-ui'
import 'element-ui/lib/theme-chalk/index.css'
Vue.use(ElementUI);

/* nutui */
import NutUI from '@nutui/nutui'
import '@nutui/nutui/dist/nutui.css'
NutUI.install(Vue);

/* axios request */
import { Request } from '@/request'
Vue.prototype.$Request = Request;

import App from '@/App.vue'
import router from '@/router'
import store from '@/store'

Vue.config.productionTip = false;

// 全局路由前置守卫
router.beforeEach((to, from, next) => {
	if (to.name === 'Login' || store.state.LoginStore.IsLogged) {
		next();
	} else {
		next({ 
			name: 'Login',
			params: {
				loggedJump: { 
					name: to.name,
					params: to.params
				}
			}
		});
	}
});

new Vue({
	router,
	store,
	render: h => h(App)
}).$mount('#app');
