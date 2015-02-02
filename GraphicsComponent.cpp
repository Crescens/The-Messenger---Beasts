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
------------------------------------------------------------------------------------------------------------------------------------------------------*/

GraphicsComponent::~GraphicsComponent()
{
	//Deallocate
	free();
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::render()

Sets the data for the render target destination and dimensions, and then renders it.
------------------------------------------------------------------------------------------------------------------------------------------------------*/

void GraphicsComponent::render(World world, double deltaTime)
{
	mRenderTarget_.x += this.velocity * deltaTime;
	mRenderTarget_.y += GameObject.velocity * deltaTime;
	mRenderTarget_.w = mStrip_.at(mFrame_).w;
	mRenderTarget_.h = mStrip_.at(mFrame_).h;

	SDL_RenderCopy(world.renderer, mTexture_, this->mStrip_.at(&mFrame_), &mRenderTarget_);

	++mFrame_;

	if (mFrame_ >= mMaxFrames_)
	{
		mFrame_ = 0;
	}
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::render()

Adds to render queue.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
void update()
{
	
}
/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::loadFromFile()

This class function loads a file, turns it into a surface, then creates a hardware accelerated texture from the surface. It then frees the surface
and then destroys the temporary texture. It returns true if the returned texture is not null.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
bool GraphicsComponent::loadFromFile(std::string path, SDL_Renderer *renderer)
{
	//Get rid of pre-existing texture
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
		// Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0x80, 0x80));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
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

This class function is almost identical to the constructor. It tests to see if the member variables mTexture_ is empty, and if it is not, it
destroys the texture and resets the mWidth_ and mHeight_ member variables to zero.
------------------------------------------------------------------------------------------------------------------------------------------------------*/

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
------------------------------------------------------------------------------------------------------------------------------------------------------*/

int GraphicsComponent::getWidth()
{
	return mWidth_;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::getHeight()

Returns the height of the full size of the loaded image.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
int GraphicsComponent::getHeight()
{
	return mHeight_;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::getFrame()

Takes the supplied index and returns a SDL_Rect located at mStrip_.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
SDL_Rect GraphicsComponent::getFrame(int index)
{
	return mStrip_.at(index);
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::getFrame()

Sets the maximum number of frames in an animation
------------------------------------------------------------------------------------------------------------------------------------------------------*/
void GraphicsComponent::setMaxFrames(int frames)
{
	mMaxFrames_ = frames;
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------
GraphicsComponent::clipSprite()

Creates a SDL_Rect with the x, y, w, and h dimensions specified. It then appends it to the end of mStrip_, which is a vector of SDL_Rects.
------------------------------------------------------------------------------------------------------------------------------------------------------*/
void GraphicsComponent::clipSprite(int x, int y, int w, int h)
{
	SDL_Rect spriteClip;
	spriteClip.x = x;
	spriteClip.y = y;
	spriteClip.w = w;
	spriteClip.h = h;
	mStrip_.push_back(spriteClip);
}