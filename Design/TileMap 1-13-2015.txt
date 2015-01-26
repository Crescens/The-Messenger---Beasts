#include "TileMap.h"


TileMap::TileMap()
{
	int x_ = 0, y_ = 0;
	bool hasCollision_ = false;
}


TileMap::~TileMap()
{
}

void TileMap::setX(int x)
{
	x_ = x;
}

void TileMap::setY(int y)
{
	y_ = y;
}

int TileMap::getX(void)
{
	return x_;
}

int TileMap::getY(void)
{
	return y_;
}

bool TileMap::hasCollision(void)
{
	return hasCollision_;
}
