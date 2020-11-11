import { MessageBox as ElmMsgBox } from 'element-ui'
import './MessageBox.css'

const MessageBox = {
	// 只有一个确定按钮
	alert: function(content, title, confirmButtonText) {
		return ElmMsgBox({
				title: (typeof title === 'string') ? (title) : (''), // 标题
				message: content, // 消息正文内容
				dangerouslyUseHTMLString: false, // 是否将 message 属性作为 HTML 片段处理
				type: 'info', // success/info/warning/error
				customClass: 'lhs-class-message-box',
				showClose: false, // 是否显示右上角关闭按钮
				distinguishCancelAndClose: true, // 是否将取消（点击取消按钮）与关闭（点击关闭按钮或遮罩层、按下 ESC 键）进行区分
				lockScroll: true, // 是否将 body 滚动锁定
				showCancelButton: false , // 是否显示取消按钮
				showConfirmButton: true, // 是否显示确定按钮
				cancelButtonText: '取消', // 取消按钮的文本内容
				confirmButtonText: (typeof confirmButtonText === 'string') ? (confirmButtonText) : ('确定'), // 确定按钮的文本内容
				closeOnClickModal: false, // 是否可通过点击遮罩关闭
				closeOnPressEscape: false, // 是否可通过按下 ESC 键关闭
				closeOnHashChange: false, // 是否在 hashchange 时关闭
				showInput: false, // 是否显示输入框
				center: true // 是否居中布局
			});
	},
	// 确定和取消按钮
	confirm: function(content, title, confirmButtonText, cancelButtonText) {
		return ElmMsgBox({
				title: (typeof title === 'string') ? (title) : (''), // 标题
				message: content, // 消息正文内容
				dangerouslyUseHTMLString: false, // 是否将 message 属性作为 HTML 片段处理
				type: 'info', // success/info/warning/error
				customClass: 'lhs-class-message-box',
				showClose: false, // 是否显示右上角关闭按钮
				distinguishCancelAndClose: true, // 是否将取消（点击取消按钮）与关闭（点击关闭按钮或遮罩层、按下 ESC 键）进行区分
				lockScroll: true, // 是否将 body 滚动锁定
				showCancelButton: true , // 是否显示取消按钮
				showConfirmButton: true, // 是否显示确定按钮
				cancelButtonText: (typeof cancelButtonText === 'string') ? (cancelButtonText) : ('取消'), // 取消按钮的文本内容
				confirmButtonText: (typeof confirmButtonText === 'string') ? (confirmButtonText) : ('确定'), // 确定按钮的文本内容
				closeOnClickModal: false, // 是否可通过点击遮罩关闭
				closeOnPressEscape: false, // 是否可通过按下 ESC 键关闭
				closeOnHashChange: false, // 是否在 hashchange 时关闭
				showInput: false, // 是否显示输入框
				center: true // 是否居中布局
			});
	}
};

export { MessageBox };