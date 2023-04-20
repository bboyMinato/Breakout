#include "../include/Sound.h"
Sound* Sound::_instance = nullptr;

Sound::Sound()
{
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024 == -1))
		std::cout << "Audio library not initialized! " << " " << Mix_GetError() << std::endl;
}

Sound::~Sound()
{
	Mix_FreeMusic(music);
	music = nullptr;
}

void Sound::LoadMusic(std::string filepath)
{	
	music = Mix_LoadMUS(filepath.c_str());

	if (music == nullptr)
		std::cout << "Failed to load the music!" << " " << Mix_GetError() << std::endl;
}

// Number of times to play music
// 0 means play once and stop
// -1 means plays infinitely 
void Sound::PlayMusic(int loops)
{	
	if (music != nullptr)
	{		
		Mix_PlayMusic(music, loops);
	}		
}

void Sound::PauseMusic()
{
	Mix_PauseMusic();
}

// range from 0 to 128
void Sound::SetVolume(int volume)
{
	Mix_VolumeMusic(volume);
}
