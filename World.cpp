#include "World.h"
#include "GraphicsComponent.h"

World::World()
{
	window = nullptr;
	renderer = nullptr;
	previousTime = 0.0;
	deltaTime = 0.0;
}

World::~World()
{
	cleanUp();
}

void World::addToUpdateList(GameObject &Actor)
{
	updateList.push_back(&Actor);
}

void World::addToRenderList(GameObject &Actor)
{
	renderList.push_back(&Actor);
}

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

void World::render(double normalizedDelta)
{
	for (auto i : renderList)
	{
		if (i.update->strip_.at(0) != NULL)
		{
			SDL_RenderCopy(renderer, i->graphics_->mTexture_, i->graphics_->strip_.at(0), renderList(i))
		}
		else return;
	}
}

void World::gameLoop()
{
	// Setup time variables
	previousTime = SDL_GetTicks();

	while (true)
	{
		double currentTime = SDL_GetTicks();
		double elapsedTime = currentTime - previousTime;
		previousTime = currentTime;
		deltaTime += elapsedTime;

		//processInput();

		while (deltaTime >= MS_PER_UPDATE)
		{
			for (auto i : updateList)
			{
				i.->.update();
			}
			deltaTime -= MS_PER_UPDATE;
		}

		render(deltaTime / 16.MS_PER_UPDATE);
	}

}

void World::cleanUp()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}