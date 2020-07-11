#include <iostream>
#include "include/chaser.h"
#include "include/screen.h"
#include "include/levelplayers.h"
#include "include/randomutil.h"

Chaser::Chaser(int x, int y) : Mob() {
	this->x = x << 4;
	this->y = y << 4;

	spriteUp = new AnimatedSprite(
		SpriteSheets::getInstance()->chaser_up,
		AnimatedSprite::Orientation::VERTICAL, 3);

	spriteDown = new AnimatedSprite(
		SpriteSheets::getInstance()->chaser_down,
		AnimatedSprite::Orientation::VERTICAL, 3);

	spriteLeft = new AnimatedSprite(
		SpriteSheets::getInstance()->chaser_left,
		AnimatedSprite::Orientation::VERTICAL, 3);

	spriteRight = new AnimatedSprite(
		SpriteSheets::getInstance()->chaser_right,
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

Chaser::~Chaser() {
	delete spriteUp;
	delete spriteDown;
	delete spriteLeft;
	delete spriteRight;
}

void Chaser::moving() {
	xa = 0;
	ya = 0;

	std::list<Player*> players = 
		LevelPlayers::getInstance()->getPlayers(this, 50);	

	if (players.size() > 0) {
		Player* player = players.front();
		if (x < player->x) xa++;
		if (x > player->x) xa--;
		if (y < player->y) ya++;
		if (y > player->y) ya--;
	}

	if (xa != 0 || ya != 0) {
		move(xa, ya);
		walking = true;
	} else {
		walking = false;
	}
}

void Chaser::update() {
	if (++time %= 2) return;
	moving();
	Mob::update();
	walking ? spriteCurrent->update() : spriteCurrent->startFrame();

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
}


void Chaser::render() {
	Mob::render();
	Screen::getInstance()->renderSprite(x, y, *spriteCurrent, true);
}
