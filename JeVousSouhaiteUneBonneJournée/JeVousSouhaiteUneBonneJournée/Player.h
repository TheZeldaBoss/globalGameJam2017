#ifndef _PLAYER_H
#define _PLAYER_H

class Player
{
public:
	Player();
	~Player();

	int getX() const;
	int getY() const;


private:
	int	_x;
	int	_y;
};

#endif 