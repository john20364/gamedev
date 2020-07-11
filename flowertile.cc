#include <iostream>
#include "include/flowertile.h"
#include "include/screen.h"

FlowerTile::FlowerTile(Sprite &sprite) : Tile(sprite) {
}

FlowerTile::~FlowerTile() {
}

void FlowerTile::render(int x, int y) {
	Screen &screen = *(Screen::getInstance());
	screen.renderTile(x << 4, y << 4, *this);
}
