module.exports = {
	devServer: {
		https: true, // 开发环境同样是https
		proxy: { // 参考https://github.com/chimurai/http-proxy-middleware
			'/dev_cross': { // Vue-CLI axios在开发模式下的跨域代理，配合request/index.js中的axios.defaults.baseURL
				target: 'https://127.0.0.1:9177', // target host
				secure: false, // if you want to verify the SSL Certs
				changeOrigin: true, // needed for virtual hosted sites
				//ws: true, // proxy websockets
				pathRewrite: {
					//'^/old/api' : '/new/api', // rewrite path
					//'^/remove/api' : '', // remove path
					//'^/' : '/basepath/', // add base path
					'^/dev_cross': ''
				}
			}
		}
	}
}