#include <SFML/Graphics.hpp>

#ifndef _IENTITY_H
#define _IENTITY_H

class IEntity
{
public:
	IEntity();
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

	void			setImage(std::string);
	void			setSubTexture(sf::IntRect);
	sf::Texture*	getTexture();
	void			setSprite(sf::IntRect);
	sf::Sprite		*getSprite() const;

	//check modified scale
	bool getEntitySet();
	void setEntitySet(bool);
	// Bonus

private:
	sf::Image			_textureImg;
	sf::Texture			*_texture;
	sf::Sprite			*_sprite;
	int					_x;
	int					_y;
	int					_speed;
	bool				_entitySet;
	std::vector<IEntity>	_bonus;
};


#endif 