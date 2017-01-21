#ifndef MAIN_H_
#define MAIN_H_
#include "Display.h"
#include <SFML/Graphics.hpp>
#include "generateLaby.h"

class globalData
{
private:
	bool exitProgram;
	bool redraw;
	Labyrinth *laby;
	sf::Texture *_texture;
	sf::Texture *_tileset;
	sf::RenderWindow *_window;
	sf::Sprite *_backGround;
	std::vector < std::vector<sf::Sprite>>spritesVector;
	sf::Sprite *_wall;
	sf::Sprite *_floor;
public:
	globalData();
	bool getExit();
	void setExit(bool);
	bool getRedraw();
	void setRedraw(bool);
	sf::Texture *getTexture();
	void setTexture(sf::Texture*);
	sf::RenderWindow *getWindow();
	void setWindow(sf::RenderWindow*);
	sf::Sprite *getBackGround();
	void setBackGround(sf::Sprite*);
	Labyrinth *getLaby();
	void setLaby(Labyrinth *);
	std::vector<std::vector<sf::Sprite>>getSpritesVector();
};

extern globalData *data;

#endif