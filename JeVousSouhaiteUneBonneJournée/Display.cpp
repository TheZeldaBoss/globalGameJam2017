#include "Display.h"
#include <iostream>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "main.h"

void drawInWindow()
{
	if (data->getRedraw() == true)
	{
		data->getWindow()->draw(*data->getBackGround());
		std::vector<std::vector<sf::Sprite>>labyData = data->getSpritesVector();

		for (unsigned int i = 0; i < labyData.size(); i++)
		{
			for (unsigned int j = 0; j < labyData[i].size(); j++)
			{
				data->getWindow()->draw(labyData[i][j]);
			}
		}
		data->getWindow()->display();
	}
}
