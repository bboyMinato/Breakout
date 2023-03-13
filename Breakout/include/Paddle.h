#pragma once
#include "Entity.h"
constexpr float PADDLE_SPEED = 0.15f;

class Paddle : public Entity
{
public:	
	Paddle(Properties* props);

	virtual void Draw();
	virtual void Update();
	virtual void Clean();

private:
	bool CheckBounds();

	float _lastSafePosition = 0;
};