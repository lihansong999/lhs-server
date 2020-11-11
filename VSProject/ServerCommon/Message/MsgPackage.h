#ifndef __MESSAGE_PACKAGE_H__
#define __MESSAGE_PACKAGE_H__

#include "MsgBase.h"


namespace MSG_NAMESPACE {


#define MSG_PACKAGE_MAX	20480


	/*
	���͵���Ϣ��
	��errorCode!=0ʱ��body�����ᱻʹ��
	��ʽ��
		json = {
			"Head": {
				"MainID": 0,
				"AssistantID": 0,
				"ErrorCode": 0,
				"Reserve": 0
			},
			"Body": {}
		}
	*/
	class MSG_DLL MsgPackageSend
	{
	public:
		MsgPackageSend(int mainID, int assistantID, const MsgBodyBase * body);
		MsgPackageSend(int mainID, int assistantID, int errorCode, const MsgBodyBase * body);
		MsgPackageSend(int mainID, int assistantID, int errorCode, int reserve, const MsgBodyBase * body);
		MsgPackageSend(const MsgPackageSend & other) = delete;
		MsgPackageSend& operator=(const MsgPackageSend & other) = delete;
		MsgPackageSend(MsgPackageSend && other) = delete;
		MsgPackageSend& operator=(MsgPackageSend && other) = delete;
		~MsgPackageSend();

		const char * GetBuffer() const;
		int GetSize() const;

	private:
		void * _serialized;
	};


	//////////////////////////////////////////////////////////////////////////

	/*
	���յ���Ϣ��
	��GetErrorCode!=0ʱ��Deserialize���ɵ���
	����out_validSize==0ʱ����Ϣ���Ƿ�
	*/
	class MSG_DLL MsgPackageRecv
	{
	public:
		MsgPackageRecv(const char * buf, int size, int * out_validSize);
		MsgPackageRecv(const MsgPackageRecv & other) = delete;
		MsgPackageRecv& operator=(const MsgPackageRecv & other) = delete;
		MsgPackageRecv(MsgPackageRecv && other) = delete;
		MsgPackageRecv& operator=(MsgPackageRecv && other) = delete;
		~MsgPackageRecv();

		static int TestBufferValidity(const char * buf, int size, int * out_validCount);

		int GetMainID() const;
		int GetAssistantID() const;
		int GetErrorCode() const;
		int GetReserve() const;

		bool Deserialize(MsgBodyBase * body) const;

	private:
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4251)
#endif
		rapidjson::GenericDocument<rapidjson::UTF8<> > _doc;
#if defined(_MSC_VER)
#pragma warning(pop)
#endif
		int _mainID;
		int _assistantID;
		int _errorCode;
		int _reserve;
	};


}


#endif //!__MESSAGE_PACKAGE_H__