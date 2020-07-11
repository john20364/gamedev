#ifndef _FLOWER_TILE_H_
#define _FLOWER_TILE_H_
#include "tile.h"

class FlowerTile : public Tile {
public:	
	FlowerTile(Sprite &sprite);
	~FlowerTile();
	void render(int x, int y);
private:
};
#endif
