#ifndef _SPRITE_SHEETS_H_
#define _SPRITE_SHEETS_H_
#include "spritesheet.h"
#include <sstream>

class SpriteSheets {
public:
	static SpriteSheets* getInstance();
	~SpriteSheets();
	SpriteSheet* texture_sheet;
	SpriteSheet* projectile_sheet;
	SpriteSheet* player_sheet;
	SpriteSheet* player_down;
	SpriteSheet* player_up;
	SpriteSheet* player_right;
	SpriteSheet* player_left;
	SpriteSheet* dummy_sheet;
	SpriteSheet* dummy_down;
	SpriteSheet* dummy_up;
	SpriteSheet* dummy_right;
	SpriteSheet* dummy_left;
	SpriteSheet* chaser_sheet;
	SpriteSheet* chaser_down;
	SpriteSheet* chaser_up;
	SpriteSheet* chaser_right;
	SpriteSheet* chaser_left;
	void destroy();
private:
	SpriteSheets();
	static SpriteSheets* instance;
};
#endif
