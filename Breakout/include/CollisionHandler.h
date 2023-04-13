#pragma once
#include "SDL.h"
#include <vector>
#include "Engine.h"
#include "Entity.h"
#include "Brick.h"

class CollisionHandler
{
public:
	static CollisionHandler* GetInstance() { return _instance = (_instance != nullptr) ? _instance : new CollisionHandler(); }
	static bool CheckCollision(SDL_Rect a, SDL_Rect b);	
	bool CheckCollision(Entity* a, Entity* b);
	//static bool CheckCollision(Entity* a, std::vector<Brick*> *bricks);

private:
	CollisionHandler() {}
	
	static CollisionHandler* _instance;
};