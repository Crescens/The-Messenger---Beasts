#pragma once

#include <SDL.h>

#include "GameObject.h"

/*------------------------------------------------------------------------------------------------------------------------------------------------------
InputComponent

An abstracted interface for the InputComponent. The real work is done by the inherited classes.
------------------------------------------------------------------------------------------------------------------------------------------------------*/

class InputComponent
{

private:
	int lastFrameState;
};

