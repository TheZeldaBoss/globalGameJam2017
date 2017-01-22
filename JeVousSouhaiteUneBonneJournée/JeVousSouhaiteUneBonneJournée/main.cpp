// JeVousSouhaiteUneBonneJournée.cpp : définit le point d'entrée pour l'application console.
//

#include "Display.h"
#include <SFML/Graphics.hpp>
#include "main.h"
#include "event.h"

globalData::globalData()
{
	this->exitProgram = false;
	this->actualiseWindow = false;
	this->play = new Display(1280, 720, "GLOBAL");
}

bool globalData::getExit()
{
	return (this->exitProgram);
}

void globalData::setExit(bool exit)
{
	this->exitProgram = exit;
}

int main()
{
	Display play(1280, 720, "GLOBAL");
	sf::Thread displayThread(&actuWindow);

	while (data.getExit() == false)
	{
		event();
	}
	return 0;
}