#include <iostream>
#include "include/levelplayers.h"
#include "math.h"

LevelPlayers* LevelPlayers::instance = NULL;

LevelPlayers* LevelPlayers::getInstance() {
	if (instance == NULL) {
		instance = new LevelPlayers();
	}
	return instance;
}

void LevelPlayers::destroy() {
	if (instance) {
		delete instance;
		instance = NULL;
	}
}

int LevelPlayers::sizePlayers() {
	return players.size();
}

void LevelPlayers::clearPlayers() {
	std::list<Player*>::iterator it;
	for (it = players.begin(); it != players.end(); ++it) {
		if ((*it)->isRemoved()) {
			delete *it;
			players.erase(it);
		}
	}
}

void LevelPlayers::clearAllPlayers() {
	std::list<Player*>::iterator it;
	for (it = players.begin(); it != players.end(); ++it) {
		delete *it;
		players.erase(it);
	}
}

void LevelPlayers::addPlayer(Player* player) {
	players.push_back(player);
}

void LevelPlayers::updatePlayers() {
	std::list<Player*>::iterator it;
	for (it = players.begin(); it != players.end(); ++it) {
		if ((*it)->isRemoved()) {
			delete *it;
			players.erase(it);
		} else {
			(*it)->update();
		}
	}
}

void LevelPlayers::renderPlayers() {
	std::list<Player*>::iterator it;
	for (it = players.begin(); it != players.end(); ++it) {
		(*it)->render();
	}
}

std::list<Player*> LevelPlayers::getPlayers(Entity* entity, int range) {
	std::list<Player*> collection;
	std::list<Player*>::iterator it;
	for (it = players.begin(); it != players.end(); ++it) {
		Player* player = (*it);
		double dx = player->x - entity->x;
		double dy = player->y - entity->y;
		double distance = sqrt(dx * dx + dy * dy);
		if (distance < range) {
			collection.push_back(player);
		}
	}
	return collection;
}

void LevelPlayers::setFrontPlayer(Player* player) {
	players.push_front(player);
}

Player* LevelPlayers::getFrontPlayer() {
	return players.front();
}

LevelPlayers::LevelPlayers() {
}

LevelPlayers::~LevelPlayers() {
	clearAllPlayers();
}

