#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xPos = x;
	yPos = y;
}

GameObject::~GameObject()
{}


void
GameObject::Update()
{
	xPos++;
	yPos++;

	srcRect.h = 32; //need to make this more flexible -- should base size off sprite or something
	srcRect.w = 24; //need to make this more flexible -- should base size off sprite or something
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