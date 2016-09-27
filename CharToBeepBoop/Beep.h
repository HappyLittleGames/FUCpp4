#pragma once
#include "Sound.h"

class Beep : public Sound
{
public:
	Beep();
	~Beep();
	char GetLetter() const;
	void SetLetter(char letter);
private:
	char m_letter;
};

