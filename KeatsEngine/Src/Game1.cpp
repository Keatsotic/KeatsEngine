#include "Game1.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components/Components.h"
#include "Vector2D.h"


Manager manager;
Map* map;

SDL_Renderer* Game1::renderer = nullptr;

auto& player(manager.AddEntity());

Game1::Game1()
{}

Game1::~Game1()
{}

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
	
	map = new Map();

	player.AddComponent<Transform>(50, 50);
	player.AddComponent<Sprite>("assets/Sprites/Player/s_player_idle.png");
	
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
	manager.Refresh();
	manager.Update();

	player.GetComponent<Transform>().position.Add(Vector2D(5, 0)); //

	if (player.GetComponent<Transform>().position.x > 100)
	{
		player.GetComponent<Sprite>().setTexture("assets/Sprites/Enemy/s_enemy.png");
	}
}
void 
Game1::Render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.Draw();
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