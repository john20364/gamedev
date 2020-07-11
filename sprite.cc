#include <iostream>
#include "include/sprite.h"

Sprite::Sprite(SpriteSheet* sheet) :
	SIZE(sheet->SIZE), sheet(sheet) {
	pixels = NULL;
}

Sprite::Sprite(int size, int x, int y, SpriteSheet* sheet) :
	SIZE(size), x(x * SIZE), y(y * SIZE), sheet(sheet) {
	width = SIZE;
	height = SIZE;
	pixels = new sf::Uint32[SIZE * SIZE];
	load();
}

Sprite::Sprite(int size, sf::Uint32 color) : SIZE(size) {
	width = SIZE;
	height = SIZE;
	pixels = new sf::Uint32[SIZE * SIZE];
	for (int y = 0; y < SIZE; ++y) {
		for (int x = 0; x < SIZE; ++x) {
			pixels[x + y * SIZE] = color;
		}
	}
}

Sprite::Sprite(int width, int height, sf::Uint32 color) : 
	SIZE(-1), width(width), height(height) {
	pixels = new sf::Uint32[width * height];
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			pixels[x + y * width] = color;
		}
	}
}

Sprite::~Sprite() {
	delete[] pixels;
}

int Sprite::getWidth() {
	return width;
}

int Sprite::getHeight() {
	return height;
}

void Sprite::load() {
	for (int y = 0; y < SIZE; ++y) {
		for (int x = 0; x < SIZE; ++x) {
			pixels[x + y * SIZE] = 
				sheet->pixels[(x + this->x) + (y + this->y) * sheet->SIZE];
		}
	}
}
