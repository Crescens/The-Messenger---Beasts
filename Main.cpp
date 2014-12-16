#include "InitError.h"
#include "cSDL.h"
#include <iostream>
#include <stdio.h>

int main( int argc, char* args[])
{
	try
	{
		SDL sdl(SDL_INIT_VIDEO|SDL_INIT_TIMER);

		return 0;
	}

	catch (const InitError& err)
	{
		std::cerr
			<< "Error while initializing SDL: "
			<< err.what() << std::endl;
	}

	return 1;
}