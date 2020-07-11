#ifndef _ANIMATED_SPRITE_H_
#define _ANIMATED_SPRITE_H_
#include "sprite.h"

class AnimatedSprite : public Sprite {
public:
	enum Orientation {VERTICAL, HORIZONTAL};
	const Orientation orientation;
	AnimatedSprite(SpriteSheet* sheet, Orientation orientation, int length);
	~AnimatedSprite();
	void update();
	int getRate();
	void setRate(int rate);
	void startFrame();
private:
	int frame;
	Sprite** sprites;
	int rate;
	int length;
	int animRate;
};
#endif
