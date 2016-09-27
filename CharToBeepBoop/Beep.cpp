#include "Beep.h"


Beep::~Beep()
{
}

char Beep::GetLetter() const
{
	return m_letter;
}

void Beep::SetLetter(char letter)
{
	m_letter = letter;
}
