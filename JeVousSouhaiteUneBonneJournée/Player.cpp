#include <Thread>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "main.h"

// Constructor

Player::Player(int id)
{
	setId(id);
	setSpeed(1);
	setBind();
	setDir(MOVE::DOWN);
	getSprite()->scale(2, 2);
	data->getPlayers()->push_back(this);
}

// Destructor

Player::~Player()
{

}

//	Member functions

void	Player::setBind()
{
	if (getId() == 0)
	{
		UP = sf::Keyboard::Z;
		LEFT = sf::Keyboard::Q;
		RIGHT = sf::Keyboard::D;
		DOWN = sf::Keyboard::S;
		setXY(100, 100);
		setImage("src/player/player1.png");
	}
	if (getId() == 1)
	{
		UP = sf::Keyboard::Up;
		LEFT = sf::Keyboard::Left;
		RIGHT = sf::Keyboard::Right;
		DOWN = sf::Keyboard::Down;
		setXY(200, 100);
		setImage("src/player/player2.png");
	}
	if (getId() == 2)
	{
		UP = sf::Keyboard::O;
		LEFT = sf::Keyboard::K;
		RIGHT = sf::Keyboard::M;
		DOWN = sf::Keyboard::L;
		setXY(100, 200);
		setImage("src/player/player3.png");
	}
	if (getId() == 3)
	{
		UP = sf::Keyboard::G;
		LEFT = sf::Keyboard::V;
		RIGHT = sf::Keyboard::N;
		DOWN = sf::Keyboard::B;
		setXY(200, 200);
		setImage("src/player/player4.png");
	}
}

void	Player::setDir(enum MOVE mv)
{
	if (mv == MOVE::UP)
		setSubTexture(sf::IntRect(0, 0, 280, 35));
	else if (mv == MOVE::LEFT)
		setSubTexture(sf::IntRect(0, 70, 280, 35));
	else if (mv == MOVE::RIGHT)
		setSubTexture(sf::IntRect(0, 35, 280, 35));
	else if (mv == MOVE::DOWN)
		setSubTexture(sf::IntRect(0, 105, 280, 35));
}

void	Player::setId(int id)
{
	_id = id;
}

int		Player::getId() const
{
	return (_id);
}

//

void	Player::start()
{
	setSprite(sf::IntRect(0, 0, 28, 35));
	getSprite()->setPosition((float)getX(), (float)getY());
	while (42)
	{
		if (sf::Keyboard::isKeyPressed(UP))
		{
			printf("x : %d y : %d\n", getX(), getY());
			move(MOVE::UP);
		}
	}
}