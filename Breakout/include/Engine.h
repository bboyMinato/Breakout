#pragma once
#include <iostream>
#include <vector>
#include "SDL.h"
#include "Entity.h"
#include "LevelMap.h"

constexpr int SCREEN_WIDTH = 1920;
constexpr int SCREEN_HEIGHT = 1024;

class Engine
{
public:
	static Engine* GetInstance() { return _instance = (_instance != nullptr) ? _instance : new Engine(); }
	SDL_Renderer* GetRenderer() { return _renderer; }
	inline bool IsRunning() { return _isRunning; }

	void Init();
	void Clean();
	void Quit();

	void Render();
	void Update();
	void Events();

private:
	Engine() {}
	void BounceOfPaddle();

	static Engine* _instance;
	bool _isRunning = false;
	std::vector<Entity*> _entityMap;

	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;
	LevelMap* _levelMap = nullptr;
};