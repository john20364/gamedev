#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include "keyboard.h"
#include "screen.h"
#include "level.h"
#include "player.h"

class Game {
public:
	const int width;
	const int height;
	const int scale;
	Game();
	~Game();
	int run();
private:
	Level* level;
	Player* player;
	Screen &screen;
	sf::RenderWindow window;
	sf::Texture texture;
	sf::Sprite sprite;
	Keyboard keyboard;
	bool paused;
	bool init();
	void event(sf::Event &event);
	void terminate();
//	void update(sf::Time elapsed);
	void update();
	void render();
};
#endif
