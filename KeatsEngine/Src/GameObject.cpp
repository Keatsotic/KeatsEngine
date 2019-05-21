#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xPos = x;
	//heres a change!
	yPos = y;
}

void
GameObject::Update()
{
	xPos++;
	yPos++;

	srcRect.h = 32;
	srcRect.w = 24;
	srcRect.x = 0;
	srcRect.y = 0;	

	destRect.h = srcRect.h * scale;
	destRect.w = srcRect.w * scale;
	destRect.x = xPos;
	destRect.y = yPos;
}

void  
GameObject::Render()
{
	SDL_RenderCopy(Game1::renderer, objTexture, &srcRect, &destRect);
}

GameObject::~GameObject()
{
}
