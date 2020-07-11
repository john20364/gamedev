#pragma once
#include "mob.h"
#include "animatedsprite.h"
#include "player.h"

class Chaser : public Mob {
public:
	Chaser(int x, int y);
	virtual ~Chaser();
	virtual void update();
	virtual void render();
	void moving();
	AnimatedSprite* spriteUp;	
	AnimatedSprite* spriteDown;	
	AnimatedSprite* spriteLeft;	
	AnimatedSprite* spriteRight;	
	AnimatedSprite* spriteCurrent;	
protected:
	int xa, ya;
	int time;
};
