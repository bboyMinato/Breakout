#pragma once
#include <vector>
#include "TextureManager.h"
#include "Brick.h"
#include "Ball.h"
#include "Paddle.h"

class Level
{
public:
	Level(int rowCount, int colCount, int rowSpacing, int colSpacing, BrickTypeList bricklist, Board grid);
	Level() {}
	void Render();
	void Update();	

	std::vector<Brick*> _bricks;
private:
	~Level();
	int _rowCount = 0;
	int _colCount = 0;
	int _rowSpacing = 0;
	int _colSpacing = 0;	
	BrickTypeList _brickType;	
	Board _board;		
	Ball* _ball = nullptr;
	Paddle* _paddle = nullptr;
	Brick* brick = nullptr;	

	void BounceOfPaddle();
	void CollisionWithBricks();
};

