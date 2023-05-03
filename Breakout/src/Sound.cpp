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

Mix_Music* Sound::LoadMusic(std::string ID, std::string filepath)
{	
	_music = Mix_LoadMUS(filepath.c_str());

	if (_music == nullptr)
		std::cout << "Failed to load the music!" << " " << Mix_GetError() << std::endl;

	_soundMap[ID] = _music;

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

void Sound::SetMusicVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

Mix_Chunk* Sound::LoadChunk(std::string ID, std::string filepath)
{
	if (filepath != "")
	{
		_chunk = Mix_LoadWAV(filepath.c_str());
	}	

	if (_chunk == nullptr)
		std::cout << "Failed to load the chunk! Error: " << Mix_GetError() << std::endl;

	_chunkMap[ID] = _chunk;
	
	return _chunk;
}

void Sound::PlayChunk(std::string ID)
{
	if (_chunk != nullptr)
	{
		Mix_PlayChannel(-1, _chunkMap[ID], 1);
	}
}
