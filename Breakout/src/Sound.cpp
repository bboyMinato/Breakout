#include "../include/Sound.h"
Sound* Sound::_instance = nullptr;

Sound::Sound()
{
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024 == -1))
	{
		std::cout << "Audio library not initialized! " << " " << Mix_GetError() << std::endl;
	}		
}

Sound::~Sound()
{
	Mix_FreeMusic(_music);
	delete _music;
	_soundMap.clear();

	Mix_FreeChunk(_chunk);
	delete _chunk;
	_chunkMap.clear();	 
}

void Sound::LoadMusic(std::string ID, std::string filepath)
{	
	if (filepath != "")
	{
		_music = Mix_LoadMUS(filepath.c_str());
	}

	if (_music == nullptr)
	{
		std::cout << "Failed to load the music!" << " " << Mix_GetError() << std::endl;
	}		

	if (_soundMap[ID] != _music)
	{
		_soundMap[ID] = _music;
	}	
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

void Sound::SetMusicVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

void Sound::LoadChunk(std::string ID, std::string filepath)
{
	if (filepath != "")
	{
		_chunk = Mix_LoadWAV(filepath.c_str());
	}

	if (_chunk == nullptr)
	{
		std::cout << "Failed to load the chunk! Error: " << Mix_GetError() << std::endl;
	}
		
	if (_chunkMap[ID] != _chunk)
	{
		_chunkMap[ID] = _chunk;
	}
}

void Sound::PlayChunk(std::string ID)
{
	if (_chunk != nullptr)
	{
		Mix_PlayChannel(-1, _chunkMap[ID], 0);
	}
}

void Sound::SetChunkVolume(Mix_Chunk* chunk, int volume)
{
	Mix_VolumeChunk(chunk, volume);
}
