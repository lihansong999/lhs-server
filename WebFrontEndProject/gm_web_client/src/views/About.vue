<template>
	<div v-bind:class="divClass">
		<el-container style="height:100%;">
			<el-header height="auto" style="padding:0px 0px 0px 0px;">
				<top-info></top-info>
			</el-header>
			<el-container>
				<el-header height="auto" style="background-color:#B3C0D1;">
					<p>顶栏：</p>
				</el-header>
				<el-container>
					<el-aside width="auto" style="background-color:#D3DCE6;">
						<p>侧边栏：</p>
					</el-aside>
					<el-main v-bind:class="mainClass">
						<p>此页开头</p>
						<p style="text-shadow:1px 1px #F0F0F0;">主要区域：</p>
						<p><strong style="font-size:1.1em;text-shadow:1px 1px #F0F0F0;">关于</strong></p>
						<p><span style="text-shadow:1px 1px #F0F0F0;" v-html="description"></span></p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>暂无更多内容</p>
						<p>此页结尾</p>
					</el-main>
				</el-container>
				<el-footer height="auto" style="background-color:#B3C0D1;">
					<p>底栏：</p>
				</el-footer>
			</el-container>
			<el-footer height="auto" style="padding:0px 0px 0px 0px;">
				<bottom-Info></Bottom-info>
			</el-footer>
		</el-container>
	</div>
</template>

<script>
import { MessageAir } from '@/views/common/MessageAir.js'
import { LoadingBox } from '@/views/common/LoadingBox.js'
//import { MessageBox } from '@/views/common/MessageBox.js'
import TopInfo from '@/components/TopInfo.vue'
import BottomInfo from '@/components/BottomInfo.vue'

export default {
	name: 'About',
	components: {
		TopInfo,
		BottomInfo
	},
	data: function () {
		return {
			divClass: 'about-class-div',
			mainClass: 'about-class-main',
			description: ''
		}
	},
	methods: {
		requestDescription: function() {
			LoadingBox.show();
			this.$Request.req('/api/aboutReq', null)
				.then(function (data) {
					LoadingBox.hide();
					if (data.Error) {
						return;
					}
					this.description = data.Description;
				}.bind(this))
				.catch(function (error) {
					LoadingBox.hide();
				}.bind(this));
		}
	},
	computed: {
	},
	mounted: function() {
		this.requestDescription();
	},
	activated: function() {
		this.requestDescription();
	}
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.about-class-div {
	display: block;
	position: absolute;
	width: 100%;
	height: 100%;
	text-align: center;
}
.about-class-main {
	background-color: #E9EEF3;
	background-image: url('../assets/background.jpg');
	background-size: cover;
	background-repeat: no-repeat;
}
</style>