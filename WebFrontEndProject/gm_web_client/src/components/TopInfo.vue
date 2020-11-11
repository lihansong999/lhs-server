<!-- 
此组件使用饿了么UI库实现，
此组件有static占位DIV，
必须加入到页面流最顶部，
否则占位DIV会使页面布局不正确 
-->
<template>
		<!-- 跟随虚的子DIV大小变化，用于真正占位的DIV -->
		<div v-show="isShow" v-bind:id="mainDivID">
			<!-- 隐藏的虚DIV，只用于使父DIV大小随之变化 -->
			<div v-bind:id="virtualDivID">
				<el-button type="text" icon="el-icon-circle-close" style="font-size:1.1em;">管理员：{{ adminName }}</el-button>
			</div>
			<!-- 锁定到屏幕顶部的真实DIV -->
			<div v-bind:id="realDivID">
				<el-button type="text" v-on:click.stop="inputLogout" icon="el-icon-circle-close" style="font-size:1.1em;">管理员：{{ adminName }}</el-button>
			</div>
		</div>
</template>

<script>
//import { MessageAir } from '@/views/common/MessageAir.js'
import { LoadingBox } from '@/views/common/LoadingBox.js'
import { MessageBox } from '@/views/common/MessageBox.js'
import { cookies } from '@/cookies'
//import { Base64 } from 'js-base64' // nonsupport IE /* base64 https://github.com/dankogai/js-base64 */
import { Base64 } from '@/third_party/js-base64-support-ie/base64.es6.js' // support IE /* https://github.com/dankogai/js-base64#if-you-really-really-need-an-es5-version */

export default {
	name: 'TopInfo',
	components: {
	},
	data: function () {
		return {
			isShow: false,
			mainDivID: 'top-info-id-main-div',
			virtualDivID: 'top-info-id-virtual-div',
			realDivID: 'top-info-id-real-div',
			adminName : ''
		}
	},
	methods: {
		inputLogout: function() {
			MessageBox.confirm('是否注销<' + this.adminName + '>？').then(function() {
				LoadingBox.show('注销中...');
				this.$Request.req('/api/logoutReq', null)
					.then(function (data) {
						LoadingBox.hide();
						if (data.Error) {
							return;
						}
						this.$router.push({
							name: 'Login', 
							params: {
								loggedJump: { 
									name: 'Home'
								}
							}
						});
					}.bind(this))
					.catch(function (error) {
						LoadingBox.hide();
					}.bind(this));
			}.bind(this)).catch(function() {
			}.bind(this));
		},
		resetShowInfo: function() {
			let adminNameB64 = cookies.getAdminName();
			this.isShow = !!adminNameB64;
			if (this.isShow) {
				this.adminName = Base64.decode(adminNameB64);
			}
		}
	},
	computed: {
	},
	mounted: function() {
		this.resetShowInfo();
	},
	activated: function() {
		this.resetShowInfo();
	}
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
#top-info-id-main-div {
	display: block;
	position: static;
	width: 100%;
	height: auto;
}
#top-info-id-virtual-div {
	display: block;
	position: static;
	visibility:hidden;
	width: 100%;
	height: auto;
	box-sizing: border-box;
	text-align: right;
	padding: 0px 15px 0px 15px;
	background-color: #B3C0D1;
}
#top-info-id-real-div {
	display: block;
	position: fixed;
	width: 100%;
	height: auto;
	top: 0px;
	box-sizing: border-box;
	text-align: right;
	padding: 0px 15px 0px 15px;
	background-color: #B3C0D1;
}
</style>