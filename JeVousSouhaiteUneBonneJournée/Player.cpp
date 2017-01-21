#include "Player.h"
#include <Thread>
#include <Windows.h>
#include <SFML/Graphics.hpp>

// Constructor

Player::Player(int id)
{

	setId(id);
	setSpeed(1);
	setBind();
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
		setTexture("src/player/player1.png");
	}
	if (getId() == 1)
	{
		UP = sf::Keyboard::Up;
		LEFT = sf::Keyboard::Left;
		RIGHT = sf::Keyboard::Right;
		DOWN = sf::Keyboard::Down;
		setXY(200, 100);
		setTexture("src/player/player2.png");
	}
	if (getId() == 2)
	{
		UP = sf::Keyboard::O;
		LEFT = sf::Keyboard::K;
		RIGHT = sf::Keyboard::M;
		DOWN = sf::Keyboard::L;
		setXY(100, 200);
		setTexture("src/player/player3.png");
	}
	if (getId() == 3)
	{
		UP = sf::Keyboard::G;
		LEFT = sf::Keyboard::V;
		RIGHT = sf::Keyboard::N;
		DOWN = sf::Keyboard::B;
		setXY(200, 200);
		setTexture("src/player/player4.png");
	}
	//setSprite();
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
		
}