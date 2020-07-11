#ifndef _MOUSE_H_
#define _MOUSE_H_
#include <SFML/Graphics.hpp>

class Mouse {
public:
	static Mouse* getInstance();
	~Mouse();
	void destroy();
	void setWindow(sf::Window* window);	
	void position(sf::Vector2i pos);
	void position(int x, int y);
	sf::Vector2i position();
	sf::Vector2i center();
	bool leftButton();
	bool middleButton();
	bool rightButton();
	sf::Vector2u clientSize;
private:
	static Mouse* instance;
	bool insideWindow();
	Mouse();
	sf::Window* window;
};
#endif
