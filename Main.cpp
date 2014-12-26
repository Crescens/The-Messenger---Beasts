#include "LoadImage.h"
#include "Actor.h"


int main( int argc, char* args[])
{
	// Global Initialization for Window and Blank Surface to NULL
	SDL_Window *window=nullptr;
	SDL_Renderer *renderer=nullptr;
	Texture backgroundTex;
	Texture actorTex;

	// Resolution Variables
	int windowWidth = 640, windowHeight = 480;

	// Create the SDL instance with Video
	SDL_Init(SDL_INIT_VIDEO);
	
	// Create a window that is centered and starts at 640x480 resolution
	window = SDL_CreateWindow( "The Messenger - Beasts",  SDL_WINDOWPOS_CENTERED,  SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN );
	
	// Create the renderer with 2D acceleration
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if( !( IMG_Init( imgFlags ) & imgFlags ) )
		{
			printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
		}

	// Load the background image
	backgroundTex.loadFromFile("Images/Background_Test_1.png", renderer);
	actorTex.loadFromFile("Images/Test_Sprite_Sheet.png", renderer);

	// Clip out single Test sprite and set a constant animation frame speed
	SDL_Rect spriteClip[4];

	// First Clip - Left Foot
	spriteClip[0].x = 36;
	spriteClip[0].y = 65;
	spriteClip[0].w = 16;
	spriteClip[0].h = 24;

	// Second Clip - Right Foot
	spriteClip[1].x = 71;
	spriteClip[1].y = 66;
	spriteClip[1].w = 16;
	spriteClip[1].h = 24;

	// Third Clip - Left Foot
	spriteClip[2].x = 36;
	spriteClip[2].y = 65;
	spriteClip[2].w = 16;
	spriteClip[2].h = 24;

	// Fourth Clip - Right Foot
	spriteClip[3].x = 71;
	spriteClip[3].y = 66;
	spriteClip[3].w = 16;
	spriteClip[3].h = 24;

	const int WALKING_ANIMATION_FRAMES = 4;

	// Main Loop
	while (1)
	{
		// Animation control
		int frame = 0;

		// Event object
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

		/* Creates a viewport
		SDL_Rect viewport;
		viewport.x = 0;
		viewport.y = 0;
		viewport.w = windowWidth / 2;
		viewport.h = windowHeight / 2;
		SDL_RenderSetViewport( renderer, &viewport );
		*/

		// Render the background texture
		backgroundTex.render(0,0,renderer);

		// Render the actor texture with a delay
		SDL_Rect* currentClip = &spriteClip[ frame / 4 ];
		actorTex.render(400, 135,renderer, currentClip);
		
		// Update renderer
		SDL_RenderPresent(renderer);

		//Go to next frame
		++frame;

		//Cycle animation
		if( frame / 4 >= WALKING_ANIMATION_FRAMES )
			{
				frame = 0;
			}

	}

	// Properly shutting down each of the SDL moving parts
	backgroundTex.free();
	actorTex.free();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}