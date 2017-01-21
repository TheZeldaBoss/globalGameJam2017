#include "Display.h"
#include <thread>
#include <SFML/Graphics.hpp>
#include "main.h"

globalData *data;

globalData::globalData()
{
	exitProgram = false;
	redraw = false;
	_texture = new sf::Texture();
	_backGround = new sf::Sprite();
	_window = new sf::RenderWindow();
	_texture->loadFromFile("src/background.png");
	_backGround->setTexture(*_texture, true);
	_window->create(sf::VideoMode(1280, 720), "GLOBAL");
}

bool globalData::getExit()
{
	return this->exitProgram;
}

void globalData::setExit(bool b)
{
	this->exitProgram = b;
}

bool globalData::getRedraw()
{
	return (redraw);
}

void globalData::setRedraw(bool b)
{
	this->redraw = b;
}

sf::Texture *globalData::getTexture()
{
	return this->_texture;
}

void globalData::setTexture(sf::Texture *t)
{
	this->_texture = t;
}

sf::RenderWindow *globalData::getWindow()
{
	return this->_window;
}

void globalData::setWindow(sf::RenderWindow *w)
{
	_window = w;
}

sf::Sprite *globalData::getBackGround()
{
	return _backGround;
}
void globalData::setBackGround(sf::Sprite *b)
{
	_backGround = b;
}

int main()
{
	data = new globalData();
	sf::Thread displayThread((&drawInWindow));
	data->getWindow()->setActive(false);
	displayThread.launch();
	while (data->getWindow()->isOpen());
	return 0;
}