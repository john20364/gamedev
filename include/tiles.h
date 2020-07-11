#ifndef _TILES_H_
#define _TILES_H_

#include "tile.h"

class Tiles {
public:
	static Tiles* getInstance();
	~Tiles();
	void destroy();
	Tile* grass;
	Tile* flower;
	Tile* rock;
	Tile* voidTile;
	const int col_grass;
	const int col_flower;
	const int col_rock;
	const int col_voidTile;
private:
	static Tiles* instance;
	Tiles();
};
#endif
