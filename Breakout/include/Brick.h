#pragma once
#include "Entity.h"
#include "SDL.h"
#include <vector>
#include "TextureManager.h"
#include "Vector2D.h"
#include <limits>

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
	
	//setters
	void SetPositionX(float pos) { _position.X = pos; }
	void SetPositionY(float pos) { _position.Y = pos; }
	void SetBox(int x, int y);

	//getters
	inline int GetWidth() { return _width; }
	inline int GetHeight() { return _height; }
	inline Vector2D GetPosition() { return _position; }	
	inline float GetHP() { return _healthPoints; }
	inline int GetBreakScore() { return BreakScore;  }

	void TakeDamage();
	SDL_Rect _box = { 0, 0, 0, 0 };
	std::string _brickTypeID;
	std::string _hitSoundID;

protected:
	int _width = 0;
	int _height = 0;
	float _healthPoints = 0;
	int BreakScore = 0; 

	BrickType* _bricktype = nullptr;
	Vector2D _position;		
};