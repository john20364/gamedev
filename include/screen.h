#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SFML/Graphics.hpp>
#include "tile.h"
#include "sprite.h"
#include "projectile.h"
#include "spritesheet.h"

class Screen {
public:
	sf::Uint32* pixels;
	int xOffset;
	int yOffset;
	static Screen* getInstance();
	~Screen();
	Screen* init(int width, int height);
	void destroy();
	int getWidth();
	int getHeight();
	void clear(sf::Uint32 color = 0xFF000000);
	void renderPlayer(int xp, int yp, Sprite& player, int flip);
	void renderProjectile(int xp, int yp, Projectile& p);
	void renderSprite(int xp, int yp, Sprite& sprite, bool fixed);
	void renderSpriteSheet(int xp, int yp, SpriteSheet& sheet, bool fixed);
	void renderTile(int xp, int yp, Tile& tile);
	void setOffset(int xOffset, int yOffset);
private:
	static Screen* instance;
	int width;
	int height;
	Screen();
};
#endif
