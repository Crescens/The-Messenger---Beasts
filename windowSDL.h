#pragma once
#include "cSDL.h"
#include <string>

class windowSDL
{
public:
	windowSDL(std::string& title, int x, int y, int w, int h, unsigned int flags);
	~windowSDL(void);
private:
	static const std::string title;
	int x, y, w, h;
	unsigned int flags;
};

