#include <iostream>
#include "include/tiles.h"
#include "include/grasstile.h"
#include "include/flowertile.h"
#include "include/rocktile.h"
#include "include/voidtile.h"
#include "include/sprites.h"

Tiles* Tiles::instance = NULL;

Tiles* Tiles::getInstance() {
	if (instance == NULL) {
		instance = new Tiles();
	}
	return instance;
}

void Tiles::destroy() {
	if (instance) {
		delete instance;
		instance = NULL;
	}
}

// Colorformate = AABBGGRR
// Grass = 0xFF00FF00;
// Flower = 0xFF00FFFF;
// Rock = 0xFF007F7F;
// PINK = 0xFFFF00FF;
Tiles::Tiles() :
	col_grass(0xFF00FF00),
	col_flower(0xFF00FFFF),
	col_rock(0xFF007F7F),
	col_voidTile(0xFFFF00FF) {
	grass = new GrassTile(*(Sprites::getInstance()->grass));
	flower = new FlowerTile(*(Sprites::getInstance()->flower));
	rock = new RockTile(*(Sprites::getInstance()->rock));
	voidTile = new VoidTile(*(Sprites::getInstance()->voidSprite));
}

Tiles::~Tiles() {
	delete voidTile;
	delete grass;
}
