#include "GraphicsComponent.h"

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::GraphicsComponent()

Constructor initializes everything to zeros or nulls.
------------------------------------------------------------------------------------------------------------------------------------------------------*/

GraphicsComponent::GraphicsComponent()
{
	//Initialize
	mTexture_ = nullptr;
	mWidth_ = 0;
	mHeight_ = 0;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::~GraphicsComponent()

Destructor calls free().
\*----------------------------------------------------------------------------------------------------------------------------------------------------*/

GraphicsComponent::~GraphicsComponent()
{
	//Deallocate
	free();
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::update()

Sets the data for the render target destination and dimensions, and then sends it into the rendering queue.
\*----------------------------------------------------------------------------------------------------------------------------------------------------*/

void GraphicsComponent::update(GameObject &Object)
{
	renderTarget_.x = Object.x;
	renderTarget_.y = Object.y;
	renderTarget_.w = strip_.at(0).w;
	renderTarget_.h = strip_.at(0).h;

	//addToRenderList(*This);
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::loadFromFile()

This class function loads a file, turns it into a surface, then creates a hardware accelerated texture from the surface.It then frees the surface
and then destroys the temporary texture.It returns true if the returned texture is not null.
\*----------------------------------------------------------------------------------------------------------------------------------------------------*/
bool GraphicsComponent::loadFromFile(std::string path, World &world)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0x80, 0x80));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(world.renderer, loadedSurface);
		if (newTexture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth_ = loadedSurface->w;
			mHeight_ = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture_ = newTexture;
	SDL_DestroyTexture(newTexture);
	return mTexture_ != nullptr;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::free()

This class function is almost identical to the contstructor.It tests to see if the member variables mTexture_ is empty, and if it is not, it
destroys the texture and resets the mWidth_ and mHeight_ member variables to zero.
\*----------------------------------------------------------------------------------------------------------------------------------------------------*/

void GraphicsComponent::free()
{
	//Free texture if it exists
	if (mTexture_ != nullptr)
	{
		SDL_DestroyTexture(mTexture_);
		mTexture_ = nullptr;
		mWidth_ = 0;
		mHeight_ = 0;
	}
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::getWidth()

Returns the width of the full size of the loaded image.
\*----------------------------------------------------------------------------------------------------------------------------------------------------*/

int GraphicsComponent::getWidth()
{
	return mWidth_;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::getHeight()

Returns the height of the full size of the loaded image.
\*----------------------------------------------------------------------------------------------------------------------------------------------------*/
int GraphicsComponent::getHeight()
{
	return mHeight_;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::getFrame()

Takes the supplied index and returns a SDL_Rect located at strip_.
\*----------------------------------------------------------------------------------------------------------------------------------------------------*/
SDL_Rect GraphicsComponent::getFrame(int index)
{
	return strip_.at(index);
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::getStrip()

Returns strip_.
\*----------------------------------------------------------------------------------------------------------------------------------------------------*/
std::vector<SDL_Rect> GraphicsComponent::getStrip()
{
	return strip_;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::clipSprite()

Creates a SDL_Rect with the x, y, w, and h dimensions specified.It then appends it to the end of strip_, which is a vector of SDL_Rects.
\*----------------------------------------------------------------------------------------------------------------------------------------------------*/
void GraphicsComponent::clipSprite(int x, int y, int w, int h)
{
	SDL_Rect spriteClip;
	spriteClip.x = x;
	spriteClip.y = y;
	spriteClip.w = w;
	spriteClip.h = h;
	strip_.push_back(spriteClip);
}