#include "Display.h"
#include <iostream>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "main.h"

void drawInWindow()
{
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
}
