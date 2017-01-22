#include <thread>
#include <SFML/Graphics.hpp>
#include "IEntity.h"

#ifndef _PLAYER_H
#define _PLAYER_H

class Player : public IEntity
{
public:
	Player(int);
	~Player();

	void	start();

	// Thread handling

	void		handling();

	void	setId(int);
	int		getId() const;
	void	setDir(enum MOVE);

	// Movements

	void	setBind();
	void	mvAnim();

private:
	int					i;
	int					speed;
	int					_id;

	sf::Keyboard::Key	UP;
	sf::Keyboard::Key	LEFT;
	sf::Keyboard::Key	RIGHT;
	sf::Keyboard::Key	DOWN;
	sf::Keyboard::Key	MAIN_MV;
};

#endif