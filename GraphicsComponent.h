#pragma once

#include <string>

#include <SDL.h>

#include "World.h"
#include "GameObject.h"


class GraphicsComponent
{
public:
	// Initializes variables
	GraphicsComponent();

	// Deallocates memory
	~GraphicsComponent();

	// Deallocates texture
	void free();

	// Renders the GraphicsComponent
	void render(World world, double deltaTime);

	// Adds this GraphicsComponent to the render list
	void update();

	//Loads image at specified path, sets mWidth_ and mHeight_ automatically
	bool loadFromFile(std::string path, World &world);

	// Creates a rectangle used to clip a sprite from a sprite sheet and adds it to the vector mStrip_
	void clipSprite(int x, int y, int w, int h);

	// Returns the frame at the supplied index
	SDL_Rect getFrame(int index);

	// Sets the maximum number of frames in an animation
	void setMaxFrames(int frames);

	// Gets image dimensions
	int getWidth();
	int getHeight();

private:
	// The actual hardware texture
	SDL_Texture* mTexture_;

	// The last frame used
	int mFrame_;

	// Total number of frames in an animation cycle
	int mMaxFrames_;

	// Image dimensions; This is of the whole image and does not get the size of clipped sprites.
	int mWidth_;
	int mHeight_;

	// Rectangle that defines the destination and dimensions of what is to be rendered
	SDL_Rect mRenderTarget_;

	// A collection of rectangles that hold the location and dimension information about where to clip on the loaded sprite sheet
	std::vector<SDL_Rect> mStrip_;

	/* These are to be used later, after testing the bast functionality. Might be worth while to find a way to dynamically generate them.
	std::vector<SDL_Rect> mWalkingUpStrip_;
	std::vector<SDL_Rect> mWalkingRightStrip_;
	std::vector<SDL_Rect> mWalkingDownStrip_;
	std::vector<SDL_Rect> mWalkingLeftStrip_;
	std::vector<SDL_Rect> mAttackingStrip_;
	std::vector<SDL_Rect> mCastingStrip_;
	*/
};