#ifndef _SPRITESHEET_H_
#define _SPRITESHEET_H_

#include <SFML/Graphics.hpp>
#include <string>

class SpriteSheet {
public:
	sf::Uint32* pixels;
	const int WIDTH;
	const int HEIGHT;
	const int SIZE;
	SpriteSheet(std::string path, int size);
	SpriteSheet(std::string path, int width, int height);
	SpriteSheet(SpriteSheet* sheet, int x, int y, 
				int width, int height, int spriteSize);
	~SpriteSheet();
private:
	void load();
	std::string path;
};
#endif
