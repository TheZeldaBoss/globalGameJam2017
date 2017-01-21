#ifndef MAIN_H_
#define MAIN_H_
#include "Display.h"
#include "Player.h"
#include <vector>
#include <SFML/Graphics.hpp>

class globalData
{
private:
	bool exitProgram;
	bool redraw;
	sf::Texture *_texture;
	sf::RenderWindow *_window;
	sf::Sprite *_backGround;
	std::vector<Player*>	*_players;

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
	std::vector<Player*>	*getPlayers();
	Player					*getPlayer(int);
};

extern globalData *data;

#endif