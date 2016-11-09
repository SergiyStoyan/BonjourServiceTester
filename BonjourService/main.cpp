// BonjourService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BonjourService.h"
#include <string>
#include <iostream>
#include <conio.h>


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


int main()
{
	const char *service_name = "agent123";
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
