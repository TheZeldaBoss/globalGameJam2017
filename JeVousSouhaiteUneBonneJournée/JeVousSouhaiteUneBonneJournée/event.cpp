#include "main.h"
#include <SFML/Graphics.hpp>
#include "Display.h"

void event(Display &play)
{
	sf::CircleShape circle;
	sf::Event event;

	circle.setRadius(150);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(5);
	circle.setPosition(10, 20);
	play.getWindow()->pollEvent(event);
	if (event.type == sf::Event::Closed)
		data.setExit(true);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))

}