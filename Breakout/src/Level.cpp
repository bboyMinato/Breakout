#include "../include/Level.h"
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
	{
		TextureManager::GetInstance()->LoadTexture(_brickType[i].ID, _brickType[i].texture);	
	}	

	for (size_t i = 0; i < _rowCount; i++)
	{
		for (size_t j = 0; j < _colCount; j++)
		{
			std::string brickID = _board[i][j];

			for (auto k = 0; k < _brickType.size()-1; k++)
			{
				if (brickID == "S")
				{
					brick = new Brick(&_brickType[k]);
					brick->SetPositionX(colSpacing + j * brick->GetWidth());
					brick->SetPositionY(rowSpacing + i * brick->GetHeight());							
					_bricks.push_back(brick);
					break;
				}

				else if (brickID == "M")
				{
					brick = new Brick(&_brickType[k+1]);
					brick->SetPositionX(colSpacing + j * brick->GetWidth());
					brick->SetPositionY(rowSpacing + i * brick->GetHeight());					
					_bricks.push_back(brick);
					break;
				}

				else if (brickID == "H")
				{
					brick = new Brick(&_brickType[k+2]);
					brick->SetPositionX(colSpacing + j * brick->GetWidth());
					brick->SetPositionY(rowSpacing + i * brick->GetHeight());					
					_bricks.push_back(brick);
					break;
				}

				else if (brickID == "I")
				{
					brick = new Brick(&_brickType[k+3]);
					brick->SetPositionX(colSpacing + j * brick->GetWidth());
					brick->SetPositionY(rowSpacing + i * brick->GetHeight());					
					_bricks.push_back(brick);
					break;
				}
			}				
		}	
	}
}

void Level::Render()
{	
	for (auto i = 0; i < _bricks.size(); i++)
	{
		_bricks[i]->Render();
	}
}

void Level::Update()
{
}

void Level::Clean()
{	
}

Level::~Level()
{
	delete brick;
}

void Clean()
{
}
