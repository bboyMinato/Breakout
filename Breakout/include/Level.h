#pragma once
#include <vector>
#include "TextureManager.h"
#include "Brick.h"

class Level
{
public:
	Level(int rowCount, int colCount, int rowSpacing, int colSpacing, BrickTypeList bricklist, Board grid);
	Level() {}
	void Render();
	void Update();
	static void Clean();	

	std::vector<Brick*> _bricks;
private:
	~Level();
	int _rowCount = 0;
	int _colCount = 0;
	int _rowSpacing = 0;
	int _colSpacing = 0;	
	BrickTypeList _brickType;	
	Board _board;		
};

