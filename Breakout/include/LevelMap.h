#pragma once
#include <vector>
#include "Level.h"

class LevelMap
{
public:
	void Render()
	{
		for (size_t i = 0; i < _mapLevel.size(); i++)
			_mapLevel[i]->Render();
	}

	void Update()
	{
		for (size_t i = 0; i < _mapLevel.size(); i++)
			_mapLevel[i]->Update();
	}

	std::vector<Level*> GetLevel() { return _mapLevel; }

protected:
	friend class LevelParser;
	std::vector<Level*> _mapLevel;
};