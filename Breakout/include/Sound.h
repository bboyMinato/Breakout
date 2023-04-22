#pragma once
#include "SDL.h"
#include "SDL_mixer.h"
#include <iostream>
#include <string>
#include <map>

//make this singleton
class Sound
{
public:
	Sound();
	~Sound();

	Mix_Music* LoadMusic(std::string id, std::string filepath);

	// Number of times to play music
	// 0 means play once and stop
	// -1 means plays infinitely 
	void PlayMusic(int loops);
	void PauseMusic();
	void SetVolume(int volume);

private:	
	static Sound* _instance;
	Mix_Music* _music = nullptr;
	std::map<std::string, Mix_Music*> _soundMap;
};

