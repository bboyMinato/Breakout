#include "../include/Level.h"

Level::Level(int rowCount, int colCount, int rowSpacing, int colSpacing, BrickTypeList bricklist)
{
	_rowCount = rowCount;
	_colCount = colCount;
	_rowSpacing = rowSpacing;
	_colSpacing = colSpacing;
	_brickType = bricklist;

	for (size_t i = 0; i < _brickType.size(); i++)
	{
		//TextureManager::GetInstance()->LoadTexture(_brickType[i].ID, _brickType[i].source);
		std::cout << _brickType[i].source << std::endl;
	}
		
}

void Level::Render()
{	
	for (size_t i = 0; i < _rowCount; i++)
	{
		for (size_t j = 0; j < _colCount; j++)
		{
			//char brickID = _grid[i][j];

			//std::cout << _grid[i][j] << std::endl;
		}
	}
}

void Level::Update()
{
}
