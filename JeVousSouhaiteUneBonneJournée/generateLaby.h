#ifndef GENERATELABY_H_
#define GENERATELABY_H_

#include <string>
#include <vector>

class Labyrinth
{
private:
	int outX;
	int outY;
	std::vector<std::vector<int>>labyrinthData;
public:
	Labyrinth(std::string fileName);
	int getOutX();
	int getOutY();
	std::vector<std::vector<int>>getData();
	
};

#endif