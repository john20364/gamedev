#ifndef _VOID_TILE_H
#define _VOID_TILE_H
#include "tile.h"

class VoidTile : public Tile {
public:	
	VoidTile(Sprite &sprite);
	~VoidTile();
	void render(int x, int y);
private:
};
#endif
