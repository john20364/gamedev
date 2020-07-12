#ifndef _MOB_H_
#define _MOB_H_
#include <list>
#include "entity.h"
#include "projectile.h"

class Mob : public Entity {
public:
	enum Direction {UP, DOWN, LEFT, RIGHT};
	Mob();
	virtual ~Mob();
	virtual void move(int xa, int ya);
	virtual void update();
	virtual void render();
	virtual void shoot(Projectile* projectile);
protected:
	std::list<Projectile*> projectiles;
	bool moving;
	int fireRate;
	Direction dir;
	bool walking;
private:
	int normalize(int value);
};
#endif
