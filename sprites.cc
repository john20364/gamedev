#include <iostream>
#include "include/sprites.h"

Sprites* Sprites::instance = NULL;

Sprites* Sprites::getInstance() {
	if (instance == NULL) {
		instance = new Sprites();
	}
	return instance;
}

void Sprites::destroy() {
	if (instance) {
		delete instance;
		instance = NULL;
	}
}

Sprites::Sprites() {
	grass = 
		new Sprite(16, 4, 0, SpriteSheets::getInstance()->texture_sheet);
	flower =
		new Sprite(16, 5, 0, SpriteSheets::getInstance()->texture_sheet);
	rock = 
		new Sprite(16, 3, 0, SpriteSheets::getInstance()->texture_sheet);
	player_forward =
		new Sprite(16, 1, 13, SpriteSheets::getInstance()->texture_sheet);
	player_forward_1 =
		new Sprite(16, 1, 14, SpriteSheets::getInstance()->texture_sheet);
	player_forward_2 =
		new Sprite(16, 1, 15, SpriteSheets::getInstance()->texture_sheet);
	player_back =
		new Sprite(16, 0, 13, SpriteSheets::getInstance()->texture_sheet);
	player_back_1 =
		new Sprite(16, 0, 14, SpriteSheets::getInstance()->texture_sheet);
	player_back_2 =
		new Sprite(16, 0, 15, SpriteSheets::getInstance()->texture_sheet);
	player_side =
		new Sprite(16, 2, 13, SpriteSheets::getInstance()->texture_sheet);
	player_side_1 =
		new Sprite(16, 2, 14, SpriteSheets::getInstance()->texture_sheet);
	player_side_2 =
		new Sprite(16, 2, 15, SpriteSheets::getInstance()->texture_sheet);
	// color alpha blue green red
	voidSprite = new Sprite(16, 0xFFE0871B);

	wizard_projectile = 
		new Sprite(16, 1, 0, SpriteSheets::getInstance()->projectile_sheet);
	
	normal_particle = new Sprite(2, 0xFFAAAAAA);
	test_particle = new Sprite(2, 0xFF0000FF);
}

Sprites::~Sprites() {
	delete wizard_projectile;
	delete normal_particle;
	delete test_particle;
	delete voidSprite;
	delete grass;
	delete flower;
	delete rock;
	delete player_forward;
	delete player_forward_1;
	delete player_forward_2;
	delete player_back;
	delete player_back_1;
	delete player_back_2;
	delete player_side;
	delete player_side_1;
	delete player_side_2;
}
