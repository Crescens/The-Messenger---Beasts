#pragma once

#include <string>

#include <SDL.h>

#include "World.h"


class GraphicsComponent
{
public:
	// Initializes variables
	GraphicsComponent();

	// Deallocates memory
	~GraphicsComponent();

	// Deallocates texture
	void free();

	// Adds this GraphicsComponent to the render list
	void update(GameObject &Object);

	//Loads image at specified path, sets mWidth_ and mHeight_ automatically
	bool loadFromFile(std::string path, World &world);

	// Creates a rectangle used to clip a sprite from a sprite sheet and adds it to the vector strip_
	void clipSprite(int x, int y, int w, int h);

	// Returns the frame at the supplied index
	SDL_Rect getFrame(int index);

	// Returns strip_
	std::vector<SDL_Rect> getStrip();

	// Gets image dimensions
	int getWidth();
	int getHeight();

private:
	// The actual hardware texture
	SDL_Texture* mTexture_;

	// Image dimensions; This is of the whole image and does not get the size of clipped sprites.
	int mWidth_;
	int mHeight_;

	// Rectangle that defines the destination and dimensions of what is to be rendered
	SDL_Rect renderTarget_;

	// A collection of rectangles that hold the location and dimension information about where to clip on the loaded sprite sheet
	std::vector<SDL_Rect> strip_;
};