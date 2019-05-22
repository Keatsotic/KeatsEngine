#pragma once
#include "Components.h"
#include "../Vector2D.h"

struct Transform : public Component
{
	Vector2D position;
	int scale = 4;

	Transform()
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}

	Transform(float x, float y)
	{
		position, x = x;
		position.y = y;
	}

	void Update() override
	{

	}


};