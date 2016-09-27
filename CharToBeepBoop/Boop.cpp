#include "Boop.h"


Boop::~Boop()
{
}

char Boop::GetSyllable() const
{
	return m_syllable;
}

void Boop::SetSyllable(char syllable)
{
	m_syllable = syllable;
}
