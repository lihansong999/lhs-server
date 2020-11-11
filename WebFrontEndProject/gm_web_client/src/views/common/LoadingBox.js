import { Loading } from 'element-ui'

let loadingInstance = null;

const LoadingBox = {
	show: function(content) {
		loadingInstance = Loading.service({
			body: true, // 是否插入至 DOM 中的 body 上
			fullscreen: true, // 是否全屏
			lock: true, // 是否锁定屏幕的滚动
			text: (typeof content === 'string') ? (content) : ('加载中...') // 显示在加载图标下方的加载文案
		});
	},
	hide: function() {
		if (loadingInstance) {
			loadingInstance.close();
			loadingInstance = null;
		}
	}
};

export { LoadingBox };