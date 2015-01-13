#include "LoadImage.h"

Texture::Texture()
{
	//Initialize
	mTexture_ = nullptr;
	mWidth_ = 0;
	mHeight_ = 0;
}

Texture::~Texture()
{
	//Deallocate
	free();
}

bool Texture::loadFromFile( std::string path, SDL_Renderer *renderer )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == nullptr )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0x80, 0x80 ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == nullptr )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth_ = loadedSurface->w;
			mHeight_ = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture_ = newTexture;
	return mTexture_ != nullptr;
}

void Texture::free()
{
	//Free texture if it exists
	if( mTexture_ != nullptr )
	{
		SDL_DestroyTexture( mTexture_ );
		mTexture_ = nullptr;
		mWidth_ = 0;
		mHeight_ = 0;
	}
}

void Texture::render( int x, int y, SDL_Renderer *renderer,  SDL_Rect *clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth_, mHeight_ };

	// Set clip rendering dimensions
	if( clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	// Render to screen
	SDL_RenderCopy( renderer, mTexture_, clip, &renderQuad );
}

int Texture::getWidth()
{
	return mWidth_;
}

int Texture::getHeight()
{
	return mHeight_;
}



/* Depreciated

// This function takes an image and returns an optimized surface
SDL_Texture *loadImage( std::string filePath, SDL_Renderer *renderer)
{
	// Optimized Surface variable
	SDL_Texture *tex = nullptr;

	// Loads image as a surface
	SDL_Surface *loadedSurface = IMG_Load(filePath.c_str());

	// Create texture from surface
	tex = SDL_CreateTextureFromSurface(renderer,loadedSurface);

	// Get rid of old surface
	SDL_FreeSurface(loadedSurface);

	//Return the texture
	return tex;

}
*/