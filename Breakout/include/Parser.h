#pragma once
#include <map>
#include <string>
#include "tinyxml.h"
#include "Level.h"
#include "Brick.h"
#include "LevelMap.h"

class LevelParser
{
public:
	static LevelParser* GetInstance() { return _instance = (_instance != nullptr) ? _instance : new LevelParser(); }
	bool Load(std::string id, std::string source);
	bool Parse(std::string id, std::string source);
	BrickType ParseBricks(TiXmlElement* bricks);
	Level* ParseLevel(TiXmlElement* xmlLevel, BrickTypeList brickTypes, int rowCount, int colCount, int rowSpacing, int colSpacing);

	inline LevelMap* GetLevel(std::string id)
	{
		return _levels[id];
	}

private:
	LevelParser() {}
	~LevelParser();

	static LevelParser* _instance;	
	std::map<std::string, LevelMap*> _levels;
};

