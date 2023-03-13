#include "../include/TextureManager.h"
#include "../include/Engine.h"
TextureManager* TextureManager::_instance = nullptr;

SDL_Texture* TextureManager::LoadTexture(std::string id, std::string filepath)
{
	_texture = IMG_LoadTexture(Engine::GetInstance()->GetRenderer(), filepath.c_str());

	if (_texture == nullptr)
		std::cout << "Failed to load the texture. Error: " << SDL_GetError() << " " << id << std::endl;	

	_textureMap[id] = _texture;

	return _texture;
}

void TextureManager::Draw(std::string id, int x, int y, int width, int heigth)
{
	SDL_Rect src = { 0, 0, width, heigth };
	SDL_Rect dst = { x, y, width, heigth };
	SDL_RenderCopy(Engine::GetInstance()->GetRenderer(), _textureMap[id], &src, &dst);
}

void TextureManager::Clean()
{
	std::map<std::string, SDL_Texture*>::iterator it;

	for (it = _textureMap.begin(); it != _textureMap.end(); it++)
		SDL_DestroyTexture(it->second);

	_textureMap.clear();
}
