#ifndef _LEVEL_H_
#define _LEVEL_H_

#include <sstream>
#include <list>
#include "tile.h"
#include <SFML/Graphics.hpp>
#include "node.h"

class Level {
public:
	std::list<Node*>* findPath(Vector2i* start, Vector2i* goal);
	bool vecInList(std::list<Node*> list, Vector2i* vector);
	void clearNodeList(std::list<Node*> list);
	Level(int width, int height);
	Level(std::string path);
	virtual ~Level();
	virtual void update();
	virtual void render(int xScroll, int yScroll);
	virtual Tile &getTile(int x, int y);
	virtual bool collision(int x, int y, 
						   int left, int right, int top, int bottom);
protected:
	int width;
	int height;
	sf::Uint32* tiles;
	void init();
	virtual void generateLevel();
	virtual void loadLevel(std::string path);
	virtual void time();
};
#endif
