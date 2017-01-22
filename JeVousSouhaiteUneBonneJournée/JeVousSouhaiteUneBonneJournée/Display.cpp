#include <SFML/Graphics.hpp>
#include "Display.h"
#include "main.h"
Display::Display(int x, int y, std::string title)
{
	_window = new sf::RenderWindow(sf::VideoMode(x, y), title);
	_window->setFramerateLimit(60);
}

Display::~Display()
{
	_window->close();
}

//affiche un cercle
void Display::DrawCircle(sf::CircleShape circle)
{

}

sf::RenderWindow *Display::getWindow()
{
	return (this->_window);
}

void	actuWindow(Display &play)
{
	sf::CircleShape circle;
	circle.setRadius(150);
	circle.setOutlineColor(sf::Color::Red);
	circle.setOutlineThickness(5);
	circle.setPosition(10, 20);

	// The main loop - ends as soon as the __window is closed
	while (play._window->isOpen())
	{
		// Event processing
		sf::Event event;
		while (play._window->pollEvent(event))
		{
			// Request for closing the _window
			if (event.type == sf::Event::Closed)
				data.setExit(true);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				_window->draw(circle);
			_window->display();

		}
		// Clear the whole _window before rendering a new frame
		_window->clear();
		// Draw some graphical entities

		// End the current frame and display its contents on screen
		
	}
}