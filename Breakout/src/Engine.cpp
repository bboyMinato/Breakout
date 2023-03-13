#include "../include/Engine.h"
#include "../include/TextureManager.h"
#include "../include/Paddle.h"
#include "../include/Input.h"
#include "../include/Ball.h"
#include "../include/CollisionHandler.h"

Engine* Engine::_instance = nullptr;
Paddle* player = nullptr;
Ball* ball = nullptr;

void Engine::Init()
{
	_isRunning = true;

	if (SDL_Init(SDL_INIT_VIDEO) > 0)
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

    player = new Paddle(new Properties("player", 433, 980, 158, 20));
	_entityMap.push_back(player);

	ball = new Ball(new Properties("ball", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 16, 16 ));
	_entityMap.push_back(ball);
}

void Engine::Clean()
{
	TextureManager::GetInstance()->Clean();

    delete player;
	delete ball;

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
    player->Draw();
	ball->Draw();

    SDL_RenderPresent(_renderer);
}

void Engine::Update()
{
	player->Update();	
	ball->Update();		

	BounceOfPaddle();
}

void Engine::Events()
{
	Input::GetInstance()->HandleEvents();
}

void Engine::BounceOfPaddle()
{
	if (CollisionHandler::CheckCollision(player, ball) && ball->_box.x < player->_box.x + player->_box.w / 2)
	{
		ball->SetVelocity(-1, -1);
	}

	else if (CollisionHandler::CheckCollision(player, ball) && ball->_box.x > player->_box.x + player->_box.w / 2)
	{
		ball->SetVelocity(1, -1);
	}
}