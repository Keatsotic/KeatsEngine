// KeatsEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Game1.h"

Game1 *game1 = nullptr;

int main(int argc, char *args[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	game1 = new Game1();

	game1->Initialize("KeatsEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, false);

	while (game1->Running())
	{

		frameStart = SDL_GetTicks();

		game1->HandleEvents();
		game1->Update();
		game1->Render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game1->Clean();
	delete game1;

	return 0;
}

