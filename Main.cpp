#include "LoadImage.h"



int main( int argc, char* args[])
{
	// Global Initialization for Window and Blank Surface to NULL
	SDL_Window *window=nullptr;
	SDL_Renderer *renderer=nullptr;
	texture tex;

	// Resolution Variables
	int windowWidth = 640, windowHeight = 480;

	// Create the SDL instance with Video
	SDL_Init(SDL_INIT_VIDEO);
	
	// Create a window that is centered and starts at 640x480 resolution
	window = SDL_CreateWindow( "The Messenger - Beasts",  SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN );
	
	// Create the renderer with 2D acceleration
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

	// Load the image via LoadImage.h/cpp
	tex.loadFromFile("Images/test_image.bmp", renderer);

	// Message Pump
	while (1)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if( e.type == SDL_QUIT)
			{
				break;
			}
		}

		// Empties out the renderer, if anything is present, copies the texture to the renderer, presents the render
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		// Render the texture
		tex.render(0,0,renderer);
		
		// Update renderer
		SDL_RenderPresent(renderer);


	}

	// Properly shutting down each of the SDL moving parts
	//SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}