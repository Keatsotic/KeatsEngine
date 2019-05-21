#pragma once
#ifndef GAME_H
#define GAME_H

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>

class Game1
{
public:
	Game1();
	~Game1();

	void Initialize(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);

	void HandleEvents();
	void Update();
	bool Running() { return isRunning; }
	void Render();
	void Clean();

	static SDL_Renderer *renderer;

private:
	bool isRunning;
	SDL_Window *window;
};

#endif
