#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <iostream>
#include <SFML/Graphics.hpp>

class Display
{
public:
	Display(int, int, std::string);
	~Display();
	void DrawCircle(sf::CircleShape);
	void	start_loop();
	sf::RenderWindow *getWindow();
private:
	sf::RenderWindow	*_window;
};

void actuWindow(Display &);

#endif