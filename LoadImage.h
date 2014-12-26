#pragma once

#include <exception>
#include <string>
#include <iostream>
#include <stdio.h>

#include <SDL.h>
#include <SDL_image.h>


//Texture wrapper class
class Texture
{
	public:
		//Initializes variables
		Texture();

		//Deallocates memory
		~Texture();

		//Loads image at specified path
		bool loadFromFile( std::string path, SDL_Renderer *renderer );

		//Deallocates texture
		void free();

		//Renders texture at given point
		void Texture::render( int x, int y, SDL_Renderer *renderer,  SDL_Rect *clip = nullptr);

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture_;

		//Image dimensions
		int mWidth_;
		int mHeight_;
};

//SDL_Texture *loadImage( std::string filePath, SDL_Renderer *renderer);


