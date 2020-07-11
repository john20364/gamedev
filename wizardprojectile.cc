#include <iostream>
#include "include/wizardprojectile.h"
#include "math.h"
#include "include/screen.h"
#include "include/sprites.h"
#include "include/spawnfactory.h"

int WizardProjectile::FIRE_RATE = 10;

WizardProjectile::WizardProjectile(int x, int y, double angle) :
	Projectile(x, y, angle) {
	range = 200;
	damage = 20;
	speed = 4;
	nx = speed * cos(angle);
	ny = speed * sin(angle);
	sprite = Sprites::getInstance()->wizard_projectile;
}

WizardProjectile::~WizardProjectile() {
//	std::cout << "destructor WizardProjectile\n";
}

void WizardProjectile::update() {
	if (level->collision(x + nx, y + ny, 4, 10, 4, 10)) {
		remove();
		SpawnParticleData sd;
		sd.x = x + 4;
		sd.y = y + 4;
		sd.xa = nx;
		sd.ya = ny;
		if (nx > 0) sd.x += 6;
		if (ny > 0) sd.y += 6;
		sd.life = 50;
		sd.amount = 100;
		SpawnFactory::getInstance()->build(
			SpawnFactory::Type::NORMAL_PARTICLE, level, &sd);
	} else {
		move();
	}
}

void WizardProjectile::render() {
	Screen::getInstance()->renderProjectile(x, y, *this);
}

double WizardProjectile::distance() {
	double dx = xOrgin - x;
	double dy = yOrigin - y;
	return sqrt(dx * dx + dy * dy);
}

void WizardProjectile::move() {
	x += nx;
	y += ny;
	if (distance() > range) remove();
}
