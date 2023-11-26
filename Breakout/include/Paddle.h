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

	void IncreaseScore(int value)
	{
		Score += value; 
		std::cout << Score << std::endl;
	}

private:
	bool CheckBounds();
	int Score = 0;

	float _lastSafePosition = 0;
	
};