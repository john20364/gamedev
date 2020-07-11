#include <iostream>
#include "include/rocktile.h"
#include "include/screen.h"

RockTile::RockTile(Sprite &sprite) : Tile(sprite) {
}

RockTile::~RockTile() {
}

void RockTile::render(int x, int y) {
	Screen &screen = *(Screen::getInstance());
	screen.renderTile(x << 4, y << 4, *this);
}

bool RockTile::solid() {
	return true;
}
