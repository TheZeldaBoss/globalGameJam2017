#include "IEntity.h"
#include "main.h"

IEntity::IEntity()
{
	_texture = new sf::Texture;
	_sprite = new sf::Sprite;
}

IEntity::~IEntity()
{

}

//

void			IEntity::setImage(std::string file)
{
	_textureImg.loadFromFile(file);
}

void			IEntity::setSubTexture(sf::IntRect area)
{
	_texture->loadFromImage(_textureImg, area);
}

sf::Texture*	IEntity::getTexture()
{
	return (_texture);
}

void			IEntity::setSprite(sf::IntRect area)
{
	_sprite->setTexture(*getTexture(), true);
	_sprite->setTextureRect(area);
}

sf::Sprite*		IEntity::getSprite() const
{
	return (_sprite);
}


void			IEntity::move(enum MOVE mv)
{
	if (mv == UP)
	{
		setY(getY() + getSpeed());
		getSprite()->setPosition(getX(), getY());
	}
	else if (mv == LEFT)
	{
		setX(getX() - getSpeed());
		getSprite()->setPosition(getX(), getY());
	}
	else if (mv == RIGHT)
	{
		setX(getX() + getSpeed());
		getSprite()->setPosition(getX(), getY());
	}
	else if (mv == DOWN)
	{
		setY(getY() - getSpeed());
		getSprite()->setPosition(getX(), getY());
	}
	data->setRedraw(true);
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