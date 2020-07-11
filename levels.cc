#include <iostream>
#include "include/levels.h"
#include "include/spawnlevel.h"

Levels* Levels::instance = NULL;

Levels* Levels::getInstance() {
	if (instance == NULL) {
		 instance = new Levels();
	}
	return instance;
}

void Levels::destroy() {
	if (instance) {
		delete instance;
		instance = NULL;
	}
}

Levels::Levels() {
	spawn = new SpawnLevel("res/texture/level/level.png");
}

Levels::~Levels() {
	delete spawn;
}
