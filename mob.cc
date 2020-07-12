#include <iostream>
#include "include/mob.h"
#include "include/level.h"
#include "include/wizardprojectile.h"
#include "include/levelentities.h"
#include "math.h"

Mob::Mob() : Entity() {
	fireRate = 0;
	moving = false;
}

Mob::~Mob() {
	std::list<Projectile*>::iterator p;
	for (p = projectiles.begin(); p != projectiles.end(); ++p) {
		delete *p;
		projectiles.erase(p);
	}
}

void Mob::update() {
	std::list<Projectile*>::iterator p;
	for (p = projectiles.begin(); p != projectiles.end(); ++p) {
		if ((*p)->isRemoved()) {
			delete *p;
			projectiles.erase(p);
		} else {
			(*p)->update();
		}
	}
}

void Mob::render() {
	std::list<Projectile*>::iterator p;
	for (p = projectiles.begin(); p != projectiles.end(); ++p) {
		(*p)->render();
	}
}

void Mob::shoot(Projectile* projectile) {
	projectiles.push_back(projectile);
}

void Mob::move(double xa, double ya) {
	if (xa != 0 && ya != 0) {
		move(xa, 0);
		move(0, ya);
		return;
	}

	if (xa > 0) dir = Mob::Direction::RIGHT;
	if (xa < 0) dir = Mob::Direction::LEFT;
	if (ya > 0) dir = Mob::Direction::DOWN;
	if (ya < 0) dir = Mob::Direction::UP;

	while (xa != 0) {
		if (abs(xa) > 1) {
			if (!level->collision(x + normalize(xa), y, 3, 12, 8, 15)) {
				x += normalize(xa);
			}
			xa -= normalize(xa);
		} else {
			if (!level->collision(x + xa, y, 3, 12, 8, 15)) {
				x += xa;
			}
			xa = 0;
		}
	}

	while (ya != 0) {
		if (abs(ya) > 1) {
			if (!level->collision(x, y + normalize(ya), 3, 12, 8, 15)) {
				y += normalize(ya);
			}
			ya -= normalize(ya);
		} else {
			if (!level->collision(x, y + ya, 3, 12, 8, 15)) {
				y += ya;
			}
			ya = 0;
		}
	}
}

int Mob::normalize(double value) {
	if (value < 0) return -1;
	return 1;
}
