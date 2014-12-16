#include "cSDL.h"


SDL::SDL(unsigned int flags) throw (InitError)
{
	if(SDL_Init(flags) != 0)
		throw InitError();
}


SDL::~SDL()
{
	SDL_Quit();
}
