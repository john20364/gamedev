#include "include/spritesheet.h"
#include <iostream>
#include "string.h"

SpriteSheet::SpriteSheet(std::string path, int size) :
	WIDTH(size), HEIGHT(size), SIZE(size), path(path) {
	pixels = new sf::Uint32[SIZE * SIZE];
	load();
}

SpriteSheet::SpriteSheet(std::string path, int width, int height) :
	WIDTH(width), HEIGHT(height), SIZE(-1), path(path) {
	pixels = new sf::Uint32[WIDTH * HEIGHT];
	load();
}

SpriteSheet::SpriteSheet(SpriteSheet* sheet, int x, int y, 
	int width, int height, int spriteSize) : 
	WIDTH(width * spriteSize), HEIGHT(height * spriteSize), 
	SIZE((width == height) ? width * spriteSize : -1), path("") {
	pixels = new sf::Uint32[WIDTH * HEIGHT];
	for (int j = 0; j < HEIGHT; ++j) {
		int ypos = y * spriteSize + j;
		for (int i = 0; i < WIDTH; ++i) {
			int xpos = x * spriteSize + i;
			pixels[i + j * WIDTH] = sheet->pixels[xpos + ypos * sheet->WIDTH];
		}
	}
}

SpriteSheet::~SpriteSheet() {
	delete[] pixels;
}

void SpriteSheet::load() {
	sf::Image image;
	if (image.loadFromFile(path) != true)	{
		std::cout << "Cann't load: " << path << std::endl;
		exit(-1);
	}

	// Copy pixel array
	memcpy(pixels, image.getPixelsPtr(), WIDTH * HEIGHT * 4);
	std::cout << "Loading : " << path << " complete\n";
}
