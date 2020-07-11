#include <iostream>
#include "include/grasstile.h"
#include "include/screen.h"

GrassTile::GrassTile(Sprite &sprite) : Tile(sprite) {
}

GrassTile::~GrassTile() {
}

void GrassTile::render(int x, int y) {
	Screen &screen = *(Screen::getInstance());
	screen.renderTile(x << 4, y << 4, *this);
}
