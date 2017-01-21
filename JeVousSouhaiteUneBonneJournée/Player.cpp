#include <Thread>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "main.h"

#define	ANIM_SPEED 3

// Constructor

Player::Player(int id)
{
	setId(id);
	setSpeed(6);
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
		setXY(200, 200);
		setImage("src/player/player1.png");
	}
	if (getId() == 1)
	{
		UP = sf::Keyboard::Up;
		LEFT = sf::Keyboard::Left;
		RIGHT = sf::Keyboard::Right;
		DOWN = sf::Keyboard::Down;
		setXY(400, 200);
		setImage("src/player/player2.png");
	}
	if (getId() == 2)
	{
		UP = sf::Keyboard::O;
		LEFT = sf::Keyboard::K;
		RIGHT = sf::Keyboard::M;
		DOWN = sf::Keyboard::L;
		setXY(200, 400);
		setImage("src/player/player3.png");
	}
	if (getId() == 3)
	{
		UP = sf::Keyboard::G;
		LEFT = sf::Keyboard::V;
		RIGHT = sf::Keyboard::N;
		DOWN = sf::Keyboard::B;
		setXY(400, 400);
		setImage("src/player/player4.png");
	}
}

void	Player::setDir(enum MOVE mv)
{
	if (mv == MOVE::DOWN)
		setSubTexture(sf::IntRect(0, 0, 280, 35));
	else if (mv == MOVE::LEFT)
		setSubTexture(sf::IntRect(0, 70, 280, 35));
	else if (mv == MOVE::RIGHT)
		setSubTexture(sf::IntRect(0, 35, 280, 35));
	else if (mv == MOVE::UP)
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

void	Player::mvAnim()
{
	if (MAIN_MV != sf::Keyboard::Key::Unknown)
	{
		if (MAIN_MV == UP)
			setDir(MOVE::UP);
		if (MAIN_MV == RIGHT)
			setDir(MOVE::RIGHT);
		if (MAIN_MV == LEFT)
			setDir(MOVE::LEFT);
		if (MAIN_MV == DOWN)
			setDir(MOVE::DOWN);
		printf("%d\n", speed);
		if (speed == ANIM_SPEED)
			{
				setSprite(sf::IntRect(i * 28, 0, 28, 35));
				i = i + 1;
				speed = 0;
			}
			if (i == 10)
				i = 0;
			speed++;
	}
	if (MAIN_MV == UP && !(sf::Keyboard::isKeyPressed(UP)))
		MAIN_MV = sf::Keyboard::Key::Unknown;
	if (MAIN_MV == DOWN && !(sf::Keyboard::isKeyPressed(DOWN)))
		MAIN_MV = sf::Keyboard::Key::Unknown;
	if (MAIN_MV == LEFT && !(sf::Keyboard::isKeyPressed(LEFT)))
		MAIN_MV = sf::Keyboard::Key::Unknown;
	if (MAIN_MV == RIGHT && !(sf::Keyboard::isKeyPressed(RIGHT)))
		MAIN_MV = sf::Keyboard::Key::Unknown;
}

void	Player::start()
{
	setSprite(sf::IntRect(0, 0, 28, 35));
	getSprite()->setPosition((float)getX(), (float)getY());
	MAIN_MV = sf::Keyboard::Key::Unknown;
	while (42)
	{
		Sleep(1);
	//	if (getId() == 1)
//			printf("P%d : %d/%d\n", getId() + 1, getX(), getY());
		if (getId() == 0 && MAIN_MV == UP)
			printf("UP\n");
		if (getId() == 0 && MAIN_MV == LEFT)
			printf("LEFT\n");
		if (getId() == 0 && MAIN_MV == RIGHT)
			printf("RIGHT\n");
		if (getId() == 0 && MAIN_MV == DOWN)
			printf("DOWN\n");
		if (getId() == 0 && MAIN_MV == sf::Keyboard::Key::Unknown)
			printf("TAMER\n");

		mvAnim();

		if (sf::Keyboard::isKeyPressed(UP))
		{
			if (MAIN_MV == sf::Keyboard::Key::Unknown)
				MAIN_MV = UP;
			move(MOVE::UP);
		}
		if (sf::Keyboard::isKeyPressed(LEFT))
		{
			if (MAIN_MV == sf::Keyboard::Key::Unknown)
				MAIN_MV = LEFT;
			move(MOVE::LEFT);
		}
		if (sf::Keyboard::isKeyPressed(RIGHT))
		{
			if (MAIN_MV == sf::Keyboard::Key::Unknown)
				MAIN_MV = RIGHT;
			move(MOVE::RIGHT);
		}
		if (sf::Keyboard::isKeyPressed(DOWN))
		{
			if (MAIN_MV == sf::Keyboard::Key::Unknown)
				MAIN_MV = DOWN;
			move(MOVE::DOWN);
		}
	}
}