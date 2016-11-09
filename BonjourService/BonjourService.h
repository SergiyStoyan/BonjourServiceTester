
#pragma once
//#include <unordered_map>
//#include <unordered_set>
#include "dns_sd.h"

class BonjourService
{
public:
	//BonjourService();
	//~BonjourService();

	static DNSServiceRef Service;

	static DNSServiceErrorType Start(const char *service_name, DNSServiceRegisterReply callBack);
	static void Stop();
	
	static void DNSSD_API BonjourService::ServiceRegisterReply(
		DNSServiceRef                       sdRef,
		DNSServiceFlags                     flags,
		DNSServiceErrorType                 errorCode,
		const char                          *name,
		const char                          *regtype,
		const char                          *domain,
		void                                *context
	);
};

