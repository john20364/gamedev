#pragma once
#include "mob.h"
#include "animatedsprite.h"

class Dummy : public Mob {
public:
	Dummy(int x, int y); 
	virtual ~Dummy(); 
	virtual void update();
	virtual void render();
	AnimatedSprite* spriteUp;	
	AnimatedSprite* spriteDown;	
	AnimatedSprite* spriteLeft;	
	AnimatedSprite* spriteRight;	
	AnimatedSprite* spriteCurrent;	
protected:
	int xa, ya;
	int time;
};
