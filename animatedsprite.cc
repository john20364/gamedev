#include <iostream>
#include "include/animatedsprite.h"

AnimatedSprite::AnimatedSprite(
	SpriteSheet* sheet, Orientation orientation, int length) :
	Sprite(sheet), orientation(orientation), length(length) {

	sprites = new Sprite*[this->length];
	// Initialize to NULL
	memset((void *)(sprites), 0, sizeof(sprites) * this->length);	

	if (orientation == AnimatedSprite::Orientation::VERTICAL) {
		width = sheet->WIDTH;
		height = sheet->HEIGHT / length;
	} else {
		width = sheet->WIDTH / length;
		height = sheet->HEIGHT;
	}

	for (int n = 0; n < length; ++n) {
		sprites[n] = new Sprite(width, height, 0xFF000000);
		for (int j = 0; j < height; ++j) {
			for (int i = 0; i < width; ++i) {
				if (orientation == AnimatedSprite::Orientation::VERTICAL) {
					sprites[n]->pixels[i + j * width] = 
						sheet->pixels[i + j * width + n * width * height];
				} else {
					sprites[n]->pixels[i + j * width] = 
						sheet->pixels[n * width + i + j * width * length];
				}
			}
		}
	}

	animRate = 0;
	frame = 0;
	rate = 10;

	pixels = sprites[frame]->pixels;
}

AnimatedSprite::~AnimatedSprite() {
	pixels = NULL;
	for (int i = 0; i < length; ++i) {
		delete sprites[i];
	}
	delete[] sprites;
}

void AnimatedSprite::update() {
	if (animRate == 0) {
		++frame %= length;
		pixels = sprites[frame]->pixels;
	}
	++animRate %= rate;
}

void AnimatedSprite::startFrame() {
	frame = 0;
	pixels = sprites[frame]->pixels;
}

void AnimatedSprite::setRate(int rate) {
	this->rate = rate;
}

int AnimatedSprite::getRate() {
	return rate;
}

