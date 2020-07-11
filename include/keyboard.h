#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include <SFML/Graphics.hpp>

class Keyboard {
public:
	Keyboard();
	~Keyboard();
	void update();
	void event(sf::Event &event);
	bool up;
	bool down;
	bool left;
	bool right;
private:
	bool keys[0xFF];
};
#endif
