#pragma once
#include "../CenterBase/Local.h"
#include "../CenterBase/TypeDefine.h"


//���ٴ���������
enum QuickHandleType
{
	QUICK_H_CLIENT_ARRIVED = 0,					//�ͻ�����Ϣ���������������߼�����������ķ��ǿͻ��ˣ�
	QUICK_H_INSIDE_CLIENT_SOCKET_CLOSE,			//�ڲ�����ͻ����׽��ֶ���
};

//���ݴ���������
enum DataHandleType
{
	DATA_H_CLIENT_REQUEST = 0,						//�ͻ�������
	DATA_H_INSIDE_RELOAD_REDIS_SCRIPT_SHA1,			//�ڲ�����ȥ���ݿ��ȡRedis�ű�Sha1
	DATA_H_INSIDE_INIT_DATABASE_REDIS_DATA,			//�ڲ�����ȥ���ݿ��Redis��ʼ����������
};