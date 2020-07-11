#ifndef _SPRITES_H_
#define _SPRITES_H_

#include "sprite.h"

class Sprites {
public:
	static Sprites* getInstance();
	~Sprites();
	void destroy();
	Sprite* grass;
	Sprite* flower;
	Sprite* rock;
	Sprite* voidSprite;
	Sprite* player_forward;
	Sprite* player_forward_1;
	Sprite* player_forward_2;
	Sprite* player_back;
	Sprite* player_back_1;
	Sprite* player_back_2;
	Sprite* player_side;
	Sprite* player_side_1;
	Sprite* player_side_2;
	Sprite* wizard_projectile;
	Sprite* normal_particle;
	Sprite* test_particle;;
private:
	Sprites();
	static Sprites* instance;
};
#endif
