#include "../include/Brick.h"
#include "../include/Engine.h"
#include "../include/CollisionHandler.h"

Brick::Brick(BrickType* bricktype)
{	
	_width = 92;
	_height = 32;
	_bricktype = bricktype;	
	_position.X = 25;
	_position.Y = 25;

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
	//if(CollisionHandler::GetInstance()->CheckCollision(ball)
}

void Brick::Clean()
{
	
}
	