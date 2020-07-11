#include <iostream>
#include "include/spawnlevel.h"
#include <SFML/Graphics.hpp>
#include "include/tiles.h"
#include "include/levelentities.h"
#include "include/dummy.h"
#include "include/chaser.h"

SpawnLevel::SpawnLevel(std::string path) : Level(path) {
	loadLevel(path);
}

SpawnLevel::~SpawnLevel() {
}

void SpawnLevel::loadLevel(std::string path) {
	sf::Image image;
	if (image.loadFromFile(path) != true)	{
		std::cout << "Cann't load: " << path << std::endl;
		exit(-1);
	}

	sf::Vector2u size = image.getSize();
	width = size.x;
	height = size.y;

	init();

	// Copy pixel array
	memcpy(tiles, image.getPixelsPtr(), width * height * 4);

	for (int i = 0; i < 2; ++i) {
		Dummy* dummy  = new Dummy(4, 5);	
		dummy->init(this);
		LevelEntities::getInstance()->addEntity(dummy);
	}

	Chaser* chaser = new Chaser(3, 3);
	chaser->init(this);
	LevelEntities::getInstance()->addEntity(chaser);
}
