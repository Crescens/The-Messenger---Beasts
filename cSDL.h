#pragma once
#include "InitError.h"
#include<SDL.h>
#include<exception>
#include<string>

class SDL
{
public:
	SDL(unsigned int flags = 0) throw (InitError);
	virtual ~SDL();
};

