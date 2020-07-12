#include <iostream>
#include <list>
#include "include/player.h"
#include "include/sprites.h"
#include "include/screen.h"
#include "include/mouse.h"
#include "math.h"
#include "include/wizardprojectile.h"

Player::Player(Keyboard* input) : Mob() {
	initPlayer(0, 0, input);
}

Player::Player(int x, int y, Keyboard* input) : Mob() {
	initPlayer(x, y, input);
}

void Player::initPlayer(int x, int y, Keyboard* input) {
	walking = false;
	anim = 0;
	this->x = x;
	this->y = y;
	this->input = input;

	spriteUp = new AnimatedSprite(
		SpriteSheets::getInstance()->player_up,
		AnimatedSprite::Orientation::VERTICAL, 3);

	spriteDown = new AnimatedSprite(
		SpriteSheets::getInstance()->player_down,
		AnimatedSprite::Orientation::VERTICAL, 3);

	spriteLeft = new AnimatedSprite(
		SpriteSheets::getInstance()->player_left,
		AnimatedSprite::Orientation::VERTICAL, 3);

	spriteRight = new AnimatedSprite(
		SpriteSheets::getInstance()->player_right,
		AnimatedSprite::Orientation::VERTICAL, 3);

	int r = 7;
	spriteUp->setRate(r);
	spriteDown->setRate(r);
	spriteLeft->setRate(r);
	spriteRight->setRate(r);
	spriteCurrent = spriteDown;
}

void Player::update() {
	Mob::update();
	walking ? spriteCurrent->update() : spriteCurrent->startFrame();

	int xa = 0;
	int ya = 0;

	if (input->left) {
		spriteCurrent = spriteLeft;	
		xa -= 2;	
	} else if (input->right) {
		spriteCurrent = spriteRight;	
		xa += 2;
	}

	if (input->up) {
		spriteCurrent = spriteUp;	
		ya -= 2;	
	} else if (input->down) {
		spriteCurrent = spriteDown;	
		ya += 2;
	} 

	if (xa != 0 || ya != 0) {
		move(xa, ya);
		walking = true;
	} else {
		walking = false;
	}

	updateShooting();
}

void Player::updateShooting() {
	if (Mouse::getInstance()->leftButton()) {
		if (fireRate == 0) {
			sf::Vector2i pos = Mouse::getInstance()->position();
			sf::Vector2i center = Mouse::getInstance()->center();
			// - 24 = 16 + 8 correction for the sprite left-upper corner !!!
			double dx = pos.x - center.x - 24;
			double dy = pos.y - center.y - 24;
			double angle = atan2(dy, dx);
			Projectile* projectile = new WizardProjectile(x, y, angle);
			projectile->init(level);
			shoot(projectile);
		}
		++fireRate %= WizardProjectile::FIRE_RATE;
	} else {
		fireRate = 0;
	}
}

void Player::render() {
	Mob::render();
	Screen::getInstance()->renderSprite(x, y, *spriteCurrent, true);
}

Player::~Player() {
	delete spriteUp;
	delete spriteDown;
	delete spriteLeft;
	delete spriteRight;
}
