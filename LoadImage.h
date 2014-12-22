#include <SDL.h>
#include <SDL_image.h>
#include <exception>
#include <string>
#include <iostream>
#include <stdio.h>

//Texture wrapper class
class texture
{
	public:
		//Initializes variables
		texture();

		//Deallocates memory
		~texture();

		//Loads image at specified path
		bool loadFromFile( std::string path, SDL_Renderer *renderer );

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render( int x, int y, SDL_Renderer *renderer );

		//Gets image dimensions
		int getWidth();
		int getHeight();

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;
};

//SDL_Texture *loadImage( std::string filePath, SDL_Renderer *renderer);


