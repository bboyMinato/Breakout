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
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e->NextSiblingElement())
	{
		if (e->Value() == std::string("BrickType"))
		{
			bricktypes.push_back(ParseBricks(e));
		}
	}

	return true;
}

BrickType LevelParser::ParseBricks(TiXmlElement* xmlBricks)
{
	BrickType brickAttribute;

	if (xmlBricks->Attribute("Id"))
		brickAttribute.ID = xmlBricks->Attribute("Id");

	if (xmlBricks->Attribute("Texture"))
		brickAttribute.source = xmlBricks->Attribute("Texture");

	if (xmlBricks->Attribute("HitPoints"))
		xmlBricks->Attribute("HitPoints", &brickAttribute.hitPoints);

	return brickAttribute;
}

LevelParser::~LevelParser()
{
	delete _instance;
}