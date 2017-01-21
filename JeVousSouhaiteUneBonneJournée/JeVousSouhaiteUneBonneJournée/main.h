#ifndef MAIN_H_
#define MAIN_H_

#include "Display.h"

class globalData
{
private:
	bool exitProgram;
	bool actualiseWindow;
	Display *play;
public:
	globalData();
	bool getExit();
	void setExit(bool);
};

//variable globale contenant toutes les donnees
globalData data;

#endif