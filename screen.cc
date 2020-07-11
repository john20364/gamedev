#include <iostream>
#include "include/screen.h"

Screen* Screen::instance = NULL;

Screen* Screen::getInstance() {
	if (instance == NULL) {
		instance = new Screen();
	}
	return instance;
}

int Screen::getWidth() {
	return width;
}

int Screen::getHeight() {
	return height;
}

void Screen::clear(sf::Uint32 color) {
	for (int i = 0; i < width * height; ++i) {
		pixels[i] = color;
	}
}

void Screen::setOffset(int xOffset, int yOffset) {
	this->xOffset = xOffset;
	this->yOffset = yOffset;
}

void Screen::renderPlayer(int xp, int yp, Sprite& player, int flip) {
	xp -= xOffset;
	yp -= yOffset;
	for (int y = 0; y < player.SIZE; ++y) {
		int ya = y + yp;
		for (int x = 0; x < player.SIZE; ++x) {
			int xa = x + xp;
			if (xa < -player.SIZE || xa >= width || 
				ya < -player.SIZE || ya >= height) break;
			if (xa < 0) xa = 0;
			if (ya < 0) ya = 0;
			int xs = x;
			if (flip == 1) xs = player.SIZE - 1 - x;
			sf::Uint32 color = player.pixels[xs+y*player.SIZE];
			if (color != 0xFFFF00FF)
				pixels[xa+ya*width] = color; 
		}
	}
}

void Screen::renderProjectile(int xp, int yp, Projectile& p) {
	xp -= xOffset;
	yp -= yOffset;
	for (int y = 0; y < p.getSpriteSize(); ++y) {
		int ya = y + yp;
		for (int x = 0; x < p.getSpriteSize(); ++x) {
			int xa = x + xp;
			if (xa < -p.getSpriteSize() || xa >= width || 
				ya < -p.getSpriteSize() || ya >= height) break;
			if (xa < 0) xa = 0;
			if (ya < 0) ya = 0;
			sf::Uint32 color = p.getSprite()->pixels[x+y*p.getSpriteSize()];
			if (color != 0xFFFF00FF)
				pixels[xa+ya*width] = color;
		}
	}
}

void Screen::renderSpriteSheet(int xp, int yp, SpriteSheet& sheet, bool fixed) {
	if (fixed) {
		xp -= xOffset;
		yp -= yOffset;
	}
	for (int y = 0; y < sheet.HEIGHT; ++y) {
		int ya = y + yp;
		for (int x = 0; x < sheet.WIDTH; ++x) {
			int xa = x + xp;
			if (xa < 0 || xa >= width || ya < 0 || ya >= height) break;
			pixels[xa + ya * width] = sheet.pixels[x + y * sheet.WIDTH];
		}
	}
}

void Screen::renderSprite(int xp, int yp, Sprite& sprite, bool fixed) {
	if (fixed) {
		xp -= xOffset;
		yp -= yOffset;
	}
	for (int y = 0; y < sprite.getHeight(); ++y) {
		int ya = y + yp;
		for (int x = 0; x < sprite.getWidth(); ++x) {
			int xa = x + xp;
			if (xa < 0 || xa >= width || ya < 0 || ya >= height) break;
			sf::Uint32 color = sprite.pixels[x + y * sprite.getWidth()];
			if (color != 0xFFFF00FF)
				pixels[xa + ya * width] = color; 
		}
	}
}

//void Screen::renderSprite(int xp, int yp, Sprite& sprite) {
//	xp -= xOffset;
//	yp -= yOffset;
//	for (int y = 0; y < sprite.SIZE; ++y) {
//		int ya = y + yp;
//		for (int x = 0; x < sprite.SIZE; ++x) {
//			int xa = x + xp;
//			if (xa < -sprite.SIZE || xa >= width || 
//				ya < -sprite.SIZE || ya >= height) break;
//			if (xa < 0) xa = 0;
//			if (ya < 0) ya = 0;
//			sf::Uint32 color = sprite.pixels[x+y*sprite.SIZE];
//			if (color != 0xFFFF00FF)
//				pixels[xa+ya*width] = color;
//		}
//	}
//}

void Screen::renderTile(int xp, int yp, Tile& tile) {
	xp -= xOffset;
	yp -= yOffset;
	for (int y = 0; y < tile.sprite.SIZE; ++y) {
		int ya = y + yp;
		for (int x = 0; x < tile.sprite.SIZE; ++x) {
			int xa = x + xp;
			if (xa < -tile.sprite.SIZE || xa >= width || 
				ya < -tile.sprite.SIZE || ya >= height) break;
			if (xa < 0) xa = 0;
			if (ya < 0) ya = 0;
			pixels[xa+ya*width] = tile.sprite.pixels[x+y*tile.sprite.SIZE];
		}
	}
}

Screen::Screen() {
	xOffset = 0;
	yOffset = 0;
	pixels = NULL;
}

Screen::~Screen() {
	if (pixels) {
		delete[] pixels;
	}
}

Screen* Screen::init(int width, int height) {
	if (!pixels) {
		this->width = width;
		this->height = height;
		pixels = new sf::Uint32[width * height];
	}
	return this;
}

void Screen::destroy() {
	if (instance) {
		delete instance;
		instance = NULL;
	}
}
