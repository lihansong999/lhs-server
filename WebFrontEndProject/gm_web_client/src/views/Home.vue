<template>
	<div v-bind:class="divClass">
		<top-info></top-info>
		<p>此页开头</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>暂无任何内容</p>
		<p>此页结尾</p>
		<bottom-Info></Bottom-info>
	</div>
</template>

<script>
import TopInfo from '@/components/TopInfo.vue'
import BottomInfo from '@/components/BottomInfo.vue'

export default {
	name: 'Home',
	components: {
		TopInfo,
		BottomInfo
	},
	data: function () {
		return {
			divClass: 'home-class-div'
		}
	},
	methods: {
	},
	mounted: function() {
	},
	activated: function() {
	},
	deactivated: function() {
	},
	beforeDestroy: function() {
	}
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.home-class-div {
	display: block;
	position: absolute;
	width: 100%;
	height: 100%;
	text-align: center;
}
</style>