#ifndef _SFML_UTIL_H_
#define _SFML_UTIL_H_

#include <SFML/Graphics.hpp>

namespace su {
	void centerWindow(sf::Window& window) {
		sf::Vector2u size = window.getSize();
		size.x = (sf::VideoMode::getDesktopMode().width - size.x) >> 1;
		size.y = (sf::VideoMode::getDesktopMode().height - size.y) >> 1;
		window.setPosition(sf::Vector2i(size.x, size.y));
	}
}
#endif
