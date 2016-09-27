#pragma once

// Files from dir
#include <windows.h>
#include <tchar.h> 
#include <stdio.h>
#include <strsafe.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "Syllable.h"
class SoundLoader
{
public:
	SoundLoader();
	~SoundLoader();
	void LoadSounds();
	Sound* MakeSound(char* filePath);
	std::vector<std::string>& GetSounds();
	std::vector<std::string*> StringToSyllables(std::string& string);
	Sound* RandomSound();
private:
	bool IsVowel(char letter);
	std::vector<std::string> m_filePaths;
	std::map<const char*, Sound*> m_soundMap;
};

