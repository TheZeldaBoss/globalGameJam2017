#include "Display.h"
#include <thread>
#include <SFML/Graphics.hpp>
#include "main.h"

globalData *data;

globalData::globalData()
{
	exitProgram = false;
	redraw = true;
	_texture = new sf::Texture();
	_backGround = new sf::Sprite();
	_window = new sf::RenderWindow();
	_tileset = new sf::Texture();
	_wall = new sf::Sprite();
	_floor = new sf::Sprite();
	_players = new std::vector<Player*>;
	_backGround->setTexture(*_texture, true);
	_texture->loadFromFile("src/background.png");
	_tileset->loadFromFile("src/tileset.png");
	_wall->setTexture(*_tileset,true);
	_floor->setTexture(*_tileset, true);
	_wall->setTextureRect(sf::IntRect(16, 0, 16, 16));
	_floor->setTextureRect(sf::IntRect(0, 0, 16, 16));
	_window->create(sf::VideoMode(1280, 720), "GLOBAL");
	_backGround->setScale((float)_window->getSize().x / _texture->getSize().x, (float)_window->getSize().y / _texture->getSize().y);
}

bool						 globalData::getExit()
{
	return this->exitProgram;
}

void						 globalData::setExit(bool b)
{
	this->exitProgram = b;
}

bool						globalData::getRedraw()
{
	return (redraw);
}

void						globalData::setRedraw(bool b)
{
	this->redraw = b;
}

sf::Texture				 *globalData::getTexture()
{
	return this->_texture;
}

void					 globalData::setTexture(sf::Texture *t)
{
	this->_texture = t;
}

sf::RenderWindow		 *globalData::getWindow()
{
	return this->_window;
}

void					globalData::setWindow(sf::RenderWindow *w)
{
	_window = w;
}

sf::Sprite				*globalData::getBackGround()
{
	return _backGround;
}
void					globalData::setBackGround(sf::Sprite *b)
{
	_backGround = b;
}

std::vector<Player*>	*globalData::getPlayers()
{
	return _players;
}

Player					*globalData::getPlayer(int i)
{
	return _players->at(i);
}


Labyrinth *globalData::getLabyrinth()
{
	return (this->laby);
}

void globalData::setLabyrinth(Labyrinth *lab)
{
	this->laby = lab;
	std::vector<std::vector<int>> labData = lab->getData();
	std::vector<sf::Sprite> *actualLine;
	actualLine = new std::vector<sf::Sprite>;
	for (unsigned int i = 0; i < labData.size(); i++)
	{
		for (unsigned int j = 0; j < labData[i].size(); j++)
		{
			if (labData[i][j] == 0)
				actualLine->push_back(*this->_floor);
			else
				actualLine->push_back(*this->_wall);
			(*actualLine)[j].setPosition(sf::Vector2f((float)(16.0 * j), (float)(16.0 * i)));
		}
		this->spritesVector.push_back(*actualLine);
		actualLine->clear();
	}
}

std::vector<std::vector<sf::Sprite>>globalData::getSpritesVector()
{
	return (this->spritesVector);
}

int main()
{
	data = new globalData();
	Labyrinth laby("src/testLabyrinth/mapTest.txt");
	Player	p1(0);
<<<<<<< HEAD
	Player	p2(1);
	Player	p3(2);
	Player	p4(3);

	std::thread t1(&Player::start, &p1);
	std::thread t2(&Player::start, &p2);
	std::thread t3(&Player::start, &p3);
	std::thread t4(&Player::start, &p4);

	std::thread	t_display(drawInWindow);
=======
	data->setLabyrinth(&laby);
	data->setRedraw(true);
	std::thread o(&Player::start, &p1);
	std::thread	t_display(&drawInWindow);
>>>>>>> origin/master

	//p1.start();
	data->getWindow()->setActive(false);

	t_display.join();
	while (data->getExit() == false);
	return 0;
}