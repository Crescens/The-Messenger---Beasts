#pragma once

#include "World.h"

int main(int argc, char* args[])
{
	World world;

	world.initialize();

	world.gameLoop();

	world.cleanUp();
}