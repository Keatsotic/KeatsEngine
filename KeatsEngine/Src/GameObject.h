#pragma once
#include "Game1.h"

class GameObject
{
public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void Update();
	void Render();

private:
	int xPos;
	int yPos;
	int scale = 4;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
};

