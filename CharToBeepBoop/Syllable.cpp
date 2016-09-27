#include "Syllable.h"



Syllable::Syllable(std::string syllable, Sound* sound)
{
	m_syllable = syllable;
	m_sound = sound;
}


Syllable::~Syllable()
{
}

void Syllable::Play()
{
	m_sound->Play();
}
