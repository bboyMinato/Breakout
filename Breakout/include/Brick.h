#pragma once
#include "Entity.h"
#include "SDL.h"
#include <vector>
#include "TextureManager.h"
#include "Vector2D.h"

struct BrickType
{	
	int hitPoints = 0;
	int breakScore = 0;
	std::string texture;
	std::string ID;
	std::string hitSound;
	std::string breakSound;	
};

using BrickTypeList = std::vector <BrickType>;
using Board = std::vector<std::vector<std::string>>;

class Brick 
{
public:	
	Brick(BrickType* bricktype);
	~Brick();

	void Render();
	void Update();
	void Clean();
	
	void SetPositionX(float pos) { _position.X = pos; }
	void SetPositionY(float pos) { _position.Y = pos; }

	inline int GetWidth() { return _width; }
	inline int GetHeight() { return _height; }

	SDL_Rect _box = { 0,0,0,0 };

protected:
	int _width = 0;
	int _height = 0;

	BrickType* _bricktype = nullptr;
	Vector2D _position;	

	//std::vector<Brick*> _bricks;
};