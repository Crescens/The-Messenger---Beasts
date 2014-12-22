#include "LoadImage.h"

texture::texture()
{
	//Initialize
	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;
}

texture::~texture()
{
	//Deallocate
	free();
}

bool texture::loadFromFile( std::string path, SDL_Renderer *renderer )
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
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
		if( newTexture == nullptr )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != nullptr;
}

void texture::free()
{
	//Free texture if it exists
	if( mTexture != nullptr )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = nullptr;
		mWidth = 0;
		mHeight = 0;
	}
}

void texture::render( int x, int y, SDL_Renderer *renderer )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };
	SDL_RenderCopy( renderer, mTexture, NULL, &renderQuad );
}

int texture::getWidth()
{
	return mWidth;
}

int texture::getHeight()
{
	return mHeight;
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