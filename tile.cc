#include <iostream>
#include "include/tile.h"

Tile::Tile(Sprite &sprite) : sprite(sprite) {
}

Tile::~Tile() {
}

void Tile::render(int x, int y) {
}

bool Tile::solid() {
	return false;
}
