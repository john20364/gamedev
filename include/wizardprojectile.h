#ifndef _WIZARD_PROJECTILE_H_
#define _WIZARD_PROJECTILE_H_
#include "projectile.h"

class WizardProjectile : public Projectile {
public:
	static int FIRE_RATE;
	WizardProjectile(int x, int y, double angle);
	~WizardProjectile();
	virtual void update();
	virtual void render();
protected:
	virtual double distance();
	virtual void move();
};
#endif
