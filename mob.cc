#include <iostream>
#include "include/mob.h"
#include "include/level.h"
#include "include/wizardprojectile.h"
#include "include/levelentities.h"

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

void Mob::move(int xa, int ya) {
	if (xa != 0 && ya != 0) {
		move(xa, 0);
		move(0, ya);
		return;
	}

	if (xa > 0) dir = Mob::Direction::RIGHT;
	if (xa < 0) dir = Mob::Direction::LEFT;
	if (ya > 0) dir = Mob::Direction::DOWN;
	if (ya < 0) dir = Mob::Direction::UP;

	if (!level->collision(x + xa, y + ya, 3, 12, 8, 15)) {
		// -1, 0, 1
		x += xa;
		y += ya;
	}
}
