#include "../include/Level.h"
#include "../include/Engine.h"
#include "../include/CollisionHandler.h"
Brick* brick;

Level::Level(int rowCount, int colCount, int rowSpacing, int colSpacing, BrickTypeList bricklist, Board grid)
{
	_rowCount = rowCount;
	_colCount = colCount;
	_rowSpacing = rowSpacing;
	_colSpacing = colSpacing;
	_brickType = bricklist;
	_board = grid;

	for (size_t i = 0; i < _brickType.size(); i++)
		TextureManager::GetInstance()->LoadTexture(_brickType[i].ID, _brickType[i].texture);		

	for (size_t i = 0; i < _rowCount; i++)
	{
		for (size_t j = 0; j < _colCount; j++)
		{
			std::string brickID = _board[i][j];

			for (auto k = 0; k < _brickType.size(); k++)
			{
				if (brickID == "S")
				{
					brick = new Brick(&_brickType[k]);
					brick->SetPositionX(colSpacing + j * brick->GetWidth());
					brick->SetPositionY(rowSpacing + i * brick->GetHeight());	
					brick->SetBox(brick->GetPosition().X, brick->GetPosition().Y);
					_bricks.push_back(brick);
					break;
				}

				else if (brickID == "M")
				{
					brick = new Brick(&_brickType[1]);
					brick->SetPositionX(colSpacing + j * brick->GetWidth());
					brick->SetPositionY(rowSpacing + i * brick->GetHeight());
					brick->SetBox(brick->GetPosition().X, brick->GetPosition().Y);
					_bricks.push_back(brick);
					break;
				}

				else if (brickID == "H")
				{
					brick = new Brick(&_brickType[2]);
					brick->SetPositionX(colSpacing + j * brick->GetWidth());
					brick->SetPositionY(rowSpacing + i * brick->GetHeight());	
					brick->SetBox(brick->GetPosition().X, brick->GetPosition().Y);				
					_bricks.push_back(brick);
					break;
				}

				else if (brickID == "I")
				{
					brick = new Brick(&_brickType[3]);
					brick->SetPositionX(colSpacing + j * brick->GetWidth());
					brick->SetPositionY(rowSpacing + i * brick->GetHeight());	
					brick->SetBox(brick->GetPosition().X, brick->GetPosition().Y);
					_bricks.push_back(brick);					
					break;
				}
			}				
		}	
	}

	_paddle = new Paddle(new Properties("player", 433, 980, 158, 20));
	_ball = new Ball(new Properties("ball", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 16, 16));	
}

void Level::Render()
{	
	for (auto i = 0; i < _bricks.size(); i++)
	{
		_bricks[i]->Render();
	}
	_paddle->Draw();
	_ball->Draw();
}

void Level::Update()
{
	_paddle->Update();
	_ball->Update();

	BounceOfPaddle();
	CollisionWithBricks();

	for (auto i = 0; i < _bricks.size(); i++)
	{		
		if (_bricks[i]->GetHP() <= 0)
		{
			_bricks.erase(_bricks.begin() + i);
		}
	}
}

Level::~Level()
{
	delete brick;
}

void Level::BounceOfPaddle()
{
	if (CollisionHandler::GetInstance()->CheckCollision(_paddle, _ball) && _ball->_box.x < _paddle->_box.x + _paddle->_box.w / 2)
	{
		_ball->SetVelocity(-1, -1);
	}

	else if (CollisionHandler::GetInstance()->CheckCollision(_paddle, _ball) && _ball->_box.x > _paddle->_box.x + _paddle->_box.w / 2)
	{
		_ball->SetVelocity(1, -1);
	}
}

void Level::CollisionWithBricks()
{
	for (auto i = 0; i < _bricks.size(); i++)
	{		
		if (CollisionHandler::GetInstance()->CheckCollision(_ball, _bricks[i]))
		{
			_ball->Bounce();
			_bricks[i]->TakeDamage();
						
		}
	}
}