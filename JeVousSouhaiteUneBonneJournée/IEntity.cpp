#include "IEntity.h"

IEntity::~IEntity()
{

}

//

void			IEntity::setTexture(std::string file)
{
	sf::Image image;

	image.loadFromFile(file);
	getTexture()->loadFromImage(image);
}

sf::Texture*	IEntity::getTexture()
{
	return (_texture);
}

void			IEntity::move(enum MOVE)
{

}

void			IEntity::setX(int x)
{
	_x = x;
}

int				IEntity::getX() const
{
	return (_x);
}

void			IEntity::setY(int y)
{
	_y = y;
}

int				IEntity::getY() const
{
	return (_y);
}

void			IEntity::setXY(int x, int y)
{
	setX(x);
	setY(y);
}

void			IEntity::setSpeed(int speed)
{
	_speed = speed;
}

int				IEntity::getSpeed() const
{
	return (_speed);
}