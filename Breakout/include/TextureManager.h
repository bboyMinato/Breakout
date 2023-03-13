#pragma once
#include "SDL_image.h"
#include <string>
#include <iostream>
#include <map>

class TextureManager
{
public:
	static TextureManager* GetInstance() { return _instance = (_instance != nullptr) ? _instance : new TextureManager(); }
	
	SDL_Texture* LoadTexture(std::string id, std::string filepath);

	void Draw(std::string id, int x, int y, int width, int heigth);
	void Clean();
	
private:
	TextureManager() {}
	static TextureManager* _instance;

	SDL_Texture* _texture = nullptr;
	std::map<std::string, SDL_Texture*> _textureMap;
};

