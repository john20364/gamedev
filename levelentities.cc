#include <iostream>
#include "include/levelentities.h"

LevelEntities* LevelEntities::instance = NULL;

LevelEntities* LevelEntities::getInstance() {
	if (instance == NULL) {
		instance = new LevelEntities();
	}
	return instance;
}

void LevelEntities::destroy () {
	if (instance) {
		delete instance;
		instance = NULL;
	}
}

int LevelEntities::sizeEntities() {
	return entities.size();
}

void LevelEntities::clearEntities() {
	std::list<Entity*>::iterator it;
	for (it = entities.begin(); it != entities.end(); ++it) {
		if ((*it)->isRemoved()) {
			delete *it;
			entities.erase(it);
		}
	}
}

void LevelEntities::clearAllEntities() {
	std::list<Entity*>::iterator it;
	for (it = entities.begin(); it != entities.end(); ++it) {
		delete *it;
		entities.erase(it);
	}
}

void LevelEntities::addEntity(Entity* entity) {
	entities.push_back(entity);
}

void LevelEntities::updateEntities() {
	std::list<Entity*>::iterator it;
	for (it = entities.begin(); it != entities.end(); ++it) {
		if ((*it)->isRemoved()) {
			delete *it;
			entities.erase(it);
		} else {
			(*it)->update();
		}
	}
}

void LevelEntities::renderEntities() {
	std::list<Entity*>::iterator it;
	for (it = entities.begin(); it != entities.end(); ++it) {
		(*it)->render();
	}
}

LevelEntities::LevelEntities() {
}

LevelEntities::~LevelEntities() {
	clearAllEntities();
}
