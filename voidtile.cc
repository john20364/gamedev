#include <iostream>
#include "include/voidtile.h"
#include "include/screen.h"

VoidTile::VoidTile(Sprite &sprite) : Tile(sprite) {
}

VoidTile::~VoidTile() {
}

void VoidTile::render(int x, int y) {
	Screen &screen = *(Screen::getInstance());
	screen.renderTile(x << 4, y << 4, *this);
}
