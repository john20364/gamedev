#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "mob.h"
#include "keyboard.h"
#include "animatedsprite.h"

class Player : public Mob {
public:
	Player(Keyboard* input);
	Player(int x, int y, Keyboard* input);
	~Player();
	void update();
	void render();
	AnimatedSprite* spriteUp;	
	AnimatedSprite* spriteDown;	
	AnimatedSprite* spriteLeft;	
	AnimatedSprite* spriteRight;	
	AnimatedSprite* spriteCurrent;	
private:
	void initPlayer(int x, int y, Keyboard* input);
	void updateShooting();
	int anim;
	Keyboard* input;
};
#endif
