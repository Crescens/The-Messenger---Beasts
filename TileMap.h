#pragma once

class TileMap
{
public:
	TileMap();
	~TileMap();

	void setX(int x);
	void setY(int y);

	int getX(void);
	int getY(void);

	bool hasCollision(void);

private:
	const int TILE_SIZE_ = 16;
	int x_, y_;
	bool hasCollision_;
};

