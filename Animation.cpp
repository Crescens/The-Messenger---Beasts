#include "Animation.h"



Animation::Animation()
{
	timing_ = 0;
}


Animation::~Animation()
{
	this->free();
}

// Allows you to destroy the last texture loaded in the strip
void Animation::rollbackStrip()
{
	strip_.pop_back();
}

// Returns the rectangle to clip during rendering
SDL_Rect Animation::getFrame(int index)
{
	return strip_.at(index);
}

// Returns the unsigned int stored in timing_
Uint32 Animation::getTiming()
{
	return timing_;
}

// Allows you to set the value in timing_; Should be used with SDL_GetTicks
void Animation::setTiming(Uint32 timing)
{
	timing_ = timing;
}

void Animation::setSpriteSheet(std::string filepath, SDL_Renderer *renderer)
{
	if(!(spriteSheet_.loadFromFile(filepath, renderer)))
	{
		printf("Unable to create texture from %s! SDL Error: %s\n", filepath.c_str(), SDL_GetError());
	}
}

void Animation::clipSprite(int x, int y, int w, int h)
{
	SDL_Rect spriteClip;
	spriteClip.x = x;
	spriteClip.y = y;
	spriteClip.w = w;
	spriteClip.h = h;
	strip_.push_back(spriteClip);
}
