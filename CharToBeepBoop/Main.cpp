#ifdef _WIN32
#pragma comment( lib, "Winmm.lib" )
#include <Windows.h>

#include "SoundLibrary.h"
#endif 
#include <iostream>

int main()
{
#ifndef _WIN32
	std::cout << "is not windows :(";
	return 0;
#endif

	SoundLibrary* soundLib = SoundLibrary::GetInstance();
	std::string what = "I am a robot, eep oop";

	while (what != "exit")
	{
		if (what == "1")
		{
			soundLib->LoadFiles();
		}
		else if (what == "2")
		{
			soundLib->PrintFiles();
		}
		else
		{
			soundLib->PlaySequence(what);
		}

		printf("user>: ");
		std::cin >> what;
	}
	
	return 0;
}



