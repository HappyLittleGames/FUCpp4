#include "SoundLibrary.h"

SoundLibrary *SoundLibrary::s_instance = nullptr;

SoundLibrary* SoundLibrary::GetInstance()
{
	if (s_instance != nullptr)
		s_instance = new SoundLibrary;
	return s_instance;
}

bool SoundLibrary::PlaySequence(std::string word)
{
	int i = 0;
	int end = word.size();
	printf("\nC2BB:	<\"");
	while (i < end)
	{
		// SoundLoader(word[i]);
		PlaySound(TEXT("clips\\audio3"), NULL, SND_FILENAME);
		std::cout << word.at(i);
		i++;
	}
	printf("\"> endl;\n");
	return false;
}


bool SoundLibrary::PlayRandSequence(std::string word)
{
	int i = 0;
	int end = word.size();
	printf("\nC2BB:	<\"");
	while (i < end)
	{
		//std::string path = m_soundLoader->GetSounds().at(rand() % m_soundLoader->GetSounds().size()).c_str();
		//LPCSTR path = m_soundLoader->GetSounds().at(rand() % m_soundLoader->GetSounds().size()).c_str();
		//LPCWSTR widePath = CA2W(m_soundLoader->GetSounds().at(rand() % m_soundLoader->GetSounds().size()).c_str());

		int random = rand() % 3 + 1;
		if (random == 1)
			PlaySound(TEXT("clips\\audio1"), NULL, SND_FILENAME);
		if (random == 2)
			PlaySound(TEXT("clips\\audio2"), NULL, SND_FILENAME);
		if (random == 3)
			PlaySound(TEXT("clips\\audio3"), NULL, SND_FILENAME);

		//PlaySound(widePath, NULL, SND_FILENAME);
		std::cout << word.at(i);
		i++;
	}
	printf("\"> endl;\n");
	return false;
}


std::string SoundLibrary::RandomBeep(std::vector<std::string> sounds)
{
	int sound = std::rand() % sounds.size();
	return sounds[sound];
}



SoundLibrary::SoundLibrary()
{
	s_instance = this;
	m_soundLoader = new SoundLoader();
	m_soundLoader->LoadSounds();
}


SoundLibrary::~SoundLibrary()
{
}
