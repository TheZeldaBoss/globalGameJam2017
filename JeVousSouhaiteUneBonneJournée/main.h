#ifndef MAIN_H_
#define MAIN_H_
#include "Display.h"
#include "Player.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
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
	sf::Sprite *_wall;
	sf::Sprite *_floor;
	std::vector<Player*>	*_players;
	std::vector<std::vector<sf::Sprite>> spritesVector;
	std::vector<sf::Music*>		_music;

public:
	globalData();
	~globalData();
	sf::Music	*getMusicStream(int);
	bool getExit();
	void setExit(bool);
	bool getRedraw();
	void setRedraw(bool);
	sf::Texture *getTexture();
	void setTexture(sf::Texture*);
	sf::Texture *getTileset();
	void setTileset(sf::Texture *);
	sf::RenderWindow *getWindow();
	void setWindow(sf::RenderWindow*);
	sf::Sprite *getBackGround();
	void setBackGround(sf::Sprite*);
	sf::Sprite *getFloor();
	void setFloor(sf::Sprite *);
	sf::Sprite *getWall();
	void setWall(sf::Sprite *);
	std::vector<Player*>	*getPlayers();
	Player					*getPlayer(int);
	Labyrinth *getLabyrinth();
	void setLabyrinth(Labyrinth *);
	std::vector < std::vector < sf::Sprite >> getSpritesVector();
};

extern globalData *data;

#endif