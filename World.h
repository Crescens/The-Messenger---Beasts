#pragma once

#include <vector>

#include <SDL_image.h>

#include "GameObject.h"

class World
{
public:
	SDL_Window* window;
	SDL_Renderer* renderer;
	const int WIDTH = 640; 
	const int HEIGHT = 480;
	int imgFlags = IMG_INIT_PNG;
	double previousTime;
	double deltaTime;
	const double MS_PER_UPDATE = 16.66666666666667;

	// Adds a GameObject to the updateList
	void addToUpdateList(GameObject &Actor);

	// Adds a GameObject to the renderList
	void addToRenderList(GameObject &Actor);

	// Initializes the window and renderer
	void initialize();

	void gameLoop();

	void cleanUp();



private:
	std::vector<GameObject* > updateList;
	std::vector<GameObject* > renderList;
}