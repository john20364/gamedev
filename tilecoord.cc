#include <iostream>
#include "include/tilecoord.h"

TileCoord::TileCoord(int x, int y, float xOffset, float yOffset) : SIZE(16) {
	this->x = (x + xOffset) * SIZE;
	this->y = (y + yOffset) * SIZE;
}

TileCoord::~TileCoord() {
}

int TileCoord::getX() {
	return x;
}

int TileCoord::getY() {
	return y;
}
