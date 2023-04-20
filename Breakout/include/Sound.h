#pragma once
#include "SDL.h"
#include "SDL_mixer.h"
#include <iostream>
#include <string>


//make this singleton
class Sound
{
public:
	Sound();
	~Sound();

	void LoadMusic(std::string filepath);
	void PlayMusic(int loops);
	void PauseMusic();
	void SetVolume(int volume);

private:	
	static Sound* _instance;
	Mix_Music* music = nullptr;
};

