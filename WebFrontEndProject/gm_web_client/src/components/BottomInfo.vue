<!-- 
此组件使用京东UI库实现，
此组件有static占位DIV，
必须加入到页面流最底部，
否则占位DIV会使页面布局不正确 
-->
<template>
		<div v-show="isShow" v-bind:id="divID">
			<nut-tabbar type="card" v-on:tab-switch="tabSwitch" v-bind:tabbar-list="tabList" v-bind:bottom="true" style="margin-top:0;"></nut-tabbar>
			<nut-tabbar type="card" v-bind:tabbar-list="tabList" style="visibility:hidden;margin-top:0;"></nut-tabbar>
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
	name: 'BottomInfo',
	components: {
	},
	data: function () {
		return {
			isShow: false,
			divID: 'bottom-info-id-div',
			tabList: [
				{
					'tabTitle': '主页',
					'curr': false,
					'routeName': 'Home'
				},
				{
					'tabTitle': '关于',
					'curr': false,
					'routeName': 'About'
				}
			]
		}
	},
	methods: {
		tabSwitch: function(value, index) {
			if (value.routeName !== this.$router.currentRoute.name) {
				this.$router.push({name: value.routeName, });
			}
		},
		resetShowInfo: function() {
			let adminNameB64 = cookies.getAdminName();
			this.isShow = !!adminNameB64;
			if (this.isShow) {
				this.adminName = Base64.decode(adminNameB64);
				for(let k in this.tabList) {
					this.tabList[k].curr = false; /* watch只对变量值有改变时才响应，所以这里必须先全部置为false */
					if (this.tabList[k].routeName === this.$router.currentRoute.name) {
						this.tabList[k].curr = true;
					}
				}
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
#bottom-info-id-div {
	display: block;
	position: static;
	width: 100%;
	height: auto;
}
</style>