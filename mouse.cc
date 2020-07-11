#include <iostream>
#include "include/mouse.h"

Mouse* Mouse::instance = NULL;

Mouse* Mouse::getInstance() {
	if (instance == NULL) {
		instance = new Mouse();
	}
	return instance;
}

void Mouse::destroy() {
	if (instance) {
		delete instance;
		instance = NULL;
	}
}

void Mouse::setWindow(sf::Window* window) {
	this->window = window;
	clientSize = window->getSize();
}

Mouse::Mouse() {
}

Mouse::~Mouse() {
}

sf::Vector2i Mouse::center() {
	return sf::Vector2i(clientSize.x >> 1, clientSize.y >> 1);
}
bool Mouse::insideWindow() {
	sf::Vector2i position = sf::Mouse::getPosition(*window);
	if (position.x >= 0 && position.x < clientSize.x &&
		position.y >= 0 && position.y < clientSize.y)
		return true;
	return false;
}

void Mouse::position(sf::Vector2i pos) {
	sf::Mouse::setPosition(pos, *window);
}

void Mouse::position(int x, int y) {
	sf::Vector2i pos(x, y);
	sf::Mouse::setPosition(pos, *window);
}

sf::Vector2i Mouse::position() {
	return sf::Mouse::getPosition(*window);
}

bool Mouse::leftButton() {
	if (insideWindow())
		return sf::Mouse::isButtonPressed(sf::Mouse::Left);
	return false;
}

bool Mouse::middleButton() {
	if (insideWindow()) 
		return sf::Mouse::isButtonPressed(sf::Mouse::Middle);
	return false;
}

bool Mouse::rightButton() {
	if (insideWindow())
		return sf::Mouse::isButtonPressed(sf::Mouse::Right);
	return false;
}

