#pragma once
#include "../CenterBase/Local.h"
#include "../CenterBase/TypeDefine.h"


//快速处理器类型
enum QuickHandleType
{
	QUICK_H_CLIENT_ARRIVED = 0,					//客户端消息到来（大厅服与逻辑服相对于中心服是客户端）
	QUICK_H_INSIDE_CLIENT_SOCKET_CLOSE,			//内部请求客户端套接字断线
};

//数据处理器类型
enum DataHandleType
{
	DATA_H_CLIENT_REQUEST = 0,						//客户端请求
	DATA_H_INSIDE_RELOAD_REDIS_SCRIPT_SHA1,			//内部请求去数据库读取Redis脚本Sha1
	DATA_H_INSIDE_INIT_DATABASE_REDIS_DATA,			//内部请求去数据库和Redis初始化启动数据
};