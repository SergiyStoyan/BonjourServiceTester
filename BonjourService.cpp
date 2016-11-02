#include "stdafx.h"
#include "BonjourService.h"



//BonjourService::BonjourService()
//{
//}
//
//
//BonjourService::~BonjourService()
//{
//}

DNSServiceRef BonjourService::Client = NULL;

void DNSSD_API BonjourService::ServiceRegisterReply(
	DNSServiceRef                       sdRef,
	DNSServiceFlags                     flags,
	DNSServiceErrorType                 errorCode,
	const char                          *name,
	const char                          *regtype,
	const char                          *domain,
	void                                *context
)
{
}

DNSServiceErrorType BonjourService::Start()
{
	DNSServiceRef *sdRef = &BonjourService::Client;
	DNSServiceFlags flags = 0;// kDNSServiceFlagsDefault;
	uint32_t interfaceIndex = 0;
	const char *service_name = "agent1";// "agent1._rfb.tcp.local";
	const char *regType = "_rfb._tcp";
	const char *domain = NULL; // default domain
	const char *host = NULL; // default host
	uint16_t port = 9999;
	uint16_t txtLen = 0;
	const char *txtRecord = NULL; 
	DNSServiceRegisterReply callBack = 	BonjourService::ServiceRegisterReply;

	int err = DNSServiceRegister(
		sdRef,
		flags,
		interfaceIndex,
		service_name,
		regType,
		domain,
		host,
		port,//htons(port),
		txtLen,
		txtRecord,
		callBack,
		NULL
	);

	return err;
}

void BonjourService::Stop()
{
	if (BonjourService::Client != NULL)
		DNSServiceRefDeallocate(BonjourService::Client);
	BonjourService::Client = NULL;
}
