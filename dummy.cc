#include <iostream>
#include "include/dummy.h"
#include "include/screen.h"
#include "include/randomutil.h"

Dummy::Dummy(int x, int y) : Mob() {
	this->x = x << 4;
	this->y = y << 4;

	spriteUp = new AnimatedSprite(
		SpriteSheets::getInstance()->dummy_up,
		AnimatedSprite::Orientation::VERTICAL, 3);

	spriteDown = new AnimatedSprite(
		SpriteSheets::getInstance()->dummy_down,
		AnimatedSprite::Orientation::VERTICAL, 3);

	spriteLeft = new AnimatedSprite(
		SpriteSheets::getInstance()->dummy_left,
		AnimatedSprite::Orientation::VERTICAL, 3);

	spriteRight = new AnimatedSprite(
		SpriteSheets::getInstance()->dummy_right,
		AnimatedSprite::Orientation::VERTICAL, 3);

	int r = 7;
	spriteUp->setRate(r);
	spriteDown->setRate(r);
	spriteLeft->setRate(r);
	spriteRight->setRate(r);
	spriteCurrent = spriteDown;

	dir = Mob::Direction::DOWN;
	xa = 0;
	ya = 0;
	time = 0;
}

Dummy::~Dummy() {
	delete spriteUp;
	delete spriteDown;
	delete spriteLeft;
	delete spriteRight;
}

void Dummy::update() {
	Mob::update();
	walking ? spriteCurrent->update() : spriteCurrent->startFrame();

	int modulo = su::Random(10,60).generate();
	if (!(++time %= modulo)) {
		xa = su::Random(-1, 1).generate();
		ya = su::Random(-1, 1).generate();
		if (su::Random(3).generate() == 3) {
			xa = ya = 0;
		}
	}	

	if (xa < 0) {
		spriteCurrent = spriteLeft;	
		dir = Mob::Direction::LEFT;
	} else if (xa > 0) {
		spriteCurrent = spriteRight;	
		dir = Mob::Direction::RIGHT;
	}

	if (ya < 0) {
		spriteCurrent = spriteUp;	
		dir = Mob::Direction::UP;
	} else if (ya > 0) {
		spriteCurrent = spriteDown;	
		dir = Mob::Direction::DOWN;
	} 

	if (xa != 0 || ya != 0) {
		move(xa, ya);
		walking = true;
	} else {
		walking = false;
	}
}

void Dummy::render() {
	Mob::render();
	Screen::getInstance()->renderSprite(x, y, *spriteCurrent, true);
}
