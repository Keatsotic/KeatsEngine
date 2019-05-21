#include "Game1.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* player;
GameObject* enemy;

Map* map;
SDL_Renderer* Game1::renderer = nullptr;

Game1::Game1()
{
}
Game1::~Game1()
{
}

void
Game1::Initialize(const char* title, int xPos, int yPos, int width, int height, bool fullScreen)
{
	//check if we are fullscreened
	int flags = 0;
	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//init the window and renderer
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems are initialized" << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window)
		{ 
			std::cout << "Window Created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			std::cout << "Renderer Created" << std::endl;
		}

		isRunning = true;
	}
	
	player = new GameObject("assets/Sprites/Player/s_player_idle.png", 0, 0);
	enemy = new GameObject("assets/Sprites/Enemy/s_enemy.png", 100, 0);
	map = new Map();
}

void 
Game1::HandleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;

	}
}

void 
Game1::Update()
{
	player->Update();
	enemy->Update();
}

void 
Game1::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void 
Game1::Clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}