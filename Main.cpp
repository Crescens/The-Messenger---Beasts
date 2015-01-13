#pragma once

#include <SDL_timer.h>

#include "Actor.h"


int main( int argc, char* args[])
{

	// BEGIN INITIALIZATION

	const int MAX_FPS = 60;
	
	// Global Initialization for Window and Blank Surface to NULL
	SDL_Window *window=nullptr;
	SDL_Renderer *renderer=nullptr;

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

	// Initialize Background Texture and Actor
	Texture backgroundTex;
	Actor actorCeles;

	// END INITIALIZATION

	// Load the background image into the texture object
	backgroundTex.loadFromFile("Images/Background_Test_1.png", renderer);

	// Load the sprite sheet into the Celes object
	actorCeles.loadFromFile("Images/Test_Sprite_Sheet_2.png", renderer);

	// Clip out the various walking animations into their own vectors

	// Walking Up - Standing Feet Together - Staring Frame
	actorCeles.moveUp.clipSprite(26, 10, 16, 24);
	// Walking Up - Right Foot
	actorCeles.moveUp.clipSprite(10, 10, 16, 24);
	// Walking Up - Standing Feet Together
	actorCeles.moveUp.clipSprite(26, 10, 16, 24);
	// Walking Up - Left Foot
	actorCeles.moveUp.clipSprite(42, 10, 16, 24);

	// Walking Right - Standing Feet Together - Starting Frame
	actorCeles.moveRight.clipSprite(26, 61, 16, 24);
	// Walking Right - Right Foot
	actorCeles.moveRight.clipSprite(10, 61, 16, 24);
	// Walking Right - Standing Feet Together
	actorCeles.moveRight.clipSprite(26, 61, 16, 24);
	// Walking Right - Left Foot
	actorCeles.moveRight.clipSprite(42, 61, 16, 24);


	// Walking Down - Standing Feet Together - Starting Frame
	actorCeles.moveDown.clipSprite(26, 86, 16, 24);
	// Walking Down - Right Foot
	actorCeles.moveDown.clipSprite(10, 86, 16, 24);
	// Walking Down - Standing Feet Together
	actorCeles.moveDown.clipSprite(26, 86, 16, 24);
	// Walking Down - Left Foot
	actorCeles.moveDown.clipSprite(42, 86, 16, 24);

	// Walking Left - Standing Feet Together - Starting Frame
	actorCeles.moveLeft.clipSprite(26, 36, 16, 24);
	// Walking Left - Left Foot
	actorCeles.moveLeft.clipSprite(10, 36, 16, 24);
	// Walking Left - Standing Feet Together
	actorCeles.moveLeft.clipSprite(26, 36, 16, 24);
	// Walking Left - Right Foot
	actorCeles.moveLeft.clipSprite(42, 36, 16, 24);

	// Animation control
	int frame = 0;

	// Loop Control, Message Pump Init, and Time Control
	bool quit = false;
	SDL_Event e;

	// Sets up animation cycle
	int animationTest = 0;

	// Frame Cap Init
	Uint32 frameStart = 0;

	// Main Loop
	while (!quit)
	{
		// Last key pressed Flag
		std::string actionFlag = "reset";

		// Creates the current clip variable and checks to see if it's empty.
		SDL_Rect currentClip = actorCeles.moveUp.getFrame(0);

		// Handle all the events in the queue
		while (SDL_PollEvent(&e) != 0)
		{

			Uint32 deltaTime = SDL_GetTicks() - frameStart;

			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			else if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_W)
			{
				if (actionFlag == "Up" && (SDL_GetTicks() - actorCeles.moveUp.getTiming()) > 75)
				{
					animationTest++;
					actorCeles.moveUp.setTiming(SDL_GetTicks());
				}
				else
				{
					animationTest = 0;
				}
				currentClip = actorCeles.moveUp.getFrame(animationTest);
				actorCeles.subY(1 * deltaTime);

				actionFlag = "Up";
			}

			else if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_S)
			{
				if (actionFlag == "Up" && (SDL_GetTicks() - actorCeles.moveDown.getTiming()) > 75)
				{
					animationTest++;
					actorCeles.moveDown.setTiming(SDL_GetTicks());
				}
				else
				{
					animationTest = 0;
				}
				currentClip = actorCeles.moveDown.getFrame(animationTest);
				actorCeles.addY(1 * deltaTime);

				actionFlag = "Up";
			}

			if (animationTest == 3)
			{
				animationTest = 0;
				actionFlag = "reset";
			}

			if (1000 / MAX_FPS > SDL_GetTicks() - frameStart)
			{
				SDL_Delay((1000 / MAX_FPS) - (SDL_GetTicks() - frameStart));
			}

		}

			// Empties out the renderer, if anything is present, copies the texture to the renderer, presents the render
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer);

			// Render the background texture
			backgroundTex.render(0, 0, renderer);

			// Render the actor texture
			actorCeles.render(actorCeles.getX(), actorCeles.getY(), renderer, &currentClip);

			// Update renderer
			SDL_RenderPresent(renderer);

			
		
		
			
	}
		
	// Properly shutting down each of the SDL moving parts
	backgroundTex.free();
	actorCeles.free();
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}