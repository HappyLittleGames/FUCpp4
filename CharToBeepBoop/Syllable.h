#pragma once
#include "Sound.h"
class Syllable
{
public:
	Syllable(std::string syllable, Sound* sound);
	~Syllable();
	void Play();
private:
	std::string m_syllable;
	Sound* m_sound;
};

