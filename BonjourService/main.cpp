// BonjourService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BonjourService.h"
#include <string>
#include <iostream>
#include <conio.h>


int main()
{
	DNSServiceErrorType err = BonjourService::Start();
	if (err != 0) 
	{
		std::cout << "ERROR while registering service..." << std::endl;
		std::cout << "Press any key to exit..." << std::endl;
		_getch();
		return 1;
	}

	std::cout << "Service registered." << std::endl;
	std::cout << "Press any key to unload..." << std::endl;
	_getch();
	BonjourService::Stop();
	std::cout << "Service stopped..." << std::endl;
	Sleep(1000);
    return 0;
}

