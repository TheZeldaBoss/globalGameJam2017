#include <SFML/Graphics.hpp>

#ifndef _IENTITY_H
#define _IENTITY_H

class IEntity
{
public:
	virtual ~IEntity() = 0;

	enum MOVE
	{
		UP,
		RIGHT,
		DOWN,
		LEFT,
		UP_RIGHT,
		RIGHT_DOWN,
		DOWN_LEFT,
		LEFT_UP
	};

	// Positions & Movements

	void			move(enum MOVE);
	void			setX(int);
	int				getX() const;
	void			setY(int);
	int				getY() const;
	void			setXY(int, int);
	void			setSpeed(int);
	int				getSpeed() const;

	// Display properties

	void			setTexture(std::string);
	sf::Texture*	getTexture();

	// Bonus




private:
	sf::Sprite			*_sprite;
	sf::Texture			*_texture;
	int					_x;
	int					_y;
	int					_speed;
	std::vector<IEntity>	_bonus;
};


#endif 