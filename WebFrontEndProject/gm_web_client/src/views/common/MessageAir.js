import { Message } from 'element-ui'
import './MessageAir.css'

const MessageAir = {
	show: function(content) {
		Message({
				message: content, // 消息文字
				type: 'info', // success/warning/info/error
				customClass: 'lhs-class-message-air',
				duration: 3500, // 显示时间, 毫秒。设为 0 则不会自动关闭
				dangerouslyUseHTMLString: false, // 是否将 message 属性作为 HTML 片段处理
				showClose: false, // 是否显示关闭按钮
				center: true, // 文字是否居中
				offset: 20 // window.screen.availHeight * 0.5 - 70 // Message 距离窗口顶部的偏移量
			});
	}
};

export { MessageAir };