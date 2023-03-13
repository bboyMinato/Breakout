#pragma once
#include <map>
#include <string>
#include "tinyxml.h"
#include "Level.h"
#include "Brick.h"

class LevelParser
{
public:
	static LevelParser* GetInstance() { return _instance = (_instance != nullptr) ? _instance : new LevelParser(); }
	bool Load(std::string id, std::string source);
	bool Parse(std::string id, std::string source);
	BrickType ParseBricks(TiXmlElement* bricks);

private:
	LevelParser() {}
	~LevelParser();

	static LevelParser* _instance;	
};

