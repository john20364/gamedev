#ifndef _TILE_COORD_H_
#define _TILE_COORD_H_
class TileCoord {
public:
	TileCoord(int x, int y, float xOffset=.0, float yOffset=.0);
	~TileCoord();
	int getX();
	int getY();
	const int SIZE;
private:
	int x;
	int y;
};
#endif
