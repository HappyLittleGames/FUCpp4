#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class SoundLoader
{
public:
	SoundLoader();
	~SoundLoader();
	void LoadSounds();
	std::vector<std::string> GetSounds();
private:
	std::vector<std::string> m_filePaths;
};

