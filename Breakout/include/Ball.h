#pragma once
#include "Entity.h"
#include "Vector2D.h"
#include "Transform.h"
#include <math.h>

class Ball : public Entity
{
public:
	Ball(Properties* props);

	virtual void Draw();
	virtual void Update();
	virtual void Clean();
	void Bounce();

	void SetVelocity(float x, float y);

private:
	void CheckBounds();
	void Reset();
	void InitRandomSpeed();
	bool _alive = false;
	bool _isMoving = false;

	Vector2D _velocity;
};