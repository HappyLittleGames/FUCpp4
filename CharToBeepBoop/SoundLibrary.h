#pragma once
#include <atlbase.h>
#include <Windows.h>
#include "SoundLoader.h"

class SoundLibrary
{
	static SoundLibrary* m_instance;

public:
	static SoundLibrary* GetInstance();
	bool PlaySequence(std::string word);
	void LoadFiles();
	void PrintFiles();
	void PlaySyllable(std::string syllable);
private:
	SoundLoader* m_soundLoader;
	std::map<std::string, Syllable*> m_syllableMap;
	SoundLibrary();
	~SoundLibrary();
	void PlayLetter(char letter);
};

