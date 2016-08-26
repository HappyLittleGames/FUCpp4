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

	std::string what = "hello";
	while (what != "exit")
	{
		if (what == "1")
		{
			if (PlaySound(TEXT("clips\\audio1"), NULL, SND_FILENAME)) // SND_ASYNC leaves out wait :)
				std::cout << "played //audio1\n";
		}
		else if (what == "2")
		{
			if (PlaySound(TEXT("clips\\audio2"), NULL, SND_FILENAME | SND_ASYNC))
				std::cout << "played //audio\n";
		}
		else if (what == "3")
		{
			if (soundLib->PlaySequence("words"))
				std::cout << "done playing words\n";	
		}
		else if (what == "4")
		{
			if (soundLib->PlayRandSequence("words"))
				std::cout << "done playing words\n";
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



