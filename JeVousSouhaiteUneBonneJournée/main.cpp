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
	_tileset = new sf::Texture();
	_floor = new sf::Sprite();
	_wall = new sf::Sprite();
	_texture->loadFromFile("src/background.png");
	_tileset->loadFromFile("src/tileset.png");
	_backGround->setTexture(*_texture, true);
	_floor->setTexture(*_tileset, true);
	_wall->setTexture(*_tileset, true);
	_floor->setTextureRect(sf::IntRect(0, 0, 16, 16));
	_wall->setTextureRect(sf::IntRect(16, 0, 16, 16));
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

Labyrinth *globalData::getLaby()
{
	return (this->laby);
}

void globalData::setLaby(Labyrinth *lab)
{
	this->laby = lab;
	std::vector < std::vector<int> >labData = lab->getData();
	std::vector<sf::Sprite> *actualLine = new std::vector<sf::Sprite>;
	for (unsigned int i = 0; i < labData.size(); i++)
	{
		for (unsigned int j = 0; j < labData[i].size(); j++)
		{
			if (labData[i][j] == 0)
				actualLine->push_back(*this->_floor);
			else
				actualLine->push_back(*this->_wall);
			std::vector<sf::Sprite> actualLineTmp = *actualLine;
			(*actualLine)[j].setPosition((float)(16.0 * j), (float)(16.0 * i));
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
	//temporaire
	Labyrinth laby("src/testLabyrinth/mapTest.txt");
		data->setLaby(&laby);
		//fin temporaire
	sf::Thread displayThread((&drawInWindow));
	data->getWindow()->setActive(false);
	displayThread.launch();
	while (data->getWindow()->isOpen());
	return 0;
}