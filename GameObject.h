#pragma once

#include "GraphicsComponent.h"
#include "InputComponent.h"

class GameObject
{
public:
	int x, y;

	virtual void update(World &world);

private:
	// Components added as necessary
	InputComponent input_;
	GraphicsComponent graphics_;
};
