#include <iostream>
#include <random>
#include "include/normalparticle.h"
#include "include/screen.h"
#include "include/sprites.h"
#include "include/randomutil.h"

NormalParticle::NormalParticle(int x, int y, int dx, int dy, int life) : 
	Particle(x, y) {
	dxOrigin = dx;
	dyOrigin = dy;
	xx = x;
	yy = y;

	su::Random rnd(-10, 10);
	this->life = life + rnd.generate();

	sprite = Sprites::getInstance()->normal_particle;

	su::NormalDistribution nd(0, 0.5);
	xa = nd.generate();
	ya = nd.generate();

	za = 0;
	zOffset = su::RandomFloat(2.0).generate();
	zz = zOffset;
}

NormalParticle::~NormalParticle() {
}

void NormalParticle::update() {
	move((int)(xx + xa), (int)(yy + ya) - (int)(zz + za) + (int)zOffset);
	za -= 0.1;

	if (zz < 0) {
		zz = 0;
		za *= -0.55;
		xa *= 0.4;	
		ya *= 0.4;	
	}

	if (--life == 0) remove();
}

void NormalParticle::move(int x, int y) {
	if (collision(x, y, sprite->SIZE - 1)) {
		xa *= -0.7;
		ya *= -0.7;
		za *= -0.7;
	} 
	xx += xa;
	yy += ya;
	zz += za;
}

bool NormalParticle::collision(int x, int y, int size) {
	bool solid = false;

	for (int c = 0; c < 4; ++c) {
		int xt = (x + c % 2 * size) >> 4;
		int yt = (y + c / 2 * size) >> 4;
		if (level->getTile(xt, yt).solid()) {
			if ((c < 2) && (dyOrigin < 0)) yy -= floor(ya);
			solid = true;
		}
	}
	return solid;
}

void NormalParticle::render() {
	Screen::getInstance()->renderSprite(
		(int)xx, (int)yy - (int)zz + (int)zOffset, *sprite, true);
}







