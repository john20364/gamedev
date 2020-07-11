#include <iostream>
#include "include/level.h"
#include "include/tiles.h"
#include "include/screen.h"
#include "include/levelentities.h"
#include "include/levelplayers.h"

Level::Level(int width, int height) {
	tiles = NULL;
	this->width = width;
	this->height = height;
	init();
}

Level::Level(std::string path) {
	tiles = NULL;
}

Level::~Level() {
	delete[] tiles;
	LevelPlayers::getInstance()->destroy();
	LevelEntities::getInstance()->destroy();
}

void Level::init() {
	if (tiles == NULL) {
		tiles = new sf::Uint32[width * height];
	}
}

void Level::generateLevel() {
	std::cout << "void Level::generateLevel() {" << std::endl;
}

void Level::loadLevel(std::string path) {
	std::cout << "void Level::loadLevel(std::string path) {" << std::endl;
}

void Level::time() {
}

bool Level::collision(int x, int y, 
					  int left, int right, int top, int bottom) {
	bool solid = false;

	for (int corner = 0; corner < 4; ++corner) {
		int xt = (x + corner % 2 * right + left - corner % 2 * left) >> 4;
		int yt = (y + corner / 2 * bottom + top - corner / 2 * top) >> 4;
		if (getTile(xt, yt).solid()) solid = true;
	}
	return solid;
}

Tile &Level::getTile(int x, int y) {
	Tiles* t = Tiles::getInstance();
	if (x < 0 || y < 0 || x >= width || y >= height) return *t->voidTile;
	if (tiles[x + y * width] == t->col_grass) 	return *t->grass;
	if (tiles[x + y * width] == t->col_flower) 	return *t->flower;
	if (tiles[x + y * width] == t->col_rock) 	return *t->rock;
	return *t->voidTile;		
}

void Level::update() {
	LevelEntities::getInstance()->updateEntities();
	LevelPlayers::getInstance()->updatePlayers();
}

void Level::render(int xScroll, int yScroll) {
	Screen& screen = *Screen::getInstance();
	screen.setOffset(xScroll, yScroll);
	int x0 = xScroll >> 4;
	int y0 = yScroll >> 4;
	int x1 = (xScroll + screen.getWidth() + 16) >> 4;
	int y1 = (yScroll + screen.getHeight() + 16) >> 4;

	for (int y = y0; y < y1; ++y) {
		for (int x = x0; x < x1; ++x) {
			getTile(x, y).render(x, y);
		}
	}
	LevelEntities::getInstance()->renderEntities();
	LevelPlayers::getInstance()->renderPlayers();
}
