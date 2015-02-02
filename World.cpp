#include "World.h"

/*------------------------------------------------------------------------------------------------------------------------------------------------------
World::World()

Makes sure the window and renderer pointers are empty and initializes previousTime and deltaTime to be essentially empty.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
World::World()
{
	window = nullptr;
	renderer = nullptr;
	previousTime = 0.0;
	deltaTime = 0.0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
World::~World()

Calls the cleanUp() function, which safely shuts down the renderer, window, and SDL.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
World::~World()
{
	cleanUp();
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
World::addToUpdateList()

This adds an address of a GameObject to a vector of pointers to GameObjects. This specifically adds the address to the end.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
void World::addToUpdateList(GameObject &Actor)
{
	updateList.push_back(&Actor);
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
World::addToRenderList()

This adds an address of a GameObject to a vector of pointers to GameObjects. This specifically adds the address to the end.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
void World::addToRenderList(GameObject &Actor)
{
	renderList.push_back(&Actor);
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
World::initialize()

This function sets up SDL with SDL_INIT_VIDEO, puts a SDL_Window in the window variable, puts a SDL_Renderer in the render variable, and adds PNG to
the usable image format for textures.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
void World::initialize()
{

	// Create the SDL instance with Video
	if (!SDL_Init(SDL_INIT_VIDEO))
	{
		printf("SDL_Init could not initialize! SDL_Init Error: %s\n", SDL_GetError());
	}

	// Create a window that is centered and starts at 640x480 resolution
	window = SDL_CreateWindow("The Messenger - Beasts", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);

	// Create the renderer with 2D acceleration
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
World::gameLoop()

The base game loop. It initially sets a time variable then sinks into the main loop. previousTime and currentTime are used to create elapsedTime, which
is then added to the deltaTime variable. deltaTime is then used to test to see if update() should be run. If deltaTime is greater than or equal to 16.7
(rounded) milliseconds, update each GameObject and subtract 16.7 from delta time. This prevents the game from updating faster than 60 fps, as 16.7 is
equal to 60 fps, but it also lets the game catch up if the game runs slower than 60fps.

To sync both update() and render(), a normalized value is passed to render between 0.0f and 1.0f. This is then multiplied by any velocity to achieve the
distances moved and so on.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
void World::gameLoop()
{
	// Setup time variables
	previousTime = SDL_GetTicks();

	// Loop control
	bool quit = false;

	// Event variable
	SDL_Event e;

	// Primary loop that starts the time count
	while (quit == false)
	{
		double currentTime = SDL_GetTicks();
		double elapsedTime = currentTime - previousTime;
		previousTime = currentTime;
		deltaTime += elapsedTime;

		// processInput(); // PLACEHOLDER

		// Sub loop that contains the exit event code
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			// Sub-sub loop that updates the 
			while (deltaTime >= MS_PER_UPDATE) // If deltaTime is less than 16.7 (rounded up), this won't run. This prevents it from going faster than 60fps.
			{
				for (auto i : updateList)
				{
					i->update();
				}

				deltaTime -= MS_PER_UPDATE; // If the machine is slow, this allows the update to catch up,
			}

			// Empties out the renderer, if anything is present, copies the texture to the renderer, presents the render
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(renderer);

			// BEGIN TEXTURE ASSIGNMENT AND CLIP


			// END TEXTURE ASSIGNMENT AND CLIP

			// render from the list
			for (auto i : renderList)
			{
				i->graphics_.render(deltaTime / MS_PER_UPDATE);
			}

			// Update renderer
			SDL_RenderPresent(renderer);
		}
	}

}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
World::cleanUp()

This simply cleans up the renderer, window, and shuts down SDL on exit.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
void World::cleanUp()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}