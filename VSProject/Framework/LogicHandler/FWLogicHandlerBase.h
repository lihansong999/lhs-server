#ifndef __FRAMEWORK_LOGICHANDLERBASE_H__
#define __FRAMEWORK_LOGICHANDLERBASE_H__

#include "../FWLocal.h"
#include "../FWTypeDefine.h"
#include "../Common/FWLock.h"
#include "FWLogicDataBase.h"

FW_NS_BEGIN


/*
�߼����������࣬
�̳к�ʹ�ã�
�ⲿPush�߼����ݣ�
�ڲ��Զ�ѡ����ʵ�ʱ��Pop��
Pop֮����ø���ʵ�ֵĴ�������
*/
class FW_DLL FWLogicHandlerBase
{
public:
	FWLogicHandlerBase();
	virtual ~FWLogicHandlerBase();

	/* threadCountHandler���߼������߳��������鴫1�����̴߳����߼��������ڿ�����*/
	bool Start(unsigned int threadCountHandler);
	
	void Stop();

	/* newһ������ѹ����У��Ժ��ͨ��_onLogicDataHandler���룬��_onLogicDataHandler������Ϻ���Զ�����_deleteLogicData�����ͷ� */
	void PushLogicData(FWLogicDataBase * dataBase);

protected:
	/* �ɸ���ʵ��returnһ�������ַ�������ӡLOGʱ�������ֲ�ͬ��FWLogicHandlerBase���� */
	virtual const char * _getTitle() const;

	/*
	��Start������ʼִ��ʱ����Start�������ص�����ڼ��ڣ�Start�����ڲ�ÿ���ɹ�����������һ�������߳�ʱ�������������߳��е��ô˺���һ��
	���ص�void*������֮���_onLogicDataHandler��_onDeleteThread�Ĳ���customArg�д���
	*/
	virtual void * _onCreateThread(const char * threadID);

	/* ��Stop������ʼִ��ʱ����Stop�������ص�����ڼ��ڣ�Stop�����ڲ�ÿ������ɱ��һ�������߳�ʱ��������ɱ���Ĵ����߳�������ǰ����ô˺���һ�� */
	virtual void _onDeleteThread(const char * threadID, void * customArg);

	/* ����ʵ���ͷŵ���PushLogicDataʱ�����dataBaseָ�� */
	virtual void _deleteLogicData(FWLogicDataBase * dataBase);

	/* ����ʵ���߼����ݵĴ��� */
	virtual void _onLogicDataHandler(FWLogicDataBase * dataBase, const char * threadID, void * customArg) = 0;

private:
	FWLogicDataBase * _popLogicData();

private:
	void _threadHandler(void * pPromiseStart);

private:
	volatile bool			_running;

	FWLockRecursive			_lock;

	void				*	_pThreadHandlerVector;
	
	HANDLE					_completionPortHandler;

	void				*	_logicDataDeque;

	FWLockRecursive			_deleteThreadNotifyLock;
};



FW_NS_END


#endif //!__FRAMEWORK_LOGICHANDLERBASE_H__