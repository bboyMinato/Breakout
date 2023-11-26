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
		for (TiXmlElement* v = e->FirstChildElement(); v != nullptr; v = v->NextSiblingElement())
		{			
			bricktypes.push_back(ParseBricks(v));
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

	brickAttribute.ID = xmlBricks->Attribute("Id");

	brickAttribute.texture = xmlBricks->Attribute("Texture");

	xmlBricks->Attribute("HitPoints", &brickAttribute.hitPoints);

	if (xmlBricks->Attribute("HitSound"))
		brickAttribute.hitSound = xmlBricks->Attribute("HitSound");		
	
	if (xmlBricks->Attribute("BreakSound"))
		brickAttribute.breakSound = xmlBricks->Attribute("BreakSound");	

	xmlBricks->Attribute("BreakScore", &brickAttribute.breakScore);		

	return brickAttribute;
}

Level* LevelParser::ParseLevel(TiXmlElement* xmlLevel, BrickTypeList brickTypes, int rowCount, int colCount, int rowSpacing, int colSpacing)
{	
	std::string matrix;		

	if (xmlLevel->Value() == std::string("Bricks"))
		matrix = xmlLevel->GetText();

	std::istringstream iss(matrix);
	std::string id;
		
	Board board(rowCount, std::vector<std::string>(colCount));

	for (size_t row = 0; row < rowCount; row++)
	{
		for (size_t col = 0; col < colCount; col++)
		{
			std::getline(iss, id, ' ');
			std::stringstream converter(id);
			converter >> board[row][col];	
						
			if (!iss.good())
				break;
		}
	}
	
	return (new Level(rowCount, colCount, rowSpacing, colSpacing, brickTypes, board));
}

LevelParser::~LevelParser()
{
	delete _instance;	
}