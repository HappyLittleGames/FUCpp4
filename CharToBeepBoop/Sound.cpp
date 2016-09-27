#include "Sound.h"

Sound::Sound(const char* filename)
{
	m_isPlayable = false;
	m_buffer = 0;
	HInstance = GetModuleHandle(0);

	std::ifstream infile(filename, std::ios::binary);

	if (!infile)
	{
		std::cout << " - Sound::file error: " << filename << std::endl;
		return;
	}

	infile.seekg(0, std::ios::end);   
	int length = infile.tellg();
	m_buffer = new char[length];      
	infile.seekg(0, std::ios::beg);   
	infile.read(m_buffer, length);    

	infile.close();
	m_isPlayable = true;
}

Sound::~Sound()
{
	PlaySound(NULL, 0, 0);  
	delete[] m_buffer;      
}

void Sound::Play(bool async)
{
	LPCWSTR file;
	file = LPCWSTR(m_buffer);

	if (!m_isPlayable)
		return;

	if (async)
		PlaySound(file, HInstance, SND_MEMORY | SND_ASYNC);
	else
		PlaySound(file, HInstance, SND_MEMORY);
}

bool Sound::IsPlayable()
{
	return m_isPlayable;
}

