#include "Display.h"
#include <iostream>
#include <Windows.h>
#include <SFML/Graphics.hpp>
#include "main.h"

void drawInWindow()
{
	data->getWindow()->draw(*data->getBackGround());
	data->getWindow()->display();
}
