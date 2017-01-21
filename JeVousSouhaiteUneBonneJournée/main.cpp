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
	_players = new std::vector<Player*>;
	_texture->loadFromFile("src/background.png");
	_backGround->setTexture(*_texture, true);
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

int main()
{
	data = new globalData();
	Player	p1(0);
	Player	p2(1);
	Player	p3(2);
	Player	p4(3);

	std::thread t1(&Player::start, &p1);
	std::thread t2(&Player::start, &p2);
	std::thread t3(&Player::start, &p3);
	std::thread t4(&Player::start, &p4);

	std::thread	t_display(drawInWindow);

	data->getWindow()->setActive(false);
	t_display.join();
	return 0;
}