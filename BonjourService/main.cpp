// BonjourService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BonjourService.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <ctime>
#include <stdexcept>

void DNSSD_API ServiceRegisterReply(
	DNSServiceRef                       sdRef,
	DNSServiceFlags                     flags,
	DNSServiceErrorType                 errorCode,
	const char                          *name,
	const char                          *regtype,
	const char                          *domain,
	void                                *context
)
{
	printf("ServiceRegisterReply: errorCode=%d, name=%s\r\n", errorCode, name);
}

BOOL WINAPI HandlerRoutine(_In_ DWORD dwCtrlType)
{
	switch (dwCtrlType) {
	case CTRL_C_EVENT:
	case CTRL_BREAK_EVENT:
	case CTRL_CLOSE_EVENT:
	case CTRL_LOGOFF_EVENT:
	case CTRL_SHUTDOWN_EVENT:
		BonjourService::Stop();
		break;
	}
	return FALSE;
}

int main1(){ 
	try
	{
		Sleep(10000);
	}
	catch (...)
	{
		
	}
	Sleep(10000);
	return 0;
}

int main()
{
	if (!SetConsoleCtrlHandler(HandlerRoutine, TRUE))
	{
		printf("ERROR: Could not SetConsoleCtrlHandler!\r\n");
		printf("Press any key to exit...\r\n");
		_getch();
		return 1;
	}

	char service_name[64]; 
	time_t t = time(0); 
	struct tm now = tm();
	localtime_s(&now, &t);
	sprintf_s(service_name, "agent-%d-%d-%d-%d-%d-%d", now.tm_year, now.tm_mon, now.tm_mday, now.tm_hour, now.tm_min, now.tm_sec);
	DNSServiceErrorType err = BonjourService::Start(service_name, ServiceRegisterReply);
	if (err != 0)
	{
		printf("ERROR while registering service: errorCode=%d\r\n", err);
		printf("Press any key to exit...\r\n");
		_getch();
		return 1;
	}

	printf("Service registered successfully: name=%s\r\n", service_name);
	printf("Press any key to unload...\r\n");
	_getch();
	BonjourService::Stop();
	printf("Service stopped...\r\n");
	Sleep(1000);
	return 0;
}