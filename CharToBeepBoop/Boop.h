#pragma once
#include "Sound.h"
class Boop : public Sound
{
public:
	Boop();
	~Boop();
	char GetSyllable() const;
	void SetSyllable(char  syllable);
private:
	char m_syllable;
};

