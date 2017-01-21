#include "Display.h"
#include <iostream>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "main.h"

void drawInWindow()
{
<<<<<<< HEAD
	while (data->getWindow()->isOpen())
	{
		if (data->getRedraw())
		{
			data->getWindow()->draw(*data->getBackGround());
			data->getWindow()->draw(*data->getPlayer(0)->getSprite());
			data->getWindow()->draw(*data->getPlayer(1)->getSprite());
			data->getWindow()->draw(*data->getPlayer(2)->getSprite());
			data->getWindow()->draw(*data->getPlayer(3)->getSprite());
			data->getWindow()->display();
		}
	}
=======
	if (data->getRedraw() == true)
	{
		data->getWindow()->draw(*data->getBackGround());
		data->getWindow()->display();
		std::vector<std::vector<sf::Sprite>>labyData = data->getSpritesVector();

		for (unsigned int i = 0; i < labyData.size(); i++)
		{
			for (unsigned int j = 0; j < (labyData)[i].size(); j++)
			{
				data->getWindow()->draw((labyData)[i][j]);
			}
		}
		data->getWindow()->draw(*data->getPlayer(0)->getSprite());
		data->getWindow()->display();
	}
	data->setRedraw(false);
>>>>>>> origin/master
}
