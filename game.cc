#include <iostream>
#include <sstream>
#include "include/game.h"
#include "include/sfmlutil.h"
#include "include/sprites.h"
#include "include/randomlevel.h"
#include "include/levels.h"
#include "include/mouse.h"
#include "include/tilecoord.h"
#include "include/levelplayers.h"
#include "include/spawnfactory.h"
#include "include/animatedsprite.h"

Game::Game() : 	width(300),
				height((width * 9) / 16),
				scale(3),
				screen(*Screen::getInstance()->init(width, height)) {
	
	paused = false;
//	level = new RandomLevel(64, 64);
	level = Levels::getInstance()->spawn;
	TileCoord coord(6, 6);
	player = new Player(coord.getX(), coord.getY(), &keyboard);	
	player->init(level);
	LevelPlayers::getInstance()->setFrontPlayer(player);
};

Game::~Game() {
	delete level;
}

int Game::run() {
	if (!init()) {
		return -1;
	}

	sf::Clock clock;
	float delta2 = 0;
	float delta = 0;
	float period = 1.0 / 60.0;
	int ups = 0;
	int frames = 0;

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			this->event(event);
		}

		if (!paused) {
			sf::Time elapsed = clock.restart();
			delta += elapsed.asSeconds();
			delta2 += elapsed.asSeconds();

			while (delta >= period) {
				delta -= period;
				update();
				ups++;
//			sf::sleep(sf::milliseconds(5));
			}

			render();
			frames++;

			if (delta2 >= 1.0) {
				delta2--;
				std::stringstream ss;
				ss << "ups: " << ups << " frames: " << frames;
				window.setTitle(ss.str());
				ups = 0;
				frames = 0;
			}
		}
	}

	terminate();
	return 0;
}

bool Game::init() {
	window.create(sf::VideoMode(scale * width, scale * height), 
		"SFML", sf::Style::Titlebar | sf::Style::Close);

	Mouse::getInstance()->setWindow(&window);
//	window.setMouseCursorVisible(false);
	su::centerWindow(window);

	if (!texture.create(width, height)) {
		return false;
	}

	sprite.setTexture(texture);
	sprite.scale((float)scale, (float)scale);
	return true;
};

void Game::event(sf::Event &event) {
	keyboard.event(event);
	switch (event.type) {
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::LostFocus:
			paused = true;
			break;
		case sf::Event::GainedFocus:
			paused = false;
			break;
		default:
			break;
	}
}

void Game::terminate() {
}

void Game::update() {
	keyboard.update();
	level->update();
}

void Game::render() {
	screen.clear();
	int xScroll = player->x - (screen.getWidth() >> 1);
	int yScroll = player->y - (screen.getHeight() >> 1);
	level->render(xScroll, yScroll);
	texture.update((sf::Uint8*)screen.pixels);
	window.draw(sprite);
	window.display();

//	sf::RectangleShape shape(sf::Vector2f(48.f, 48.f));
//	shape.setPosition(mouse->position().x-24, mouse->position().y-24);
//	window.draw(shape);

//	Mouse* mouse = Mouse::getInstance();
//	sf::Text text;
//	sf::Font font;
//	if (!font.loadFromFile("res/font/arial.ttf")) {
//		std::cout << "Cannot find font-file\n";
//	}
//	text.setFont(font);
//	std::stringstream ss;
//	ss << mouse->leftButton() << mouse->middleButton() << mouse->rightButton() <<
//	" " << mouse->position().x << " , " << mouse->position().y; 
//	text.setString(ss.str());
//	text.setCharacterSize(24);
//	text.setFillColor(sf::Color::Red);
//	text.setPosition(10, 100);
//	window.draw(text);
//	window.display();
}

