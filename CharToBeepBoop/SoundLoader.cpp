#include "SoundLoader.h"



SoundLoader::SoundLoader()
{
}


SoundLoader::~SoundLoader()
{
}

void SoundLoader::LoadSounds()
{
	// should read the directory though
	std::ifstream file("clips\\reg.txt");
	if (file)
	{
		std::string str;
		m_filePaths.clear();
		while (std::getline(file, str))
		{
			m_filePaths.push_back(str);
		}

		std::cout << "paths: " << std::endl;
		for each (std::string path in m_filePaths)
		{
			std::cout << path << std::endl;
		}
	}
	else
	{
		std::cout << "LoadSounds() failed to find specified path" << std::endl;
	}
}

std::vector<std::string> SoundLoader::GetSounds()
{
	// flyweight this!! like the whole point eeeeh

	return m_filePaths;
}
