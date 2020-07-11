#ifndef _NORMAL_PARTICLE_H_
#define _NORMAL_PARTICLE_H_
#include "particle.h"

class NormalParticle : public Particle {
public:
	NormalParticle(int x, int y, int dx, int dy, int life);
	~NormalParticle();
	virtual void update();
	virtual void render();
protected:
	int life;
	int dxOrigin;
	int dyOrigin;
	double xa, ya, za;
	double xx, yy, zz;
	double zOffset;
	virtual void move(int x, int y);
	virtual bool collision(int x, int y, int size);
};
#endif
