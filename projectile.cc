#include <iostream>
#include "include/projectile.h"

Projectile::Projectile(int x, int y, double angle) : Entity() {
	xOrgin = x;
	yOrigin = y;
	this->angle = angle;
	this->x = x;
	this->y = y;
}

Projectile::~Projectile() {
}

Sprite* Projectile::getSprite() {
	return sprite;
}

int Projectile::getSpriteSize() {
	return sprite->SIZE;
}

void Projectile::move() {
}
