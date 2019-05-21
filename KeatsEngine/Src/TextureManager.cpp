#include "TextureManager.h"


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

SDL_Texture* 
TextureManager::LoadTexture(const char* filename)
{
	SDL_Surface* tempSurface = IMG_Load(filename);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game1::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return texture;
}

void
TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game1::renderer, texture, &src, &dest);
}

