#pragma once
#include "Components.h"
#include "SDL.h"

class Sprite : public Component
{
public:
	Sprite() = default;
	Sprite(const char* path)
	{
		setTexture(path);
	}

	void setTexture(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	void Initialize() override
	{
		transform = &entity->GetComponent<Transform>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = 24;
		srcRect.h = 32;

		destRect.w = 24 * transform->scale;
		destRect.h = 32 * transform->scale;

	}

	void Update() override
	{
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;
	}

	void Draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect); 
	}

private:
	Transform *transform;
	SDL_Texture *texture;

	SDL_Rect srcRect, destRect;
};