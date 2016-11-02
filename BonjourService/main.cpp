// BonjourService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BonjourService.h"
#include <string>
#include <iostream>


int main()
{
	DNSServiceErrorType err = BonjourService::Start();
	if (err == 0) 
	{
		std::cout << "Service registered..." << std::endl;
	}
	else 
	{
		std::cout << "ERROR while registering service" << std::endl;
		return 1;
	}

	Sleep(10000);
	BonjourService::Stop();
	std::cout << "Service stopped..." << std::endl;
	Sleep(10000);
    return 0;
}

