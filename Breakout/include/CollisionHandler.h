#pragma once
#include "SDL.h"
#include <vector>
#include "Engine.h"
#include "Entity.h"

class CollisionHandler
{
public:
	static CollisionHandler* GetInstance() { return _instance = (_instance != nullptr) ? _instance : new CollisionHandler(); }
	bool CheckCollision(SDL_Rect a, SDL_Rect b);	
	static bool CheckCollision(Entity* a, Entity* b);

private:
	CollisionHandler() {}
	
	static CollisionHandler* _instance;
};