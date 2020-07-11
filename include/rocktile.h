#ifndef _ROCK_TILE_H_
#define _ROCK_TILE_H_
#include "tile.h"

class RockTile : public Tile {
public:	
	RockTile(Sprite &sprite);
	~RockTile();
	void render(int x, int y);
	bool solid();
private:
};
#endif

