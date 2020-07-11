#ifndef _SPRITE_H_
#define _SPRITE_H_

#include <SFML/Graphics.hpp>
#include "spritesheets.h"

class Sprite {
public:
	Sprite(int size, int x, int y, SpriteSheet* sheet);
	Sprite(int size, sf::Uint32 color);
	Sprite(int width, int height, sf::Uint32 color);
	virtual ~Sprite();
	sf::Uint32* pixels;
	const int SIZE;
	virtual int getWidth();
	virtual int getHeight();
protected:
	int width, height;
	Sprite(SpriteSheet* sheet);
private:
	int x, y;
	SpriteSheet* sheet;
	void load();
};
#endif
