#include "../include/Paddle.h"
#include "../include/TextureManager.h"
#include "../include/Input.h"
#include "../include/Engine.h"

Paddle::Paddle(Properties* props) : Entity(props)
{
}

void Paddle::Draw()
{		
	TextureManager::GetInstance()->Draw(_textureID, _transform->X, _transform->Y, _width, _height);
}

void Paddle::Update()
{
	_box = { (int)_transform->X, (int)_transform->Y, _width, _height };

	_lastSafePosition = _transform->X;

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A) || Input::GetInstance()->GetKeyDown(SDL_SCANCODE_LEFT))
	{
		_transform->X -= PADDLE_SPEED;
	}

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D) || Input::GetInstance()->GetKeyDown(SDL_SCANCODE_RIGHT))
	{
		_transform->X += PADDLE_SPEED;
	}		

	if (CheckBounds())	
		_transform->X = _lastSafePosition;		
}

void Paddle::Clean()
{
	TextureManager::GetInstance()->Clean();
}

bool Paddle::CheckBounds()
{
	if (_transform->X <= 0 || _transform->X + _width >= SCREEN_WIDTH)		
		return true;
	
	return false;
}
