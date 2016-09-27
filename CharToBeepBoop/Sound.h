#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <fstream>
#include <conio.h>

class Sound {

public:
	Sound(const char* filename);
	~Sound();
	void Play(bool async = false);
	bool IsPlayable();

private:
	char* m_buffer;
	bool m_isPlayable;
	HINSTANCE HInstance;
};
