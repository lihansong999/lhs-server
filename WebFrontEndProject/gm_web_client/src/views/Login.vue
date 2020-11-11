<template>
	<div v-bind:class="divClass">
		<el-container v-bind:class="containerClass">
			<el-header>
				<h1>系统登录</h1>
			</el-header>
			<el-main>
				<p><el-input v-model="account" type="text" maxlength="12" v-bind:clearable=true placeholder="请输入账号"><template slot="prepend">账号:</template></el-input></p>
				<p><el-input v-model="password" type="text" maxlength="12" v-bind:clearable=true placeholder="请输入密码" show-password v-on:keyup.enter.native="inputLogin"><template slot="prepend">密码:</template></el-input></p>
				<el-switch v-model="remember" active-text="记住账号" active-color="#13CE66" inactive-color="#B0B0B0"></el-switch>
			</el-main>
			<el-footer>
				<el-button type="primary" v-on:click.stop="inputLogin">登录</el-button>
			</el-footer>
		</el-container>
	</div>
</template>

<script>
import { MessageAir } from '@/views/common/MessageAir.js'
import { LoadingBox } from '@/views/common/LoadingBox.js'
//import { MessageBox } from '@/views/common/MessageBox.js'
import { localStore } from '@/localStore'

export default {
	name: 'Login',
	components: {
	},
	props: {
		loggedJump: {
			type: Object,
			//required: true,
			default: function() {
				return { name: 'Home' };
			}
		}
	},
	data: function () {
		return {
			divClass: 'login-class-div',
			containerClass: 'login-class-container',
			account: '',
			password: '',
			remember: false
		}
	},
	watch: {
		'account': {
			handler: function(n, o) {
				n = n.replace(/[^a-zA-Z0-9]/g, '');
				if (n.length > 12) {
					n = n.slice(0, 12);
				}
				this.account = n;
			},
			deep: false,
			immediate: true
		},
		'password': {
			handler: function(n, o) {
				n = n.replace(/[^a-zA-Z0-9]/g, '');
				if (n.length > 12) {
					n = n.slice(0, 12);
				}
				this.password = n;
			},
			deep: false,
			immediate: true
		}
	},
	methods: {
		inputLogin: function() {
			if (this.account.length < 6 || this.account.length > 12) {
				MessageAir.show('请输入正确的账号');
				return
			}
			if (this.password.length < 6 || this.password.length > 12) {
				MessageAir.show('请输入正确的密码');
				return
			}
			LoadingBox.show('登录中...');
			this.$Request.req('/api/loginReq', {
					Username: this.account,
					Password: this.password
				})
				.then(function (data) {
					LoadingBox.hide();
					if (data.Error) {
						return;
					}
					if (!data.Succeed) {
						MessageAir.show(data.ErrInfo);
						return;
					}
					this.saveRememberInfo();
					this.$store.commit('LoginStore/setIsLogged', true);
					this.$router.replace(this.loggedJump);
				}.bind(this))
				.catch(function (error) {
					LoadingBox.hide();
				}.bind(this));
		},
		loadRememberInfo: function() {
			if (localStore.getIsRememberAccount()) {
				this.account = localStore.getLastAccount();
				this.remember = true;
			} else {
				this.account = '';
				this.remember = false;
			}
		},
		saveRememberInfo: function() {
			if (this.remember) {
				localStore.setIsRememberAccount(true);
				localStore.setLastAccount(this.account);
			} else {
				localStore.setIsRememberAccount(false);
				localStore.setLastAccount('');
			}
		}
	},
	computed: {
	},
	beforeCreate: function() {
	},
	created: function() {
	},
	beforeMount: function() {
	},
	mounted: function() {
		this.loadRememberInfo();
	},
	beforeUpdate: function() {
	},
	updated: function() {
	},
	activated: function() {
		this.loadRememberInfo();
		this.password = '';
	},
	deactivated: function() {
		this.password = '';
	},
	beforeDestroy: function() {
	},
	destroyed: function() {
	}
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.login-class-div {
	display: block;
	position: absolute;
	width: 100%;
	height: 100%;
	text-align: center;
}
.login-class-container {
	position: absolute;
	width: 370px;
	height: auto;
	left: 50%;
	top: 50%;
	border-style: outset;
	border-width: 1px;
	border-color: #3A8EE6;
	transform: translate(-50%, -50%); /* 配合left:50%;top:50%;再平移自身保持居中 */
	-ms-transform: translate(-50%, -50%); /* IE 9 */
	-moz-transform: translate(-50%, -50%); /* Firefox */
	-webkit-transform: translate(-50%, -50%); /* Safari 和 Chrome */
	-o-transform: translate(-50%, -50%); /* Opera */
}
@media screen and (min-width: 992px) and (max-width: 32767px) {
	.login-class-container {
		width: 540px;
	}
}
@media screen and (min-width: 768px) and (max-width: 991px) {
	.login-class-container {
		width: 470px;
	}
}
@media screen and (min-width: 375px) and (max-width: 767px) {
	.login-class-container {
		width: 370px;
	}
}
@media screen and (min-width: 0px) and (max-width: 374px) {
	.login-class-container {
		width: 96%;
	}
}
</style>