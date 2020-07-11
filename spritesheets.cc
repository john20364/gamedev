#include <iostream>
#include "include/spritesheets.h"

SpriteSheets* SpriteSheets::instance = NULL;

SpriteSheets* SpriteSheets::getInstance() {
	if (instance == NULL) {
		instance = new SpriteSheets();
	}
	return instance;
}

void SpriteSheets::destroy() {
	if (instance) {
		delete instance;
		instance = NULL;
	}
}

SpriteSheets::SpriteSheets() {
	texture_sheet = 
		new SpriteSheet("res/texture/sheet/spritesheet.png", 256);
	projectile_sheet =
		new SpriteSheet("res/texture/sheet/projectilesheet.png", 256);
	player_sheet =
		new SpriteSheet("res/texture/sheet/playersheet.png", 64, 48);
	player_down = 
		new SpriteSheet(player_sheet, 0, 0, 1, 3, 16);
	player_up = 
		new SpriteSheet(player_sheet, 1, 0, 1, 3, 16);
	player_right = 
		new SpriteSheet(player_sheet, 2, 0, 1, 3, 16);
	player_left = 
		new SpriteSheet(player_sheet, 3, 0, 1, 3, 16);
	dummy_sheet =
		new SpriteSheet("res/texture/sheet/dummysheet.png", 64, 48);
	dummy_down = 
		new SpriteSheet(dummy_sheet, 0, 0, 1, 3, 16);
	dummy_up = 
		new SpriteSheet(dummy_sheet, 1, 0, 1, 3, 16);
	dummy_right = 
		new SpriteSheet(dummy_sheet, 2, 0, 1, 3, 16);
	dummy_left = 
		new SpriteSheet(dummy_sheet, 3, 0, 1, 3, 16);
	chaser_sheet =
		new SpriteSheet("res/texture/sheet/chasersheet.png", 64, 48);
	chaser_down = 
		new SpriteSheet(chaser_sheet, 0, 0, 1, 3, 16);
	chaser_up = 
		new SpriteSheet(chaser_sheet, 1, 0, 1, 3, 16);
	chaser_right = 
		new SpriteSheet(chaser_sheet, 2, 0, 1, 3, 16);
	chaser_left = 
		new SpriteSheet(chaser_sheet, 3, 0, 1, 3, 16);
}

SpriteSheets::~SpriteSheets() {
	delete dummy_left;
	delete dummy_right;
	delete dummy_up;
	delete dummy_down;
	delete dummy_sheet;
	delete chaser_left;
	delete chaser_right;
	delete chaser_up;
	delete chaser_down;
	delete chaser_sheet;
	delete player_left;
	delete player_right;
	delete player_up;
	delete player_down;
	delete player_sheet;
	delete projectile_sheet;
	delete texture_sheet;
}
