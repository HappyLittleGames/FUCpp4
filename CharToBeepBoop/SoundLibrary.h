#pragma once
#include <atlbase.h>
#include <Windows.h>
#include "SoundLoader.h"

class SoundLibrary
{
	static SoundLibrary* s_instance;

public:
	static SoundLibrary* GetInstance();

	bool PlaySequence(std::string word);
	bool PlayRandSequence(std::string word);
	static std::string RandomBeep(std::vector<std::string> sounds);

private:
	SoundLoader* m_soundLoader;
	SoundLibrary();
	~SoundLibrary();

};

