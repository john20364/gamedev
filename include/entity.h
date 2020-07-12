#ifndef _ENTITY_H_
#define _ENTITY_H_
#include <iostream>
#include "level.h"
#include "randomutil.h"
#include "sprite.h"

class Entity {
public:
	double x, y;

	Entity();
	virtual ~Entity();
	virtual void update();
	virtual void render();
	virtual void remove();
	virtual bool isRemoved();
	virtual void init(Level* level);
private:
	bool removed = false;
protected:
	Sprite* sprite;
	Level* level;
	su::Random* random;	
};
#endif
