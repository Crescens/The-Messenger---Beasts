#include "Initialize.h"

void initialize(SDL_Window* window, SDL_Renderer *renderer)
{
	// Resolution Variables
	int windowWidth = 640, windowHeight = 480;

	// Create the SDL instance with Video
	SDL_Init(SDL_INIT_VIDEO);

	// Create a window that is centered and starts at 640x480 resolution
	window = SDL_CreateWindow("The Messenger - Beasts", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN);

	// Create the renderer with 2D acceleration
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
}