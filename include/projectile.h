#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_
#include "entity.h"
#include "sprite.h"

class Projectile : public Entity {
public:
	Projectile(int x, int y, double angle);
	virtual ~Projectile();
	virtual Sprite* getSprite();
	virtual int getSpriteSize();
protected:
	int xOrgin, yOrigin;
	double angle;
	double x, y;
	double nx, ny;
	double speed, range, damage;
	virtual void move();
};
#endif
