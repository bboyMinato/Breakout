#include "../include/Engine.h"
#include "../include/TextureManager.h"
#include "../include/Paddle.h"
#include "../include/Input.h"
#include "../include/Ball.h"
#include "../include/CollisionHandler.h"
#include "../include/Parser.h"
#include "../include/Level.h"

Engine* Engine::_instance = nullptr;
Paddle* player = nullptr;
Ball* ball = nullptr;

void Engine::Init()
{
	_isRunning = true;

	if (SDL_Init(SDL_INIT_VIDEO || SDL_INIT_AUDIO) > 0 )
		std::cout << "SDL_Init has failed: " << SDL_GetError() << std::endl;

	if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)))
		std::cout << "IMG_Init has failed: " << SDL_GetError() << std::endl;

	_window = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (_window == nullptr)
		std::cout << "Window has failed to initialize! Error: " << SDL_GetError() << std::endl;

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (_renderer == nullptr)
		std::cout << "Renderer has failed to initialize! Error: " << SDL_GetError() << std::endl;

    TextureManager::GetInstance()->LoadTexture("background", "res\\img\\space_background.png");
    TextureManager::GetInstance()->LoadTexture("player", "res\\img\\paddle.png");
	TextureManager::GetInstance()->LoadTexture("ball", "res\\img\\ball_sprite.png");

	LevelParser::GetInstance()->Load("Level", "res/Level.xml");

	_levelMap = LevelParser::GetInstance()->GetLevel("Level");   
}

void Engine::Clean()
{
	TextureManager::GetInstance()->Clean();

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
}

void Engine::Quit()
{
}

void Engine::Render()
{
    SDL_SetRenderDrawColor(_renderer, 200, 0, 100, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(_renderer);

    TextureManager::GetInstance()->Draw("background", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);   	

	_levelMap->Render();

    SDL_RenderPresent(_renderer);
}

void Engine::Update()
{
	_levelMap->Update();
}

void Engine::Events()
{
	Input::GetInstance()->HandleEvents();
}
