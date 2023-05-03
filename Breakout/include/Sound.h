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
	static Sound* GetInstance() { return _instance = (_instance != nullptr) ? _instance : new Sound(); }
	~Sound();

	// Load music into the map 
	// ID is the ID that will be used to store and access the music
	// filepath is the source path of the music 
	Mix_Music* LoadMusic(std::string ID, std::string filepath);

	// Number of times to play music
	// 0 means play once and stop
	// -1 means plays infinitely 
	void PlayMusic(int loops);

	// Pause music
	void PauseMusic();

	// Set volume of music (range from 0 to 128)
	void SetMusicVolume(int volume);

	// Load chunk into the map 
	// ID is the ID that will be used to store and access the chunk
	// filepath is the source path of the music 
	Mix_Chunk* LoadChunk(std::string ID, std::string filepath);

	// Play requested chunk
	void PlayChunk(std::string ID);

private:	
	Sound();
	static Sound* _instance;
	Mix_Music* _music = nullptr;
	Mix_Chunk* _chunk = nullptr;

	std::map<std::string, Mix_Music*> _soundMap;
	std::map<std::string, Mix_Chunk*> _chunkMap;
};

