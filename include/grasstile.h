#ifndef _GRASS_TILE_H_
#define _GRASS_TILE_H_
#include "tile.h"

class GrassTile : public Tile {
public:	
	GrassTile(Sprite &sprite);
	~GrassTile();
	void render(int x, int y);
private:
};
#endif
