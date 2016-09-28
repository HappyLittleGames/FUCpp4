#include "SoundLoader.h"



SoundLoader::SoundLoader()
{
	m_filePaths.clear();
}


SoundLoader::~SoundLoader()
{
}


void SoundLoader::LoadSounds()
{

	std::cout << "initiating SoundLoader vector" << std::endl;
	std::cout << "loading entries from" << " clips\\reg.txt" << std::endl;
	std::ifstream file("clips\\reg.txt");
	if (file)
	{
		std::string str;
		m_filePaths.clear();
		while (std::getline(file, str))
		{
			m_filePaths.push_back("clips\\"+str);
#ifdef _DEBUG
			std::cout << "added " << m_filePaths.back() << std::endl;
#endif
		}
	}
	else
	{
		std::cout << "SoundLoader::LoadSounds failed to find specified registry" << std::endl;
	}
}


Sound* SoundLoader::RandomSound()
{
	int random = rand() % m_filePaths.size();
	if (m_soundMap.find(m_filePaths[random].c_str()) != m_soundMap.end())
	{
		return m_soundMap[m_filePaths[random].c_str()];
	}
	else
	{
		m_soundMap.emplace(m_filePaths[random].c_str(), new Sound(m_filePaths[random].c_str()));
		return m_soundMap[m_filePaths[random].c_str()];
	}
}


std::vector<std::string>& SoundLoader::GetSounds()
{
	return m_filePaths;
}


std::vector<std::string*> SoundLoader::StringToSyllables(std::string & string)
{
	std::vector<std::string*> syllables{};
	std::string currentSyllable{};
	int i = 0;
	for each (char letter in string)
	{
		i++;
		if ((i == string.size()) || (currentSyllable.size() > 5)) // syllables can't be longer than 5, yeah.
		{
			currentSyllable.push_back(letter);
			syllables.push_back(new std::string(currentSyllable));
			currentSyllable.clear();
		}
		else if (IsVowel(letter))
		{
			currentSyllable.push_back(letter);
		}
		else
		{
			currentSyllable.push_back(letter);
			syllables.push_back(new std::string(currentSyllable));
			currentSyllable.clear();
		}
	}
	return syllables;
}


bool SoundLoader::IsVowel(char letter)
{
	switch (toupper(letter))
	{
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
	case 'Y':
		return true;
		break;
	default:
		return false;
		break;

	}
}
