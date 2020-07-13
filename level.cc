#include <iostream>
#include "include/level.h"
#include "include/tiles.h"
#include "include/screen.h"
#include "include/levelentities.h"
#include "include/levelplayers.h"
#include "include/node.h"
#include "include/voidtile.h"

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

bool compare_fCost(const Node* first, const Node* second) {
	return first->fCost < second->fCost;
}

template<typename Base, typename T>
inline bool instanceof(const T&) {
   return std::is_base_of<Base, T>::value;
}

bool Level::vecInList(std::list<Node*> list, Vector2i* vector) {
	std::list<Node*>::iterator it;
	for (it = list.begin(); it != list.end(); ++it) {
		if((*it)->tile->equals(*vector)) return true;
	}
	return false;
}

void Level::clearNodeList(std::list<Node*> list) {
	std::list<Node*>::iterator it;
	for (it = list.begin(); it != list.end(); ++it) {
		delete *it;
		list.erase(it);
	}
}

std::list<Node*>* Level::findPath(Vector2i* start, Vector2i* goal) {
	std::list<Node*> openList;
	std::list<Node*> closedList;
	Node* current = new Node(start, NULL, 0, start->distance(*goal));
	openList.push_back(current);

	while (!openList.empty()) {
		openList.sort(compare_fCost);
		current = openList.front();
		
		if (current->tile->equals(*goal)) {
			std::list<Node*>* path = new std::list<Node*>;
			while (current->parent != NULL) {
				path->push_back(current);
				current = current->parent;
			}
			clearNodeList(openList);
			clearNodeList(closedList);
			return path;
		}
		openList.remove(current);
		closedList.push_back(current);

		for (int i = 0; i < 9; i++) {
			if (i == 4) continue;
			int x = current->tile->getX();
			int y = current->tile->getY();
			int xi = (i % 3) - 1; // -1, 0, 1
			int yi = (i / 3) - 1; // -1, 0, 1
			Tile& at = getTile(x + xi, y + yi);
			if (instanceof<VoidTile>(at) || at.solid()) continue;
			Vector2i* a = new Vector2i(x + xi, y + yi);
			double gCost = current->gCost + current->tile->distance(*a);
			double hCost = a->distance(*goal);
			Node* node = new Node(a, current, gCost, hCost);
			if (vecInList(closedList, a) && gCost >= node->gCost) continue;
			if (!vecInList(openList, a) || gCost < node->gCost) {
				openList.push_back(node);
			} else {
				delete node;
			}
		}
	}
	clearNodeList(closedList);
	return NULL;
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
