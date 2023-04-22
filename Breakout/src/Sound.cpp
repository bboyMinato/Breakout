#include "../include/Sound.h"
Sound* Sound::_instance = nullptr;

Sound::Sound()
{
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024 == -1))
		std::cout << "Audio library not initialized! " << " " << Mix_GetError() << std::endl;
}

Sound::~Sound()
{
	Mix_FreeMusic(_music);
	_music = nullptr;
}

Mix_Music* Sound::LoadMusic(std::string id, std::string filepath)
{	
	_music = Mix_LoadMUS(filepath.c_str());

	if (_music == nullptr)
		std::cout << "Failed to load the music!" << " " << Mix_GetError() << std::endl;

	_soundMap[id] = _music;

	return _music;
}


void Sound::PlayMusic(int loops)
{	
	if (_music != nullptr)
	{		
		Mix_PlayMusic(_music, loops);
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
