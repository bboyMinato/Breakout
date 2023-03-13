#pragma once
#include "Entity.h"
#include "SDL.h"
#include <vector>

struct BrickType
{	
	int hitPoints = 0;
	int breakScore = 0;
	std::string source;
	std::string ID;
};

using BrickTypeList = std::vector <BrickType>;

class Brick
{
public:
	Brick();
	~Brick();

	void Render();
	void Update();

protected:
	int _width = 0;
	int _height = 0;
	int _hitPoints = 0;
	int _breakScore = 0;
	SDL_Texture* _texture = nullptr;
};