#ifndef _TILE_H_
#define _TILE_H_

#include "sprite.h"

class Tile {
public:
	int x;
	int y;
	Sprite &sprite;

	Tile(Sprite &sprite);
	virtual ~Tile();
	virtual void render(int x, int y);
	virtual bool solid();
private:
};
#endif
