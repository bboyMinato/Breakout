#include "../include/Level.h"
#include "../include/Engine.h"
#include "../include/CollisionHandler.h"

Level::Level(int rowCount, int colCount, int rowSpacing, int colSpacing, BrickTypeList bricklist, Board grid)
{
	_rowCount = rowCount;
	_colCount = colCount;
	_rowSpacing = rowSpacing;
	_colSpacing = colSpacing;
	_brickType = bricklist;
	_board = grid;

	for (auto i = 0; i < _brickType.size(); i++)
	{
		TextureManager::GetInstance()->LoadTexture(_brickType[i].ID, _brickType[i].texture);	
		Sound::GetInstance()->LoadChunk(_brickType[i].ID, _brickType[i].breakSound);
	}	

	for (auto i = 0; i < _rowCount; i++)
	{
		for (auto j = 0; j < _colCount; j++)
		{
			std::string brickID = _board[i][j];

			for (auto k = 0; k < _brickType.size(); k++)
			{				
				if (brickID == _brickType[k].ID)
				{
					_brick = new Brick(&_brickType[k]);
					_brick->SetPositionX(colSpacing + j * _brick->GetWidth());
					_brick->SetPositionY(rowSpacing + i * _brick->GetHeight());
					_brick->SetBox(_brick->GetPosition().X, _brick->GetPosition().Y);
					_bricks.push_back(_brick);
				}
			}				
		}	
	}		
	
	_paddle = new Paddle(new Properties("player", SCREEN_WIDTH / 2 - 79, 980, 158, 20));
	_ball = new Ball(new Properties("ball", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 16, 16));
	
	Sound::GetInstance()->LoadMusic("level music", "res\\sfx\\level_music.wav");	
	Sound::GetInstance()->SetMusicVolume(10);
	Sound::GetInstance()->PlayMusic(-1);	
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
		// -2147483648 represents value of std::numeric_limits<float>::infinity()
		if (_bricks[i]->GetHP() <= 0 && _bricks[i]->GetHP() != -2147483648)
		{
			Sound::GetInstance()->PlayChunk(_bricks[i]->_breakSoundID);
			_bricks.erase(_bricks.begin() + i);			
		}	
	}	
}

Level::~Level()
{
	delete _brick;
	delete _paddle;
	delete _ball;	
}

void Level::BounceOfPaddle()
{
	if (CollisionHandler::GetInstance()->CheckCollision(_paddle, _ball)  && _ball->_box.x + _ball->_box.h < _paddle->_box.x + _paddle->_box.w / 2)
	{
		_ball->SetVelocity(1, -1);
	}

	else if (CollisionHandler::GetInstance()->CheckCollision(_paddle, _ball) && _ball->_box.x + _ball->_box.h > _paddle->_box.x + _paddle->_box.w / 2)
	{
		_ball->SetVelocity(-1, -1);
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