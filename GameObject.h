#pragma once

#include "GraphicsComponent.h"
#include "InputComponent.h"

class GameObject
{
public:
	int x, y;

	virtual void update();

	// Components added as necessary
	InputComponent input_;
	GraphicsComponent graphics_;
};
