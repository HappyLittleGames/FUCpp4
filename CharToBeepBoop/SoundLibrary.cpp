#include "SoundLibrary.h"

SoundLibrary *SoundLibrary::m_instance = nullptr;

SoundLibrary* SoundLibrary::GetInstance()
{
	if (m_instance == nullptr)
		m_instance = new SoundLibrary;
	return m_instance;
}

bool SoundLibrary::PlaySequence(std::string word)
{
	std::vector<std::string*> syllables = m_soundLoader->StringToSyllables(word);
	printf("\nC2BB:	<\"");
	for each (std::string* syllable in syllables)
	{
		PlaySyllable(*syllable);

		std::cout << *syllable;

	}
	printf("\"> endl;\n");
	return false;
}


void SoundLibrary::LoadFiles()
{
	m_soundLoader->LoadSounds();
}

void SoundLibrary::PrintFiles()
{
	for each (std::string file in m_soundLoader->GetSounds())
	{
		std::cout << file << std::endl;
	}
}


void SoundLibrary::PlaySyllable(std::string syllable)
{
	// the flyweight, move to loader and make it a factory
	if (m_syllableMap.find(syllable) != m_syllableMap.end())
	{
		m_syllableMap[syllable]->Play();
	}
	else
	{
		m_syllableMap.emplace(syllable, new Syllable(syllable, m_soundLoader->RandomSound()));
		m_syllableMap[syllable]->Play();
	}
}


SoundLibrary::SoundLibrary()
{
	m_instance = this;
	m_soundLoader = new SoundLoader();
	LoadFiles();
}


SoundLibrary::~SoundLibrary()
{
}

void SoundLibrary::PlayLetter(char letter)
{
}
