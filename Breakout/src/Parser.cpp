#include "../include/Parser.h"
LevelParser* LevelParser::_instance = nullptr;

bool LevelParser::Load(std::string id, std::string source)
{
	if (!Parse(id, source))
		return false;

	return false;
}

bool LevelParser::Parse(std::string id, std::string source)
{
	TiXmlDocument xml;
	xml.LoadFile(source);

	if (xml.Error())
	{
		std::cout << "Failed to load XML document: " << source << std::endl;
		return false;
	}

	TiXmlElement* root = xml.RootElement();
	int rowCount, columnCount, rowSpacing, columnSpacing = 0;

	root->Attribute("RowCount", &rowCount);
	root->Attribute("ColumnCount", &columnCount);
	root->Attribute("RowSpacing", &rowSpacing);
	root->Attribute("ColumnSpacing", &columnSpacing);

	BrickTypeList bricktypes;
	
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{				
		if (e->Value() == std::string("BrickTypes"))
		{				
			for (TiXmlElement* v = e->FirstChildElement(); v != nullptr; v = v->NextSiblingElement())
			{				
				std::cout << v->Value() << std::endl;
				bricktypes.push_back(ParseBricks(e));
			}
		}
	}

	LevelMap* levelMap = new LevelMap();
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("Bricks"))
		{
			Level* newLevel = ParseLevel(e, bricktypes, rowCount, columnCount, rowSpacing, columnSpacing);
			levelMap->_mapLevel.push_back(newLevel);
		}
	}

	_levels[id] = levelMap;
	return true;
}

BrickType LevelParser::ParseBricks(TiXmlElement* xmlBricks)
{
	BrickType brickAttribute;	

	TiXmlElement* brickType = xmlBricks->FirstChildElement();

	if (brickType->Attribute("Id"))
		brickAttribute.ID = brickType->Attribute("Id");

	std::cout << brickAttribute.ID << std::endl;
	
	if (brickType->Attribute("Texture"))
		brickAttribute.source = brickType->Attribute("Texture");
	
	if (brickType->Attribute("HitPoints"))
		brickType->Attribute("HitPoints", &brickAttribute.hitPoints);

	return brickAttribute;
}

Level* LevelParser::ParseLevel(TiXmlElement* xmlLevel, BrickTypeList brickTypes, int rowCount, int colCount, int rowSpacing, int colSpacing)
{
	std::string matrix;	

	for (TiXmlElement* e = xmlLevel->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("Bricks"))
		{
			matrix = e->GetText();			
			break;
		}
	}

	std::istringstream iss(matrix);
	std::string id;

	Grid grid(rowCount, std::vector<int>(colCount, 0));

	for (size_t row = 0; row < rowCount; row++)
	{
		for (size_t col = 0; col < colCount; col++)
		{
			std::getline(iss, id, ' ');
			std::stringstream converter(id);
			converter >> grid[row][col];

			if (!iss.good())
				break;
		}
	}

	return (new Level(rowCount, colCount, rowSpacing, colSpacing, brickTypes));
}

LevelParser::~LevelParser()
{
	delete _instance;	
}