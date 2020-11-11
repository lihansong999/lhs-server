#include "PTMain.h"
#include <google/protobuf/message_lite.h>

FW_NS_USEING;


BOOL WINAPI _ConsoleCtrlHandler(DWORD CtrlType)
{
	switch (CtrlType)
	{
	case CTRL_CLOSE_EVENT:
		break;
	case CTRL_C_EVENT:
		break;
	case CTRL_BREAK_EVENT:
		break;
	case CTRL_LOGOFF_EVENT:
		break;
	case CTRL_SHUTDOWN_EVENT:
		break;
	default:
		break;
	}
	return FALSE;
}

int main(int argc, char **argv)
{
	FWOutPut::GetInstance()->CustomPrintPrint([](const char * str)->void {
		printf("%s", str);
	});
	FWOutPut::GetInstance()->CustomLogPrint([](FWOutPut::LOGTYPE t, const char * str)->void {
		printf("%s", str);
	});

	PTMain ptMain;

	SetConsoleCtrlHandler(_ConsoleCtrlHandler, TRUE);

	ptMain.Run();
	
	google::protobuf::ShutdownProtobufLibrary();

	return 0;
}