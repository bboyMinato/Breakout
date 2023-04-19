#include "../include/Brick.h"
#include "../include/Engine.h"
#include "../include/CollisionHandler.h"

Brick::Brick(BrickType* bricktype)
{
	_width = 92;
	_height = 32;
	_bricktype = bricktype;	
	_healthPoints = _bricktype->hitPoints;

	_box = { static_cast<int>(_position.X), static_cast<int>(_position.Y), _width, _height };
}	

Brick::~Brick()
{
}

void Brick::Render()
{
	TextureManager::GetInstance()->Draw(_bricktype->ID, _position.X, _position.Y, _width, _height);
}

void Brick::Update()
{

}

void Brick::Clean()
{
	
}

void Brick::SetBox(int x, int y)
{
	_box.x = x;
	_box.y = y;
}

void Brick::TakeDamage()
{
	_healthPoints--;	
}
	