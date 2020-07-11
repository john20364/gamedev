#include "include/randomlevel.h"
#include <iostream>
#include "include/tiles.h"
#include "include/randomutil.h"

RandomLevel::RandomLevel(int width, int height) : Level(width, height) {
	generateLevel();
}

RandomLevel::~RandomLevel() {
}

// Colorformate = AABBGGRR
// Grass = 0xFF00FF00;
// Flower = 0xFF00FFFF;
// Rock = 0xFF007F7F;
// PINK = 0xFFFF00FF;
void RandomLevel::generateLevel() {
	Tiles* t = Tiles::getInstance();

	su::Random random(4);

	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			int n = random.generate();
			if (n == 0) tiles[x + y * width] = t->col_grass;
			if (n == 1) tiles[x + y * width] = t->col_flower; 
			if (n == 2) tiles[x + y * width] = t->col_rock; 
			if (n == 3) tiles[x + y * width] = t->col_voidTile;
			if (n == 4) tiles[x + y * width] = t->col_voidTile; 
		}
	}
}


