#include <iostream>
#include "include/particle.h"

Particle::Particle(int x, int y) : Entity() {
	this->x = x;
	this->y = y;
}

Particle::~Particle() {
}
