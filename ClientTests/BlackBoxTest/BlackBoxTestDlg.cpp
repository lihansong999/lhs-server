
// BlackBoxTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "BlackBoxTest.h"
#include "BlackBoxTestDlg.h"
#include "afxdialogex.h"
#include "AccountInputDlg.h"
#include "CommonInputDlg.h"
#include "PlayerInfoDlg.h"
#include "Classes/RecordInfo.h"
#include "Classes/Tools.h"
#include "Classes/Charset.h"
#include "Classes/WebMsgProtocol/WebMsgProtocol.h"
#include "Classes/WebMsgProtocol/WebMsgPackage.h"
#include "ProtobufDynamic/CustomImporter.h"

#include <google/protobuf/message_lite.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PRINT_DEQUE_MAX_COUNT	120

#define SOCKET_THREAD_UPDATE 1
#define SOCKET_HEARTBEAT_SEND 2


static void NewlinePrint(CBlackBoxTestDlg * blackBoxTestDlg, std::string s)
{
	s.append("\r\n");
	blackBoxTestDlg->LobbyPrintA(s.c_str());
}
static char * LABELNAME[4]{ nullptr,"optional","required","repeated" };
static void PrintProtobufMessageSub(CBlackBoxTestDlg * blackBoxTestDlg, const google::protobuf::Descriptor * descriptor,const std::string & table)
{
	for (int i = 0; i < descriptor->field_count(); i++)
	{
		const google::protobuf::FieldDescriptor * fieldDescriptor = descriptor->field(i);

		switch (fieldDescriptor->cpp_type())
		{
		case google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE:
		{
			const google::protobuf::Descriptor * descriptor2 = fieldDescriptor->message_type();
			if (descriptor2)
			{
				char buff[1024];
				sprintf_s(buff, sizeof(buff), "%s%s (msg)%s %s =", table.c_str(), LABELNAME[fieldDescriptor->label()], descriptor2->full_name().c_str(), fieldDescriptor->name().c_str());
				NewlinePrint(blackBoxTestDlg, buff);
				NewlinePrint(blackBoxTestDlg, table + "{");
				PrintProtobufMessageSub(blackBoxTestDlg, descriptor2, table + "    ");
				sprintf_s(buff, sizeof(buff), "%s} =  %d;", table.c_str(), fieldDescriptor->number());
				NewlinePrint(blackBoxTestDlg, buff);
			}
		}
			break;
		case google::protobuf::FieldDescriptor::CPPTYPE_ENUM:
		{
			const google::protobuf::EnumDescriptor * enumDescriptor = fieldDescriptor->enum_type();
			if (enumDescriptor)
			{
				char buff[1024];
				sprintf_s(buff, sizeof(buff), "%s%s (enum)%s %s = %d;", table.c_str(), LABELNAME[fieldDescriptor->label()], enumDescriptor->full_name().c_str(), fieldDescriptor->name().c_str(), fieldDescriptor->number());
				NewlinePrint(blackBoxTestDlg, buff);
			}
		}
			break;
		default:
		{
			char buff[1024];
			sprintf_s(buff, sizeof(buff), "%s%s %s %s = %d;", table.c_str(), LABELNAME[fieldDescriptor->label()], fieldDescriptor->type_name(), fieldDescriptor->name().c_str(), fieldDescriptor->number());
			NewlinePrint(blackBoxTestDlg, buff);
		}
			break;
		}
	}
}
static void PrintProtobufMessage(CBlackBoxTestDlg * blackBoxTestDlg, CustomImporter * customImporter, const std::string & name)
{
	google::protobuf::Message * message = customImporter->NewDynamicMessage(name);
	if (message)
	{
		const google::protobuf::Descriptor * descriptor = message->GetDescriptor();
		NewlinePrint(blackBoxTestDlg, "(msg)"+descriptor->full_name() + " =");
		NewlinePrint(blackBoxTestDlg, "{");
		PrintProtobufMessageSub(blackBoxTestDlg, message->GetDescriptor(), "    ");
		NewlinePrint(blackBoxTestDlg, "}");
		delete message;
	}
}

static google::protobuf::Message * TestSetProtobufMessage(CBlackBoxTestDlg * blackBoxTestDlg, CustomImporter * customImporter)
{
	google::protobuf::Message * message_protocol_club_AddressBook = customImporter->NewDynamicMessage("protocol.club.AddressBook");
	if (!message_protocol_club_AddressBook)
		return nullptr;
	const google::protobuf::Descriptor * descriptor_protocol_club_AddressBook = message_protocol_club_AddressBook->GetDescriptor();
	const google::protobuf::Reflection * reflection_protocol_club_AddressBook = message_protocol_club_AddressBook->GetReflection();

#define IF_RETURN(p)	if (p){delete message_protocol_club_AddressBook;return nullptr;}

	const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_leader = descriptor_protocol_club_AddressBook->FindFieldByName("leader");
	IF_RETURN(!fieldDescriptor_protocol_club_AddressBook_leader);

	if (fieldDescriptor_protocol_club_AddressBook_leader->label() == google::protobuf::FieldDescriptorProto_Label::FieldDescriptorProto_Label_LABEL_REQUIRED)
	{
		;//这种字段类型必须填写
	}

	// leader
	if (fieldDescriptor_protocol_club_AddressBook_leader->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
	{
		google::protobuf::Message * message_protocol_club_AddressBook_leader = reflection_protocol_club_AddressBook->MutableMessage(message_protocol_club_AddressBook, fieldDescriptor_protocol_club_AddressBook_leader, nullptr);
		const google::protobuf::Descriptor * descriptor_protocol_club_AddressBook_leader = message_protocol_club_AddressBook_leader->GetDescriptor();
		const google::protobuf::Reflection * reflection_protocol_club_AddressBook_leader = message_protocol_club_AddressBook_leader->GetReflection();

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_leader_name = descriptor_protocol_club_AddressBook_leader->FindFieldByName("name");
		IF_RETURN(!fieldDescriptor_protocol_club_AddressBook_leader_name);
		reflection_protocol_club_AddressBook_leader->SetString(message_protocol_club_AddressBook_leader, fieldDescriptor_protocol_club_AddressBook_leader_name, "lihansong");

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_leader_id = descriptor_protocol_club_AddressBook_leader->FindFieldByName("id");
		IF_RETURN(!fieldDescriptor_protocol_club_AddressBook_leader_id);
		reflection_protocol_club_AddressBook_leader->SetInt32(message_protocol_club_AddressBook_leader, fieldDescriptor_protocol_club_AddressBook_leader_id, 17);

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_leader_email = descriptor_protocol_club_AddressBook_leader->FindFieldByName("email");
		IF_RETURN(!fieldDescriptor_protocol_club_AddressBook_leader_email);
		reflection_protocol_club_AddressBook_leader->SetString(message_protocol_club_AddressBook_leader, fieldDescriptor_protocol_club_AddressBook_leader_email, "lihansong@mail.com");

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_leader_phones = descriptor_protocol_club_AddressBook_leader->FindFieldByName("phones");
		IF_RETURN(!fieldDescriptor_protocol_club_AddressBook_leader_phones);
		if (fieldDescriptor_protocol_club_AddressBook_leader_phones->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
		{
			char * numberArray[2] = { "18875001107","67906172" };
			int numberEnumArray[2] = { 0,1 };
			for (int i = 0; i < 2; i++)
			{
				google::protobuf::Message * message_protocol_actor_Person_PhoneNumber = customImporter->NewDynamicMessage("protocol.actor.Person.PhoneNumber");
				const google::protobuf::Descriptor * descriptor_protocol_actor_Person_PhoneNumber = message_protocol_actor_Person_PhoneNumber->GetDescriptor();
				const google::protobuf::Reflection * reflection_protocol_actor_Person_PhoneNumber = message_protocol_actor_Person_PhoneNumber->GetReflection();

				const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_PhoneNumber_number = descriptor_protocol_actor_Person_PhoneNumber->FindFieldByName("number");
				IF_RETURN(!fieldDescriptor_protocol_actor_Person_PhoneNumber_number);
				reflection_protocol_actor_Person_PhoneNumber->SetString(message_protocol_actor_Person_PhoneNumber, fieldDescriptor_protocol_actor_Person_PhoneNumber_number, numberArray[i]);

				const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_PhoneNumber_type = descriptor_protocol_actor_Person_PhoneNumber->FindFieldByName("type");
				IF_RETURN(!fieldDescriptor_protocol_actor_Person_PhoneNumber_type);
				reflection_protocol_actor_Person_PhoneNumber->SetEnumValue(message_protocol_actor_Person_PhoneNumber, fieldDescriptor_protocol_actor_Person_PhoneNumber_type, numberEnumArray[i]);

				reflection_protocol_club_AddressBook_leader->AddAllocatedMessage(message_protocol_club_AddressBook_leader, fieldDescriptor_protocol_club_AddressBook_leader_phones, message_protocol_actor_Person_PhoneNumber);
			}
		}
	}

	const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_people = descriptor_protocol_club_AddressBook->FindFieldByName("people");
	IF_RETURN(!fieldDescriptor_protocol_club_AddressBook_people);
	// people
	if (fieldDescriptor_protocol_club_AddressBook_people->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
	{
		char * nameArray[2] = { "liuyi","liduojia" };
		int idArray[2] = { 21,22 };
		char * emailArray[2] = { "liuyi@mail.com","liduojia@mail.com" };
		char * numberArray[2] = { "12121122","67675548" };
		int numberEnumArray[2] = { 2,1 };
		for (int i = 0; i < 2; i++)
		{
			google::protobuf::Message * message_protocol_actor_Person = customImporter->NewDynamicMessage("protocol.actor.Person");
			const google::protobuf::Descriptor * descriptor_protocol_actor_Person = message_protocol_actor_Person->GetDescriptor();
			const google::protobuf::Reflection * reflection_protocol_actor_Person = message_protocol_actor_Person->GetReflection();

			const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_name = descriptor_protocol_actor_Person->FindFieldByName("name");
			IF_RETURN(!fieldDescriptor_protocol_actor_Person_name);
			reflection_protocol_actor_Person->SetString(message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_name, nameArray[i]);

			const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_id = descriptor_protocol_actor_Person->FindFieldByName("id");
			IF_RETURN(!fieldDescriptor_protocol_actor_Person_id);
			reflection_protocol_actor_Person->SetInt32(message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_id, idArray[i]);

			const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_email = descriptor_protocol_actor_Person->FindFieldByName("email");
			IF_RETURN(!fieldDescriptor_protocol_actor_Person_email);
			reflection_protocol_actor_Person->SetString(message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_email, emailArray[i]);

			const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_phones = descriptor_protocol_actor_Person->FindFieldByName("phones");
			IF_RETURN(!fieldDescriptor_protocol_actor_Person_phones);
			if (fieldDescriptor_protocol_actor_Person_phones->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
			{
				google::protobuf::Message * message_protocol_actor_Person_PhoneNumber = customImporter->NewDynamicMessage("protocol.actor.Person.PhoneNumber");
				const google::protobuf::Descriptor * descriptor_protocol_actor_Person_PhoneNumber = message_protocol_actor_Person_PhoneNumber->GetDescriptor();
				const google::protobuf::Reflection * reflection_protocol_actor_Person_PhoneNumber = message_protocol_actor_Person_PhoneNumber->GetReflection();

				const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_PhoneNumber_number = descriptor_protocol_actor_Person_PhoneNumber->FindFieldByName("number");
				IF_RETURN(!fieldDescriptor_protocol_actor_Person_PhoneNumber_number);
				reflection_protocol_actor_Person_PhoneNumber->SetString(message_protocol_actor_Person_PhoneNumber, fieldDescriptor_protocol_actor_Person_PhoneNumber_number, numberArray[i]);

				const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_PhoneNumber_type = descriptor_protocol_actor_Person_PhoneNumber->FindFieldByName("type");
				IF_RETURN(!fieldDescriptor_protocol_actor_Person_PhoneNumber_type);
				reflection_protocol_actor_Person_PhoneNumber->SetEnumValue(message_protocol_actor_Person_PhoneNumber, fieldDescriptor_protocol_actor_Person_PhoneNumber_type, numberEnumArray[i]);

				reflection_protocol_actor_Person->AddAllocatedMessage(message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_phones, message_protocol_actor_Person_PhoneNumber);
			}

			reflection_protocol_club_AddressBook->AddAllocatedMessage(message_protocol_club_AddressBook, fieldDescriptor_protocol_club_AddressBook_people, message_protocol_actor_Person);
		}
	}

	const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_err = descriptor_protocol_club_AddressBook->FindFieldByName("err");
	IF_RETURN(!fieldDescriptor_protocol_club_AddressBook_err);
	// err
	if (fieldDescriptor_protocol_club_AddressBook_err->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
	{
		google::protobuf::Message * message_protocol_club_AddressBook_err = reflection_protocol_club_AddressBook->MutableMessage(message_protocol_club_AddressBook, fieldDescriptor_protocol_club_AddressBook_err, nullptr);
		const google::protobuf::Descriptor * descriptor_protocol_club_AddressBook_err = message_protocol_club_AddressBook_err->GetDescriptor();
		const google::protobuf::Reflection * reflection_protocol_club_AddressBook_err = message_protocol_club_AddressBook_err->GetReflection();

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_err_code = descriptor_protocol_club_AddressBook_err->FindFieldByName("code");
		IF_RETURN(!fieldDescriptor_protocol_club_AddressBook_err_code);
		reflection_protocol_club_AddressBook_err->SetInt32(message_protocol_club_AddressBook_err, fieldDescriptor_protocol_club_AddressBook_err_code, 8888);

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_err_info = descriptor_protocol_club_AddressBook_err->FindFieldByName("info");
		IF_RETURN(!fieldDescriptor_protocol_club_AddressBook_err_info);
		reflection_protocol_club_AddressBook_err->SetString(message_protocol_club_AddressBook_err, fieldDescriptor_protocol_club_AddressBook_err_info, "error info - test");
	}

	blackBoxTestDlg->LogicalPrintA("Set message_protocol_club_AddressBook <<<\r\n");
	blackBoxTestDlg->LogicalPrintA(message_protocol_club_AddressBook->DebugString().c_str());
	blackBoxTestDlg->LogicalPrintA("Set message_protocol_club_AddressBook >>>\r\n");

	return message_protocol_club_AddressBook;
}

static bool HAS_FOR_REQUIRED(const google::protobuf::Message * message, const google::protobuf::FieldDescriptor * fieldDescriptor, const google::protobuf::Reflection * reflection)
{
	if (fieldDescriptor->label() == google::protobuf::FieldDescriptorProto_Label::FieldDescriptorProto_Label_LABEL_REQUIRED) {
		if (!reflection->HasField(*message, fieldDescriptor)) {
			AfxMessageBox(ANSI_2_UNICODE(("字段 " + message->GetTypeName() + "." + fieldDescriptor->name() + " 为 required ，必须填写。").c_str()).c_str());
			return false;
		}
	}
	return true;
}

static void TestGetProtobufMessage(CBlackBoxTestDlg * blackBoxTestDlg, google::protobuf::Message * message_protocol_club_AddressBook)
{
	if (!message_protocol_club_AddressBook)
		return;

	blackBoxTestDlg->LogicalPrintA("Get message_protocol_club_AddressBook <<<\r\n");

	const google::protobuf::Descriptor * descriptor_protocol_club_AddressBook = message_protocol_club_AddressBook->GetDescriptor();
	const google::protobuf::Reflection * reflection_protocol_club_AddressBook = message_protocol_club_AddressBook->GetReflection();
	
	std::function<void(CBlackBoxTestDlg*, const google::protobuf::Message&, std::string)> getFunction_protocol_Error = [](CBlackBoxTestDlg * blackBoxTestDlg, const google::protobuf::Message & message_protocol_Error, std::string table)->void {
		const google::protobuf::Descriptor * descriptor_protocol_Error = message_protocol_Error.GetDescriptor();
		const google::protobuf::Reflection * reflection_protocol_Error = message_protocol_Error.GetReflection();

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_Error_code = descriptor_protocol_Error->FindFieldByName("code");
		HAS_FOR_REQUIRED(&message_protocol_Error, fieldDescriptor_protocol_Error_code, reflection_protocol_Error);
		int code = reflection_protocol_Error->GetInt32(message_protocol_Error, fieldDescriptor_protocol_Error_code);
		char buff[64];
		sprintf_s(buff, sizeof(buff), "%d", code);
		blackBoxTestDlg->LogicalPrintA(table.c_str());
		blackBoxTestDlg->LogicalPrintA("code = ");
		blackBoxTestDlg->LogicalPrintA(buff);
		blackBoxTestDlg->LogicalPrintA("\r\n");

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_Error_info = descriptor_protocol_Error->FindFieldByName("info");
		HAS_FOR_REQUIRED(&message_protocol_Error, fieldDescriptor_protocol_Error_info, reflection_protocol_Error);
		std::string info = reflection_protocol_Error->GetString(message_protocol_Error, fieldDescriptor_protocol_Error_info);
		blackBoxTestDlg->LogicalPrintA(table.c_str());
		blackBoxTestDlg->LogicalPrintA("info = \"");
		blackBoxTestDlg->LogicalPrintA(info.c_str());
		blackBoxTestDlg->LogicalPrintA("\"\r\n");
	};

	std::function<void(CBlackBoxTestDlg*, const google::protobuf::Message&, std::string)> getFunction_protocol_actor_Person_PhoneNumber = [](CBlackBoxTestDlg * blackBoxTestDlg, const google::protobuf::Message & message_protocol_actor_Person_PhoneNumber, std::string table)->void {
		const google::protobuf::Descriptor * descriptor_protocol_actor_Person_PhoneNumber = message_protocol_actor_Person_PhoneNumber.GetDescriptor();
		const google::protobuf::Reflection * reflection_protocol_actor_Person_PhoneNumber = message_protocol_actor_Person_PhoneNumber.GetReflection();
	
		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_PhoneNumber_number = descriptor_protocol_actor_Person_PhoneNumber->FindFieldByName("number");
		HAS_FOR_REQUIRED(&message_protocol_actor_Person_PhoneNumber, fieldDescriptor_protocol_actor_Person_PhoneNumber_number, reflection_protocol_actor_Person_PhoneNumber);
		std::string number = reflection_protocol_actor_Person_PhoneNumber->GetString(message_protocol_actor_Person_PhoneNumber, fieldDescriptor_protocol_actor_Person_PhoneNumber_number);
		blackBoxTestDlg->LogicalPrintA(table.c_str());
		blackBoxTestDlg->LogicalPrintA("number = \"");
		blackBoxTestDlg->LogicalPrintA(number.c_str());
		blackBoxTestDlg->LogicalPrintA("\"\r\n");

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_PhoneNumber_type = descriptor_protocol_actor_Person_PhoneNumber->FindFieldByName("type");
		HAS_FOR_REQUIRED(&message_protocol_actor_Person_PhoneNumber, fieldDescriptor_protocol_actor_Person_PhoneNumber_type, reflection_protocol_actor_Person_PhoneNumber);
		char * enumStringArray[3] = { "MOBILE", "HOME", "WORK" };
		int phoneType = reflection_protocol_actor_Person_PhoneNumber->GetEnumValue(message_protocol_actor_Person_PhoneNumber, fieldDescriptor_protocol_actor_Person_PhoneNumber_type);
		blackBoxTestDlg->LogicalPrintA(table.c_str());
		blackBoxTestDlg->LogicalPrintA("type = ");
		blackBoxTestDlg->LogicalPrintA(enumStringArray[phoneType]);
		blackBoxTestDlg->LogicalPrintA("\r\n");
	};

	std::function<void(CBlackBoxTestDlg*, const google::protobuf::Message&, std::string)> getFunction_protocol_actor_Person = [getFunction_protocol_actor_Person_PhoneNumber](CBlackBoxTestDlg * blackBoxTestDlg, const google::protobuf::Message & message_protocol_actor_Person, std::string table)->void {
		const google::protobuf::Descriptor * descriptor_protocol_actor_Person = message_protocol_actor_Person.GetDescriptor();
		const google::protobuf::Reflection * reflection_protocol_actor_Person = message_protocol_actor_Person.GetReflection();
		
		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_name = descriptor_protocol_actor_Person->FindFieldByName("name");
		HAS_FOR_REQUIRED(&message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_name, reflection_protocol_actor_Person);
		std::string name = reflection_protocol_actor_Person->GetString(message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_name);
		blackBoxTestDlg->LogicalPrintA(table.c_str());
		blackBoxTestDlg->LogicalPrintA("name = \"");
		blackBoxTestDlg->LogicalPrintA(name.c_str());
		blackBoxTestDlg->LogicalPrintA("\"\r\n");
		
		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_id = descriptor_protocol_actor_Person->FindFieldByName("id");
		HAS_FOR_REQUIRED(&message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_id, reflection_protocol_actor_Person);
		int id = reflection_protocol_actor_Person->GetInt32(message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_id);
		char buff[64];
		sprintf_s(buff, sizeof(buff), "%d", id);
		blackBoxTestDlg->LogicalPrintA(table.c_str());
		blackBoxTestDlg->LogicalPrintA("id = ");
		blackBoxTestDlg->LogicalPrintA(buff);
		blackBoxTestDlg->LogicalPrintA("\r\n");

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_email = descriptor_protocol_actor_Person->FindFieldByName("email");
		HAS_FOR_REQUIRED(&message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_email, reflection_protocol_actor_Person);
		std::string email = reflection_protocol_actor_Person->GetString(message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_email);
		blackBoxTestDlg->LogicalPrintA(table.c_str());
		blackBoxTestDlg->LogicalPrintA("email = \"");
		blackBoxTestDlg->LogicalPrintA(email.c_str());
		blackBoxTestDlg->LogicalPrintA("\"\r\n");

		const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_actor_Person_phones = descriptor_protocol_actor_Person->FindFieldByName("phones");
		int count = reflection_protocol_actor_Person->FieldSize(message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_phones);
		blackBoxTestDlg->LogicalPrintA(table.c_str());
		blackBoxTestDlg->LogicalPrintA("phones = {\r\n");
		for (int i = 0; i < count; i++)
		{
			const google::protobuf::Message & message_protocol_actor_Person_PhoneNumber = reflection_protocol_actor_Person->GetRepeatedMessage(message_protocol_actor_Person, fieldDescriptor_protocol_actor_Person_phones, i);
			blackBoxTestDlg->LogicalPrintA(table.c_str());
			blackBoxTestDlg->LogicalPrintA("  {\r\n");
			getFunction_protocol_actor_Person_PhoneNumber(blackBoxTestDlg, message_protocol_actor_Person_PhoneNumber, table + "    ");
			blackBoxTestDlg->LogicalPrintA(table.c_str());
			blackBoxTestDlg->LogicalPrintA("  }\r\n");
		}
		blackBoxTestDlg->LogicalPrintA(table.c_str());
		blackBoxTestDlg->LogicalPrintA("}\r\n");
	};

	// err
	const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_err = descriptor_protocol_club_AddressBook->FindFieldByName("err");
	HAS_FOR_REQUIRED(message_protocol_club_AddressBook, fieldDescriptor_protocol_club_AddressBook_err, reflection_protocol_club_AddressBook);
	if (fieldDescriptor_protocol_club_AddressBook_err->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
	{
#ifdef UNICODE
#ifdef GetMessageW
#error "function google::protobuf::Reflection::GetMessage fix failed"
#else
#define GetMessageW  GetMessage
#endif
#else
#ifdef GetMessageA
#error "function google::protobuf::Reflection::GetMessage fix failed"
#else
#define GetMessageA  GetMessage
#endif
#endif // !UNICODE
		const google::protobuf::Message & message_protocol_club_AddressBook_err = reflection_protocol_club_AddressBook->GetMessage(*message_protocol_club_AddressBook, fieldDescriptor_protocol_club_AddressBook_err, nullptr);
#ifdef UNICODE
#undef GetMessageW
#else
#undef GetMessageA
#endif // !UNICODE
		blackBoxTestDlg->LogicalPrintA("err = {\r\n");
		getFunction_protocol_Error(blackBoxTestDlg, message_protocol_club_AddressBook_err, "  ");
		blackBoxTestDlg->LogicalPrintA("}\r\n");
	}

	// leader
	const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_leader = descriptor_protocol_club_AddressBook->FindFieldByName("leader");
	HAS_FOR_REQUIRED(message_protocol_club_AddressBook, fieldDescriptor_protocol_club_AddressBook_leader, reflection_protocol_club_AddressBook);
	if (fieldDescriptor_protocol_club_AddressBook_leader->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
	{
#ifdef UNICODE
#ifdef GetMessageW
#error "function google::protobuf::Reflection::GetMessage fix failed"
#else
#define GetMessageW  GetMessage
#endif
#else
#ifdef GetMessageA
#error "function google::protobuf::Reflection::GetMessage fix failed"
#else
#define GetMessageA  GetMessage
#endif
#endif // !UNICODE
		const google::protobuf::Message & message_protocol_club_AddressBook_leader = reflection_protocol_club_AddressBook->GetMessage(*message_protocol_club_AddressBook, fieldDescriptor_protocol_club_AddressBook_leader, nullptr);
#ifdef UNICODE
#undef GetMessageW
#else
#undef GetMessageA
#endif // !UNICODE
		blackBoxTestDlg->LogicalPrintA("leader = {\r\n");
		getFunction_protocol_actor_Person(blackBoxTestDlg, message_protocol_club_AddressBook_leader, "  ");
		blackBoxTestDlg->LogicalPrintA("}\r\n");
	}

	// people
	const google::protobuf::FieldDescriptor * fieldDescriptor_protocol_club_AddressBook_people = descriptor_protocol_club_AddressBook->FindFieldByName("people");
	HAS_FOR_REQUIRED(message_protocol_club_AddressBook, fieldDescriptor_protocol_club_AddressBook_people, reflection_protocol_club_AddressBook);
	if (fieldDescriptor_protocol_club_AddressBook_people->cpp_type() == google::protobuf::FieldDescriptor::CPPTYPE_MESSAGE)
	{
		int count = reflection_protocol_club_AddressBook->FieldSize(*message_protocol_club_AddressBook, fieldDescriptor_protocol_club_AddressBook_people);
		blackBoxTestDlg->LogicalPrintA("people = {\r\n");
		for (int i = 0; i < count; i++)
		{
			const google::protobuf::Message & message_protocol_actor_Person_PhoneNumber = reflection_protocol_club_AddressBook->GetRepeatedMessage(*message_protocol_club_AddressBook, fieldDescriptor_protocol_club_AddressBook_people, i);
			blackBoxTestDlg->LogicalPrintA("  {\r\n");
			getFunction_protocol_actor_Person(blackBoxTestDlg, message_protocol_actor_Person_PhoneNumber, "    ");
			blackBoxTestDlg->LogicalPrintA("  }\r\n");
		}
		blackBoxTestDlg->LogicalPrintA("}\r\n");
	}

	blackBoxTestDlg->LogicalPrintA("Get message_protocol_club_AddressBook >>>\r\n");
}

CBlackBoxTestDlg::CBlackBoxTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_BLACKBOXTEST_DIALOG, pParent)
	, _lobbySocketThread(ST_NAME_LOBBY)
	, _lobbyConnected(false)
	, _logicalSocketThread(ST_NAME_LOGICAL)
	, _logicalConnected(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CBlackBoxTestDlg::~CBlackBoxTestDlg()
{
	_lobbySocketThread.RemoveListener(this);
	_logicalSocketThread.RemoveListener(this);
	google::protobuf::ShutdownProtobufLibrary();
}

void CBlackBoxTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBlackBoxTestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CBlackBoxTestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CBlackBoxTestDlg::OnBnClickedCancel)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, &CBlackBoxTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBlackBoxTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CBlackBoxTestDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CBlackBoxTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CBlackBoxTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CBlackBoxTestDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CBlackBoxTestDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CBlackBoxTestDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CBlackBoxTestDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CBlackBoxTestDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CBlackBoxTestDlg::OnBnClickedButton11)
END_MESSAGE_MAP()


// CBlackBoxTestDlg 消息处理程序

BOOL CBlackBoxTestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	std::string webHost = RecordInfo::GetInstance()->Read_WebHost();
	if (webHost.size() > 0)
	{
		((CEdit*)GetDlgItem(IDC_EDIT7))->SetWindowText(ANSI_2_UNICODE(webHost.c_str()).c_str());
	}
	std::string lobbyHost = RecordInfo::GetInstance()->Read_LobbyHost();
	int lobbyPort = RecordInfo::GetInstance()->Read_LobbyPort();
	if (lobbyHost.size() > 0)
	{
		((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS1))->SetWindowText(ANSI_2_UNICODE(lobbyHost.c_str()).c_str());
	}
	if (lobbyPort > 0)
	{
		CString portStr;
		portStr.Format(L"%d", lobbyPort);
		((CEdit*)GetDlgItem(IDC_EDIT3))->SetWindowText(portStr);
	}

	((CIPAddressCtrl*)GetDlgItem(IDC_IPADDRESS2))->SetWindowText(L"");
	((CEdit*)GetDlgItem(IDC_EDIT4))->SetWindowText(L"");

	((CButton *)GetDlgItem(IDC_BUTTON3))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_BUTTON8))->EnableWindow(FALSE);
	((CButton *)GetDlgItem(IDC_BUTTON9))->EnableWindow(FALSE);

	_lobbySocketThread.AddListener(this);
	_logicalSocketThread.AddListener(this);

	CustomImporter customImporter;
	std::string realPath = GetModuleFileDirectory();
	realPath.append("\\ProtoExamples\\protocol");
	customImporter.GetCustomSourceTree()->MapPath("", realPath.c_str());
	customImporter.Import("club/addressbook.proto");
	PrintProtobufMessage(this, &customImporter, "protocol.club.AddressBook");
	google::protobuf::Message * message_protocol_club_AddressBook = TestSetProtobufMessage(this, &customImporter);
	TestGetProtobufMessage(this, message_protocol_club_AddressBook);
	if (message_protocol_club_AddressBook)
		delete message_protocol_club_AddressBook;

	SetTimer(SOCKET_THREAD_UPDATE, 50, NULL);
	SetTimer(SOCKET_HEARTBEAT_SEND, 6000, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CBlackBoxTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CBlackBoxTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CBlackBoxTestDlg::onConnectResult(SocketThread * socketThread, bool s)
{
	if (socketThread == &_lobbySocketThread)
	{
		if (!s)
		{
			((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->EnableWindow(TRUE);
			((CEdit *)GetDlgItem(IDC_EDIT3))->SetReadOnly(FALSE);
			((CButton *)GetDlgItem(IDC_BUTTON1))->EnableWindow(TRUE);
			this->LobbyPrintW(L"连接失败\r\n");
			return;
		}
		_lobbyConnected = true;
		this->LobbyPrintW(L"连接成功\r\n");
	}
	else if (socketThread == &_logicalSocketThread)
	{
		if (!s)
		{
			((CButton *)GetDlgItem(IDC_BUTTON7))->EnableWindow(TRUE);
			this->LogicalPrintW(L"连接失败\r\n");
			return;
		}

		((CButton *)GetDlgItem(IDC_BUTTON3))->EnableWindow(TRUE);

		_logicalConnected = true;
		this->LogicalPrintW(L"连接成功\r\n");

		Message::Logical::LoginReq loginReq;
		loginReq.PlayerID = _lobbyLoginRes.PlayerID;
		loginReq.DynaPwd = _lobbyLoginRes.DynaPwd;
		Message::MsgPackageSend msgPackageSend(Message::Logical::MSG_MAIN_LOGIN, Message::Logical::MSG_ASS_LOGIN_DYNAMIC_PASSWORD, &loginReq);
		_logicalSocketThread.SendData(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
	}
}

void CBlackBoxTestDlg::onDisconnected(SocketThread * socketThread)
{
	if (socketThread == &_lobbySocketThread)
	{
		_lobbyConnected = false;
		((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->EnableWindow(TRUE);
		((CEdit *)GetDlgItem(IDC_EDIT3))->SetReadOnly(FALSE);
		((CButton *)GetDlgItem(IDC_BUTTON1))->EnableWindow(TRUE);

		((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(L"");

		((CButton *)GetDlgItem(IDC_BUTTON4))->EnableWindow(TRUE);
		((CButton *)GetDlgItem(IDC_BUTTON5))->EnableWindow(TRUE);

		_lobbyLoginRes.PlayerID = 0;

		this->LobbyPrintW(L"连接已断开\r\n");
	}
	else if (socketThread == &_logicalSocketThread)
	{
		_logicalConnected = false;
		((CButton *)GetDlgItem(IDC_BUTTON7))->EnableWindow(TRUE);

		((CButton *)GetDlgItem(IDC_BUTTON3))->EnableWindow(FALSE);
		((CButton *)GetDlgItem(IDC_BUTTON8))->EnableWindow(FALSE);
		((CButton *)GetDlgItem(IDC_BUTTON9))->EnableWindow(FALSE);

		((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(L"");

		this->LogicalPrintW(L"连接已断开\r\n");
	}
}

void CBlackBoxTestDlg::onMessage(SocketThread * socketThread, Message::MsgPackageRecv * pack)
{
	const int mainID = pack->GetMainID();
	const int assistantID = pack->GetAssistantID();
	const int errorCode = pack->GetErrorCode();
	if (errorCode != 0)
	{
		AfxMessageBox(ANSI_2_UNICODE(Message::GetErrorString(errorCode).C_Str()).c_str());
		return;
	}
	if (strcmp(socketThread->GetName(), ST_NAME_LOBBY) == 0)
	{
		switch (mainID)
		{
		case Message::Common::MSG_MAIN_TEST:
		{
			switch (assistantID)
			{
			case Message::Common::MSG_ASS_TEST_HEARTBEAT:
			{
				Message::Common::BeartbeatRes beartbeatRes;
				pack->Deserialize(&beartbeatRes);
			}
				break;
			default:
				break;
			}
		}
			break;
		case Message::Lobby::MSG_MAIN_LOGIN:
		{
			pack->Deserialize(&_lobbyLoginRes);
			switch (assistantID)
			{
			case Message::Lobby::MSG_ASS_LOGIN_ACCOUNT:
			{
				this->LobbyPrintW(L"账号登录成功\r\n");
				CString playerIDStr;
				playerIDStr.Format(L"%lld", _lobbyLoginRes.PlayerID);
				((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(playerIDStr);

				((CButton *)GetDlgItem(IDC_BUTTON4))->EnableWindow(FALSE);
				((CButton *)GetDlgItem(IDC_BUTTON5))->EnableWindow(FALSE);

				if (_lobbyLoginRes.LogicalServerID > 0 && !_logicalConnected)
				{
					this->LobbyPrintW(L"重连比赛中...\r\n");

					((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS2))->SetWindowText(ANSI_2_UNICODE(_lobbyLoginRes.LogicalAddr.C_Str()).c_str());
					CString portStr;
					portStr.Format(L"%d", _lobbyLoginRes.LogicalTcpPort);
					((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(portStr);

					_logicalSocketThread.ConnectServer(_lobbyLoginRes.LogicalAddr.C_Str(), _lobbyLoginRes.LogicalTcpPort);
				}
			}
				break;
			case Message::Lobby::MSG_ASS_LOGIN_UNIONID:
			{
				this->LobbyPrintW(L"唯一码登录成功\r\n");
				CString playerIDStr;
				playerIDStr.Format(L"%lld", _lobbyLoginRes.PlayerID);
				((CEdit *)GetDlgItem(IDC_EDIT5))->SetWindowText(playerIDStr);

				((CButton *)GetDlgItem(IDC_BUTTON4))->EnableWindow(FALSE);
				((CButton *)GetDlgItem(IDC_BUTTON5))->EnableWindow(FALSE);

				if (_lobbyLoginRes.LogicalServerID > 0 && !_logicalConnected)
				{
					this->LobbyPrintW(L"重连比赛中...\r\n");

					((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS2))->SetWindowText(ANSI_2_UNICODE(_lobbyLoginRes.LogicalAddr.C_Str()).c_str());
					CString portStr;
					portStr.Format(L"%d", _lobbyLoginRes.LogicalTcpPort);
					((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(portStr);

					_logicalSocketThread.ConnectServer(_lobbyLoginRes.LogicalAddr.C_Str(), _lobbyLoginRes.LogicalTcpPort);
				}
			}
				break;
			default:
				break;
			}
		}
			break;
		case Message::Lobby::MSG_MAIN_REQUEST_PLAYERINFO:
		{
			Message::Lobby::PlayerInfoRes playerInfoRes;
			pack->Deserialize(&playerInfoRes);
			if (playerInfoRes.PlayerID == _lobbyLoginRes.PlayerID)
			{
				//可以更新一下自己的显示
			}
		}
			break;
		case Message::Lobby::MSG_MAIN_NOTIFY:
		{
			switch (assistantID)
			{
			case Message::Lobby::MSG_ASS_NOTIFY_FORCE_OFFLINE:
			{
				Message::Lobby::NotifyForceOfflineRes notifyForceOfflineRes;
				pack->Deserialize(&notifyForceOfflineRes);
				if (notifyForceOfflineRes.PlayerID == _lobbyLoginRes.PlayerID)
				{
					if (notifyForceOfflineRes.Type == Message::FOT_REPEAT_LOGIN)
					{
						AfxMessageBox(L"账号在别处登录，您被迫下线。");
					}
				}
			}
				break;
			default:
				break;
			}
		}
			break;
		case Message::Lobby::MSG_MAIN_MATCH:
		{
			switch (assistantID)
			{
			case Message::Lobby::MSG_ASS_MATCH_REQ_ADD_SVR:
			{
				Message::Lobby::MatchRes matchRes;
				pack->Deserialize(&matchRes);
				if (((CButton *)GetDlgItem(IDC_BUTTON7))->IsWindowEnabled() == TRUE)
				{
					((CButton *)GetDlgItem(IDC_BUTTON7))->EnableWindow(FALSE);

					((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS2))->SetWindowText(ANSI_2_UNICODE(matchRes.LogicalAddr.C_Str()).c_str());
					CString portStr;
					portStr.Format(L"%d", matchRes.LogicalTcpPort);
					((CEdit *)GetDlgItem(IDC_EDIT4))->SetWindowText(portStr);

					_logicalSocketThread.ConnectServer(matchRes.LogicalAddr.C_Str(), matchRes.LogicalTcpPort);
				}
			}
				break;
			default:
				break;
			}
		}
			break;
		default:
			break;
		}
	}
	else if (strcmp(socketThread->GetName(), ST_NAME_LOGICAL) == 0)
	{
		switch (mainID)
		{
		case Message::Common::MSG_MAIN_TEST:
		{
			switch (assistantID)
			{
			case Message::Common::MSG_ASS_TEST_HEARTBEAT:
			{
				Message::Common::BeartbeatRes beartbeatRes;
				pack->Deserialize(&beartbeatRes);
			}
				break;
			default:
				break;
			}
		}
			break;
		case Message::Logical::MSG_MAIN_LOGIN:
		{
			pack->Deserialize(&_logicalLoginRes);
			switch (assistantID)
			{
			case Message::Logical::MSG_ASS_LOGIN_DYNAMIC_PASSWORD:
			{
				Message::Logical::LoginRes loginRes;
				pack->Deserialize(&loginRes);
				this->LogicalPrintW(L"登录成功\r\n");
				if (loginRes.LogicalServerStationID == 0)
				{
					((CButton *)GetDlgItem(IDC_BUTTON9))->EnableWindow(TRUE);
				}
			}
				break;
			default:
				break;
			}
		}
			break;
		case Message::Logical::MSG_MAIN_MATCH:
		{
			switch (assistantID)
			{
			case Message::Logical::MSG_ASS_MATCH_REQ_ADD:
			{
				Message::Logical::AddMatchRes addMatchRes;
				pack->Deserialize(&addMatchRes);
				_logicalLoginRes.LogicalServerStationID = addMatchRes.LogicalServerStationID;
				this->LogicalPrintW(L"加入比赛站成功\r\n");
				CString logicalServerStationIDStr;
				logicalServerStationIDStr.Format(L"%d", _logicalLoginRes.LogicalServerStationID);
				((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(logicalServerStationIDStr);
				((CButton *)GetDlgItem(IDC_BUTTON9))->EnableWindow(FALSE);
				((CButton *)GetDlgItem(IDC_BUTTON8))->EnableWindow(TRUE);
			}
				break;
			case Message::Logical::MSG_ASS_MATCH_REQ_QUIT:
			{
				Message::Logical::QuitMatchRes quitMatchRes;
				pack->Deserialize(&quitMatchRes);
				_logicalLoginRes.LogicalServerStationID = 0;
				this->LogicalPrintW(L"已退出比赛\r\n");
				((CEdit *)GetDlgItem(IDC_EDIT6))->SetWindowText(L"");
				((CButton *)GetDlgItem(IDC_BUTTON9))->EnableWindow(TRUE);
				((CButton *)GetDlgItem(IDC_BUTTON8))->EnableWindow(FALSE);
				_logicalSocketThread.Disconnect();
			}
				break;
			default:
				break;
			}
		}
			break;
		default:
			break;
		}
	}
}

void CBlackBoxTestDlg::LobbyPrintA(const char * str)
{
	this->LobbyPrintW(ANSI_2_UNICODE(str).c_str());
}

void CBlackBoxTestDlg::LobbyPrintW(const wchar_t * str)
{
	CEdit * pEdit = (CEdit *)GetDlgItem(IDC_EDIT2);
	const wchar_t * pStr = str;
	int removeLength = 0;
	_lobbyPrintDeque.push_back(str);
	if (_lobbyPrintDeque.size() > PRINT_DEQUE_MAX_COUNT)
	{
		removeLength = (int)_lobbyPrintDeque.front().length();
		_lobbyPrintDeque.pop_front();
	}
	if (removeLength > 0)
	{
		pEdit->SetSel(0, removeLength);
		pEdit->ReplaceSel(L"");
	}
	pEdit->SetSel(-1);
	pEdit->ReplaceSel(pStr);
}

void CBlackBoxTestDlg::LogicalPrintA(const char * str)
{
	this->LogicalPrintW(ANSI_2_UNICODE(str).c_str());
}

void CBlackBoxTestDlg::LogicalPrintW(const wchar_t * str)
{
	CEdit * pEdit = (CEdit *)GetDlgItem(IDC_EDIT1);
	const wchar_t * pStr = str;
	int removeLength = 0;
	_logicalPrintDeque.push_back(str);
	if (_logicalPrintDeque.size() > PRINT_DEQUE_MAX_COUNT)
	{
		removeLength = (int)_logicalPrintDeque.front().length();
		_logicalPrintDeque.pop_front();
	}
	if (removeLength > 0)
	{
		pEdit->SetSel(0, removeLength);
		pEdit->ReplaceSel(L"");
	}
	pEdit->SetSel(-1);
	pEdit->ReplaceSel(pStr);
}

std::string CBlackBoxTestDlg::GetShowedWebHostA()
{
	std::wstring ws = this->GetShowedWebHostW();
	return UNICODE_2_ANSI(ws.c_str());
}

std::wstring CBlackBoxTestDlg::GetShowedWebHostW()
{
	CString webHost;
	((CEdit*)GetDlgItem(IDC_EDIT7))->GetWindowText(webHost);
	return std::wstring(webHost.GetBuffer());
}

BOOL CBlackBoxTestDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN || pMsg->message == WM_KEYUP)
	{
		if (pMsg->wParam == VK_ESCAPE)
		{
			return TRUE;
		}
		if (pMsg->wParam == VK_RETURN)
		{
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CBlackBoxTestDlg::OnBnClickedOk()
{
	//CDialog::OnOK();
}

void CBlackBoxTestDlg::OnBnClickedCancel()
{
	_lobbySocketThread.Disconnect();
	_logicalSocketThread.Disconnect();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	CDialog::OnCancel();
}

void CBlackBoxTestDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case SOCKET_THREAD_UPDATE:
	{
		_lobbySocketThread.Update();
		_logicalSocketThread.Update();
	}
	break;
	case SOCKET_HEARTBEAT_SEND:
	{
		if (_lobbyConnected)
		{
			Message::Common::BeartbeatReq beartbeatReq;
			Message::MsgPackageSend msgPackageSend(Message::Common::MSG_MAIN_TEST, Message::Common::MSG_ASS_TEST_HEARTBEAT, &beartbeatReq);
			_lobbySocketThread.SendData(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		}
		if (_logicalConnected)
		{
			Message::Common::BeartbeatReq beartbeatReq;
			Message::MsgPackageSend msgPackageSend(Message::Common::MSG_MAIN_TEST, Message::Common::MSG_ASS_TEST_HEARTBEAT, &beartbeatReq);
			_logicalSocketThread.SendData(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		}
	}
	break;
	default:
		break;
	}

	CDialog::OnTimer(nIDEvent);
}

void CBlackBoxTestDlg::OnBnClickedButton1()
{
	//大厅服连接
	CString host;
	((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->GetWindowText(host);
	CString port;
	((CEdit *)GetDlgItem(IDC_EDIT3))->GetWindowText(port);
	std::string lobbyHost = UNICODE_2_ANSI(host.GetBuffer());
	std::string lobbyPortStr = UNICODE_2_ANSI(port.GetBuffer());
	if (lobbyPortStr.size() > 0)
	{
		int lobbyPort = atoi(lobbyPortStr.c_str());

		((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->EnableWindow(FALSE);
		((CEdit *)GetDlgItem(IDC_EDIT3))->SetReadOnly(TRUE);
		((CButton *)GetDlgItem(IDC_BUTTON1))->EnableWindow(FALSE);

		RecordInfo::GetInstance()->Save_LobbyHost(lobbyHost);
		RecordInfo::GetInstance()->Save_LobbyPort(lobbyPort);

		_lobbySocketThread.ConnectServer(lobbyHost, lobbyPort);
	}
}

void CBlackBoxTestDlg::OnBnClickedButton2()
{
	//大厅服断开
	_lobbySocketThread.Disconnect();
}

void CBlackBoxTestDlg::OnBnClickedButton3()
{
	//逻辑服断开
	_logicalSocketThread.Disconnect();
}

void CBlackBoxTestDlg::OnBnClickedButton4()
{
	//注册
	std::string webHost = this->GetShowedWebHostA();
	if (webHost.compare("") == 0)
	{
		AfxMessageBox(L"操作失败，尚未设置WebHost");
		return;
	}
	CAccountInputDlg dlg;
	dlg._createType = CAccountInputDlg::CT_REGISTER;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == CAccountInputDlg::IT_ACT)
	{
		RecordInfo::GetInstance()->Save_Account(dlg._account);
		RecordInfo::GetInstance()->Save_Password(dlg._password);

		RegisterAccountReq req;
		req.Account = dlg._account.c_str();
		req.Password = dlg._password.c_str();
		req.Nickname = ANSI_2_UTF8(dlg._nickname.c_str()).c_str();
		req.Sex = dlg._sex;
		Message::MSGString dataJson = WebMsgPackage(&req);
		HttpRequest::RequestSetting reqSetting((webHost + "/api/AccountRegister").c_str(), dataJson.C_Str(), dataJson.Size(),[this](CURLcode performCode, long responseCode, const std::vector<std::string> & headData, const std::string & bodyData, long long custom)->void {
			RegisterAccountRes res;
			if (WebMsgUnPackage(performCode, responseCode, bodyData.c_str(), &res))
			{
				AfxMessageBox(UTF8_2_UNICODE(res.Tips.C_Str()).c_str());
			}
		});
		HttpRequest::GetInstance()->Post(reqSetting);
	}
	else if (nResponse == CAccountInputDlg::IT_UID)
	{
		RecordInfo::GetInstance()->Save_Unionid(dlg._unionid);

		RegisterUnionidReq req;
		req.Unionid = dlg._unionid.c_str();
		req.Nickname = ANSI_2_UTF8(dlg._nickname.c_str()).c_str();
		req.Sex = dlg._sex;
		Message::MSGString dataJson = WebMsgPackage(&req);
		HttpRequest::RequestSetting reqSetting((webHost + "/api/UnionidRegister").c_str(), dataJson.C_Str(), dataJson.Size(), [this](CURLcode performCode, long responseCode, const std::vector<std::string> & headData, const std::string & bodyData, long long custom)->void {
			RegisterUnionidRes res;
			if (WebMsgUnPackage(performCode, responseCode, bodyData.c_str(), &res))
			{
				AfxMessageBox(UTF8_2_UNICODE(res.Tips.C_Str()).c_str());
			}
		});
		HttpRequest::GetInstance()->Post(reqSetting);
	}
}

void CBlackBoxTestDlg::OnBnClickedButton5()
{
	//大厅服登录
	CAccountInputDlg dlg;
	dlg._createType = CAccountInputDlg::CT_LOGIN;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == CAccountInputDlg::IT_ACT)
	{
		RecordInfo::GetInstance()->Save_Account(dlg._account);
		RecordInfo::GetInstance()->Save_Password(dlg._password);

		if (_lobbyConnected)
		{
			Message::Lobby::LoginReq loginReq;
			loginReq.Account = dlg._account.c_str();
			loginReq.Password = dlg._password.c_str();
			Message::MsgPackageSend msgPackageSend(Message::Lobby::MSG_MAIN_LOGIN, Message::Lobby::MSG_ASS_LOGIN_ACCOUNT, &loginReq);
			_lobbySocketThread.SendData(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		}
		else
		{
			AfxMessageBox(L"操作失败，尚未连接服务器");
		}
	}
	else if (nResponse == CAccountInputDlg::IT_UID)
	{
		RecordInfo::GetInstance()->Save_Unionid(dlg._unionid);

		if (_lobbyConnected)
		{
			Message::Lobby::LoginReq loginReq;
			loginReq.Unionid = dlg._unionid.c_str();
			Message::MsgPackageSend msgPackageSend(Message::Lobby::MSG_MAIN_LOGIN, Message::Lobby::MSG_ASS_LOGIN_UNIONID, &loginReq);
			_lobbySocketThread.SendData(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
		}
		else
		{
			AfxMessageBox(L"操作失败，尚未连接服务器");
		}
	}
}

void CBlackBoxTestDlg::OnBnClickedButton6()
{
	if (!_lobbyConnected)
	{
		AfxMessageBox(L"操作失败，尚未连接服务器");
		return;
	}
	if (_lobbyLoginRes.PlayerID <= 0)
	{
		AfxMessageBox(L"操作失败，尚未登录大厅");
		return;
	}
	CCommonInputDlg inputDlg;
	inputDlg._defaultText.Format(L"%lld", _lobbyLoginRes.PlayerID);
	if (inputDlg.DoModal() != IDOK)
	{
		return;
	}
	std::string inputText = UNICODE_2_ANSI(inputDlg._inputContent.GetBuffer());
	std::regex pattern("^[0-9]+$");
	if (inputText.size() == 0 || inputText.size() > 19 || !std::regex_match(inputText, pattern))
	{
		AfxMessageBox(L"无效的玩家ID");
		return;
	}
	PLAYERID_T findID = atoll(inputText.c_str());
	CPlayerInfoDlg dlg(&_lobbySocketThread, &_logicalSocketThread, _lobbyLoginRes.PlayerID, findID);
	dlg.DoModal();
}

void CBlackBoxTestDlg::OnBnClickedButton7()
{
	//请求进入比赛服
	if (!_lobbyConnected)
	{
		AfxMessageBox(L"操作失败，尚未连接服务器");
		return;
	}
	if (_lobbyLoginRes.PlayerID <= 0)
	{
		AfxMessageBox(L"操作失败，尚未登录大厅");
		return;
	}
	Message::Lobby::MatchReq matchReq;
	Message::MsgPackageSend msgPackageSend(Message::Lobby::MSG_MAIN_MATCH, Message::Lobby::MSG_ASS_MATCH_REQ_ADD_SVR, &matchReq);
	_lobbySocketThread.SendData(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
}

void CBlackBoxTestDlg::OnBnClickedButton8()
{
	//请求退出比赛
	if (!_logicalConnected)
	{
		AfxMessageBox(L"操作失败，尚未连接服务器");
		return;
	}
	Message::Logical::QuitMatchReq quitMatchReq;
	Message::MsgPackageSend msgPackageSend(Message::Logical::MSG_MAIN_MATCH, Message::Logical::MSG_ASS_MATCH_REQ_QUIT, &quitMatchReq);
	_logicalSocketThread.SendData(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
}

void CBlackBoxTestDlg::OnBnClickedButton9()
{
	//请求加入比赛
	if (!_logicalConnected)
	{
		AfxMessageBox(L"操作失败，尚未连接服务器");
		return;
	}
	Message::Logical::AddMatchReq addMatchReq;
	Message::MsgPackageSend msgPackageSend(Message::Logical::MSG_MAIN_MATCH, Message::Logical::MSG_ASS_MATCH_REQ_ADD, &addMatchReq);
	_logicalSocketThread.SendData(msgPackageSend.GetBuffer(), msgPackageSend.GetSize());
}

void CBlackBoxTestDlg::OnBnClickedButton10()
{
	CCommonInputDlg inputDlg;
	inputDlg._defaultText = this->GetShowedWebHostW().c_str();
	if (inputDlg.DoModal() != IDOK)
	{
		return;
	}
	if (!(inputDlg._inputContent.Find(L"http://") == 0 && inputDlg._inputContent.GetLength() > 7)
		&& !(inputDlg._inputContent.Find(L"https://") == 0 && inputDlg._inputContent.GetLength() > 8))
	{
		AfxMessageBox(L"错误的URL格式！");
		return;
	}
	if (inputDlg._inputContent.GetBuffer()[inputDlg._inputContent.GetLength() - 1] == L'/')
	{
		inputDlg._inputContent.Delete(inputDlg._inputContent.GetLength() - 1, 1);
	}
	((CEdit*)GetDlgItem(IDC_EDIT7))->SetWindowText(inputDlg._inputContent);
	RecordInfo::GetInstance()->Save_WebHost(UNICODE_2_ANSI(inputDlg._inputContent.GetBuffer()));
}

void CBlackBoxTestDlg::OnBnClickedButton11()
{
	std::string webHost = this->GetShowedWebHostA();
	if (webHost.compare("") == 0)
	{
		AfxMessageBox(L"操作失败，尚未设置WebHost");
		return;
	}

	HttpRequest::RequestSetting reqSetting((webHost + "/api/GetLobbyHost").c_str(), [this](CURLcode performCode, long responseCode, const std::vector<std::string> & headData, const std::string & bodyData, long long custom)->void {
		if (_lobbyConnected)
		{
			AfxMessageBox(L"操作失败，已经连接了大厅服务器");
			return;
		}
		LobbyServerSelectionInfoRes res;
		if (WebMsgUnPackage(performCode, responseCode, bodyData.c_str(), &res))
		{
			((CIPAddressCtrl *)GetDlgItem(IDC_IPADDRESS1))->SetWindowText(ANSI_2_UNICODE(res.Address.C_Str()).c_str());
			CString ps;
			ps.Format(L"%d", res.TcpPort);
			((CEdit *)GetDlgItem(IDC_EDIT3))->SetWindowText(ps);
			AfxMessageBox(L"大厅服务器地址获取成功，已填入地址栏。", MB_OK | MB_ICONINFORMATION);
		}
	});
	HttpRequest::GetInstance()->Get(reqSetting);
}
