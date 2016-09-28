#pragma once

#include <atlbase.h>
#include <Windows.h>
#include "Syllable.h"
#include "SoundLoader.h"

class SoundLibrary
{
	static SoundLibrary* m_instance;

public:
	static SoundLibrary* GetInstance();
	bool PlaySequence(std::string word);
	void LoadFiles();
	void PrintFiles();
	
private:
	SoundLoader* m_soundLoader;
	std::map<std::string, Syllable*> m_syllableMap;
	SoundLibrary();
	~SoundLibrary();
	void PlaySyllable(std::string syllable);
	void PlayLetter(char letter);
};

