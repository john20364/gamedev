#include "include/keyboard.h"
#include <iostream>

Keyboard::Keyboard() {
	for (int i = 0; i < 0xFF; ++i) {
		keys[i] = false;
	}
}

Keyboard::~Keyboard() {
}

void Keyboard::event(sf::Event &event) {
	switch(event.type) {
	case sf::Event::KeyPressed:
		keys[event.key.code & 0xFF] = true;
		break;
	case sf::Event::KeyReleased:
		keys[event.key.code & 0xFF] = false;
		break;
	default:
		break;
	}
}

void Keyboard::update() {
	up = keys[sf::Keyboard::Up & 0xFF] || keys[sf::Keyboard::W & 0xFF];
	down = keys[sf::Keyboard::Down & 0xFF] || keys[sf::Keyboard::S & 0xFF];
	left = keys[sf::Keyboard::Left & 0xFF] || keys[sf::Keyboard::A & 0xFF];
	right = keys[sf::Keyboard::Right & 0xFF] || keys[sf::Keyboard::D & 0xFF];
}
