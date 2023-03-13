#include "../include/Ball.h"
#include "../include/TextureManager.h"
#include "../include/Engine.h"

Ball::Ball(Properties* props) : Entity(props)
{	
	Reset();		
}

void Ball::Draw()
{
	TextureManager::GetInstance()->Draw(_textureID, (int)_transform->X, (int)_transform->Y, _width, _height);
}

void Ball::Update()
{
	_transform->TranslateX(_velocity.X);
	_transform->TranslateY(_velocity.Y);

	_box = { (int)_transform->X, (int)_transform->Y, _width, _height };
		
	CheckBounds();
}

void Ball::Clean()
{
	TextureManager::GetInstance()->Clean();
}

void Ball::SetVelocity(float x, float y)
{
	_velocity.X *= x;
	_velocity.Y *= y;
}

void Ball::BounceOfPaddle()
{

}

void Ball::CheckBounds()
{
	if (_transform->X <= 0)
	{		
		_transform->X = 0;		
		_velocity.X *= -1;
	}

	else if (_transform->X + _width >= SCREEN_WIDTH)
	{
		_transform->X = SCREEN_WIDTH - static_cast<float>(_width);		
		_velocity.X *= -1;
	}	

	else if (_transform->Y <= 0)
	{		
		_transform->Y = 0;
		_velocity.Y *= -1;
	}

	else if (_transform->Y + _height >= SCREEN_HEIGHT)
	{		
		Reset();
	}
}

void Ball::Reset()
{
	_transform->X = SCREEN_WIDTH  / 2.0f - _width / 2.0f;
	_transform->Y = SCREEN_HEIGHT / 2.0f - _height / 2.0f;

	InitRandomSpeed();
}

void Ball::InitRandomSpeed()
{
	srand(time(NULL));

	switch (rand() * 10 % 3)
	{
	case 0:
		_velocity.X = 0.05f;
		_velocity.Y = 0.15f;
		break;
	case 1:
		_velocity.X = -0.1f;
		_velocity.Y = -0.2f;
		break;
	case 2:
		_velocity.X = -0.1f;
		_velocity.Y = 0.15f;
		break;
	default:
		break;
	}
}